/* These unit tests test the playAdventurer(gameState*) function from dominion.c */

#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/*int playAdventurer(struct gameState *state) {
	int drawntreasure = 0;
	int cardDrawn;
	int temphand[MAX_HAND];
	int currentPlayer = whoseTurn(state);
	int z = 0;// this is the counter for the temp hand
	while (drawntreasure < 2) {
		if (state->deckCount[currentPlayer] < 1) {//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else {
			temphand[z] = cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while (z - 1 >= 0) {
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
		z = z + 1;
	}
	return 0;
}*/

int assertTrue(int expression, char message[]) {
	if (!expression) {
		printf(message);
		return 0;
	}
	else return 1;
}

void checkPlayAdventurer(struct gameState *post, int *handCountFails,  int *treasureCountFails) 
{
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));

	int p = pre.whoseTurn;
	int handCount = testState.handCount[p];
	int actualTreasureCount = 0;
	int expectedTreasureCount;

	for (i = 0; i < handCount; i++) {
		if (pre.hand[p][i] == copper ||
			pre.hand[p][i] == silver ||
			pre.hand[p][i] == gold)
		{
			actualTreasureCount++;
		}
	}

	expectedTreasureCount = actualTreasureCount + 2;

	playAdventurer(post);
	actualTreasureCount = 0;

	for (i = 0; i < handCount; i++) {
		if (post.hand[currentPlayer][i] == copper ||
			post.hand[currentPlayer][i] == silver ||
			post.hand[currentPlayer][i] == gold)
		{
			actualTreasureCount++;
		}
	}

	if (!assertTrue(post->handCount[p] == pre.handCount[p] + 1, ">>> TEST FAILED: Incorrect # of cards drawn\n")) (*handCountFails)++;
	if (!assertTrue(expectedTreasureCount == actualTreasureCount, ">>> TEST FAILED: treasure count incorrect after playing adventurer.\n")) (*treasureCountFails)++;
}

int main() {
	srand(time(0));
	int n, handPos;
	int handCountFails = 0;
	int treasureCountFails = 0;
	int k[10] = { adventurer, council_room, feast, gardens, mine,
				  remodel, smithy, village, baron, great_hall };
	int numPlayers = 2;

	struct gameState G;

	printf("Testing playAdventurer\n");
	printf("RANDOM TESTS\n");

	for (n = 0; n < 2000; n++) {
		initializeGame(numPlayers, k, 12, &G);
		G.whoseTurn = rand() % 2;
		int p = G.whoseTurn;
		G.deckCount[p] = rand() % MAX_DECK;
		G.discardCount[p] = rand() % MAX_DECK;
		G.handCount[p] = rand() % MAX_HAND + 1;
		handPos = rand() % G.handCount[p];
		checkPlayAdventurer(&G, &handCountFails, &treasureCountFails);
	}

	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	printf("# of Hand Count Fails: %d\n", handCountFails);
	printf("# of Treasure Count Fails: %d\n", treasureCountFails);
	return 0;
}