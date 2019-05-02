/* These unit tests test the great_hall case from cardEffect() from dominion.c */

#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/*case great_hall:
		//+1 Card
		drawCard(currentPlayer, state);

		//+1 Actions
		state->numActions++;

		//discard card from hand
		discardCard(handPos, currentPlayer, state, 0);
		return 0;*/

void assertTrue(int expression, char message[]) {
	if (!expression) {
		printf(message);
	}
}

void testGreatHall() {
	struct gameState state, testState;
	int handPos = 0;
	int i;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
			 sea_hag, tribute, smithy };

	initializeGame(2, k, 2, &state);

	// TEST 1: player's hand increases by 1, then goes down 1 after discarding great hall
	printf("\n >>> TESTING - playAdventurer(gameState*) <<<\n");
	printf(" playAdventurer increases hand count by 1 and discards the card\n");
	memcpy(&testState, &state, sizeof(struct gameState));
	int currentPlayer = testState.whoseTurn;
	int handCount = testState.handCount[currentPlayer];
	int expectedHandCount = handCount;

	cardEffect(great_hall, 0, 0, 0, &testState, 0, 0)
	int actualHandCount = testState.handCount[currentPlayer];

	printf("Expected number of cards in hand: %d \tActual number of cards in hand: %d\n",
		expectedHandCount,
		actualHandCount
	);
	assertTrue(expectedHandCount == actualHandCount, "TEST FAILED: hand count incorrect after drawing/discarding.\n");

}

int main() {
	testGreatHall();
	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	return 0;
}

