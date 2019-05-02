/* These unit tests test the salvager case from cardEffect() from dominion.c */

#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/*case salvager:
		//+1 buy
		state->numBuys++;

		if (choice1)
		{
			//gain coins equal to trashed card
			state->coins = state->coins + getCost(handCard(choice1, state));
			//trash card
			discardCard(choice1, currentPlayer, state, 1);
		}

		//discard card
		discardCard(handPos, currentPlayer, state, 0);
		return 0;*/

void assertTrue(int expression, char message[]) {
	if (!expression) {
		printf(message);
	}
}

void testSalvager() {
	struct gameState state, testState;
	int handPos = 0;
	int i;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
			 sea_hag, tribute, smithy };

	initializeGame(2, k, 2, &state);

	// TEST 1: player's buys increases by 1
	printf("\n >>> TESTING - cardEffect() for salvager <<<\n");
	printf(" salvager increases buy count by 1\n");
	memcpy(&testState, &state, sizeof(struct gameState));
	int currentPlayer = testState.whoseTurn;
	int buyCount = testState.numBuys;
	int expectedBuyCount = buyCount + 1;

	cardEffect(salvager, 0, 0, 0, &testState, 0, 0);
	int actualBuyCount = testState.numBuys;

	printf("Expected number of buys: %d \tActual number of buys: %d\n",
		expectedBuyCount,
		actualBuyCount
	);
	assertTrue(expectedBuyCount == actualBuyCount, "TEST FAILED: buy count incorrect.\n");


}

int main() {
	testSalvager();
	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	return 0;
}

