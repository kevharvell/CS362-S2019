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

void assertTrue(int expression, char message[]) {
	if (!expression) {
		printf(message);
	}
}

void testPlayAdventurer() {
	struct gameState state, testState;
	int handPos = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
			 sea_hag, tribute, smithy };

	initializeGame(2, k, 2, &state);

	// TEST 1: player's hand increases by 2, then goes down 1 after discarding
	printf("\n >>> TESTING - playAdventurer(gameState*) <<<\n");
	printf(" playAdventurer increases hand count by 2 and discards the card\n");
	memcpy(&testState, &state, sizeof(struct gameState));
	int currentPlayer = testState.whoseTurn;
	//int deckCount = state->deckCount[currentPlayer];
	int handCount = testState.handCount[currentPlayer];
	int expectedHandCount = handCount + 1;

	playAdventurer(testState, handPos);
	int actualHandCount = testState.handCount[currentPlayer];

	printf("Expected number of cards in hand: %d \tActual number of cards in hand: %d\n",
		expectedHandCount,
		actualHandCount
	);
	assertTrue(expectedHandCount == actualHandCount, "TEST FAILED: hand count incorrect after drawing/discarding.\n");

}

int main() {
	testPlayAdventurer();
	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	return 0;
}

