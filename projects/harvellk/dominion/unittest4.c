/* These unit tests test the playCouncilRoom(gameState*, int) function from dominion.c */

#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/*int playCouncilRoom(struct gameState *state, int handPos) {
	int i;
	int currentPlayer = whoseTurn(state);

	//+4 Cards
	for (i = 0; i < 4; i++)
	{
		drawCard(currentPlayer, state);
	}

	//+1 Buy
	state->numBuys++;

	//Each other player draws a card
	for (i = 0; i < state->numPlayers; i++)
	{
		if (i != currentPlayer)
		{
			drawCard(i, state);
		}
	}

	//put played card in played card pile
	discardCard(handPos, currentPlayer, state, 0);

	return 0;
}*/

void assertTrue(int expression, char message[]) {
	if (!expression) {
		printf(message);
	}
}

void testPlayCouncilRoom() {
	struct gameState state, testState;
	int handPos = 0;
	int i;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
			 sea_hag, tribute, smithy };

	initializeGame(2, k, 2, &state);

	// TEST 1: player's hand increases by 4, then goes down 1 after discarding
	printf("\n >>> TESTING - playCouncilRoom(gameState*, int) <<<\n");
	printf(" playCouncilRoom increases hand count by 4 and discards the card\n");
	memcpy(&testState, &state, sizeof(struct gameState));
	int currentPlayer = testState.whoseTurn;
	int handCount = testState.handCount[currentPlayer];
	int expectedHandCount = handCount + 3;

	playCouncilRoom(&testState, handPos);
	int actualHandCount = testState.handCount[currentPlayer];

	printf("Expected number of cards in hand: %d \tActual number of cards in hand: %d\n",
		expectedHandCount,
		actualHandCount
	);
	assertTrue(expectedHandCount == actualHandCount, "TEST FAILED: hand count incorrect after drawing/discarding.\n");

	// TEST 2: other player's hand increases by 1
	printf("\n >>> TESTING - playCouncilRoom(gameState*, int) <<<\n");
	printf(" playCouncilRoom increases opponent's hand by 1\n");
	memcpy(&testState, &state, sizeof(struct gameState));
	int opponent = 1;
	handCount = testState.handCount[opponent];
	expectedHandCount = handCount + 1;

	playCouncilRoom(&testState, handPos);
	actualHandCount = testState.handCount[opponent];

	printf("Expected number of cards in hand: %d \tActual number of cards in hand: %d\n",
		expectedHandCount,
		actualHandCount
	);
	assertTrue(expectedHandCount == actualHandCount, "TEST FAILED: opponent hand count incorrect after drawing.\n");
}

int main() {
	testPlayCouncilRoom();
	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	return 0;
}

