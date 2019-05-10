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

void checkPlaySmithy(int handPos, struct gameState *post) {
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));

	int handCountFails = 0;
	int deckCountFails = 0; 
	int discardCountFails = 0;
	int p = pre.whoseTurn;
	playSmithy(post, handPos);

	if (!assertTrue(post->handCount[p] == pre.handCount[p] + 2, ">>> TEST FAILED: Incorrect # of cards drawn\n")) handCountFails++;
	if (!assertTrue(post->deckCount[p] == pre.deckCount[p] - 3, ">>> TEST FAILED: Incorrect # of cards removed from deck\n")) deckCountFails++;
	if (!assertTrue(post->discardCount[p] == pre.discardCount[p] + 1, ">>> TEST FAILED: Smithy not discarded after use\n")) discardCountFails++;

	printf("# of Hand Count Fails: %d\n", handCountFails);
	printf("# of Deck Count Fails: %d\n", deckCountFails);
	printf("# of Smithy Discard Fails: %d\n", discardCountFails);

}

int main() {
	srand(time(0));
	int i, n, handPos;

	int k[10] = { adventurer, council_room, feast, gardens, mine,
				  remodel, smithy, village, baron, great_hall };

	struct gameState G;

	printf("Testing playSmithy\n");
	printf("RANDOM TESTS\n");

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 10; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = rand() % 257;
		}
		G.whoseTurn = rand() % (MAX_PLAYERS + 1);
		int p = G.whoseTurn;
		G.deckCount[p] = rand() % (MAX_DECK + 1);
		G.discardCount[p] = rand() % (MAX_DECK + 1);
		G.handCount[p] = rand() % (MAX_HAND + 1);
		handPos = rand() % (G.handCount[p] + 1);
		checkPlaySmithy(handPos, &G);
	}

	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	return 0;
}