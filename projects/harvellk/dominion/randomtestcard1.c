/* These random tests test the playSmithy(gameState*, int) function from dominion.c */

#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <time.h>

/*int playSmithy(struct gameState *state, int handPos) {
	int i;
	int currentPlayer = whoseTurn(state);
	//+3 Cards
	for (i = 0; i < 5; i++)
	{
		drawCard(currentPlayer, state);
	}
	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}*/

int assertTrue(int expression, char message[]) {
	if (!expression) {
		printf(message);
		return 0;
	}
	else return 1;
}

void checkPlaySmithy(int handPos, struct gameState *post, int *handCountFails, int *deckCountFails, int *discardCountFails) {
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));

	int p = pre.whoseTurn;
	playSmithy(post, handPos);

	if (!assertTrue(post->handCount[p] == pre.handCount[p] + 2, ">>> TEST FAILED: Incorrect # of cards drawn\n")) (*handCountFails)++;
	if (!assertTrue(post->deckCount[p] == pre.deckCount[p] - 3, ">>> TEST FAILED: Incorrect # of cards removed from deck\n")) (*deckCountFails)++;
	if (!assertTrue(post->discardCount[p] == pre.discardCount[p] + 1, ">>> TEST FAILED: Smithy not discarded after use\n")) (*discardCountFails)++;

	

}

int main() {
	srand(time(0));
	int n, handPos;
	int handCountFails = 0;
	int deckCountFails = 0;
	int discardCountFails = 0;
	int k[10] = { adventurer, council_room, feast, gardens, mine,
				  remodel, smithy, village, baron, great_hall };
	int numPlayers = 2;

	struct gameState G;

	printf("Testing playSmithy\n");
	printf("RANDOM TESTS\n");

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 2000; n++) {
		initializeGame(numPlayers, k, 12, &G);
		G.whoseTurn = rand() % 2;
		int p = G.whoseTurn;
		G.deckCount[p] = rand() % MAX_DECK;
		G.discardCount[p] = rand() % MAX_DECK;
		G.handCount[p] = rand() % MAX_HAND + 1;
		handPos = rand() % G.handCount[p];
		checkPlaySmithy(handPos, &G, &handCountFails, &deckCountFails, &discardCountFails);
	}

	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	printf("# of Hand Count Fails: %d\n", handCountFails);
	printf("# of Deck Count Fails: %d\n", deckCountFails);
	printf("# of Smithy Discard Fails: %d\n", discardCountFails);
	return 0;
}