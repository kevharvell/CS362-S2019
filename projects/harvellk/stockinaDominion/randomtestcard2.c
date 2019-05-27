/* These unit tests test the playVillage(gameState*, int) function from dominion.c */

#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/*int playVillage(struct gameState *state, int handPos) {
	int currentPlayer = whoseTurn(state);
	//+1 Card
	drawCard(currentPlayer, state);
	//+2 Actions
	state->numActions = state->numActions + 3;
	//discard played card from hand
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

void checkPlayVillage(int handPos, 
					  struct gameState *post, 
					  int *handCountFails, 
					  int *deckCountFails, 
					  int *discardCountFails, 
					  int *actionCountFails) 
{
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));

	int p = pre.whoseTurn;
	cardEffect(village, 0, 0, 0, post, handPos, 0);

	if (!assertTrue(post->handCount[p] == pre.handCount[p], 
					">>> TEST FAILED: Incorrect # of cards drawn\n")) 
		(*handCountFails)++;
	if (!assertTrue(post->deckCount[p] == pre.deckCount[p] - 1, 
					">>> TEST FAILED: Incorrect # of cards removed from deck\n")) 
		(*deckCountFails)++;
	if (!assertTrue(post->playedCardCount == pre.playedCardCount + 1, 
					">>> TEST FAILED: Village not discarded after use\n")) 
		(*discardCountFails)++;
	if (!assertTrue(post->numActions == pre.numActions + 2, 
					">>> TEST FAILED: Incorrect # of actions added\n")) 
		(*actionCountFails)++;
}

int main() {
	srand(time(0));
	int n, handPos;
	int handCountFails = 0;
	int deckCountFails = 0;
	int discardCountFails = 0;
	int actionCountFails = 0;
	int k[10] = { adventurer, council_room, feast, gardens, mine,
				  remodel, smithy, village, baron, great_hall };
	int numPlayers = 2;

	struct gameState G;

	printf("Testing playVillage\n");
	printf("RANDOM TESTS\n");

	for (n = 0; n < 2000; n++) {
		initializeGame(numPlayers, k, 12, &G);
		G.whoseTurn = rand() % 2;
		int p = G.whoseTurn;
		G.deckCount[p] = rand() % MAX_DECK;
		G.discardCount[p] = rand() % MAX_DECK;
		G.handCount[p] = rand() % MAX_HAND + 1;
		handPos = rand() % G.handCount[p];
		checkPlayVillage(handPos, &G, &handCountFails, &deckCountFails, &discardCountFails, &actionCountFails);
	}

	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	printf("# of Hand Count Fails: %d\n", handCountFails);
	printf("# of Deck Count Fails: %d\n", deckCountFails);
	printf("# of Village Discard Fails: %d\n", discardCountFails);
	printf("# of Action Count Fails: %d\n", actionCountFails);
	return 0;
}