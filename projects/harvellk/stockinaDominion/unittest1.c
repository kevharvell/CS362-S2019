/* These unit tests test the playVillage(gameState*, int) function from dominion.c */

#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void assertTrue(int expression, char message[]) {
	if (!expression) {
		printf(message);
	}
}

void testPlayVillage() {
	struct gameState *state = malloc(sizeof(struct gameState));
	
	// TEST 1: player's hand increases by 1, then goes down 1 after discarding
	printf("\n >>> TESTING - playVillage(gameState*, int) <<<\n");
	printf(" playVillage increases hand count by 1 and discards the card\n");
	int handPos = 0;
	state->whoseTurn = 0;
	int currentPlayer = state->whoseTurn;
	state->deckCount[currentPlayer] = 10;
	state->handCount[currentPlayer] = 5;
	int expectedHandCount = 5;

	//cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
	cardEffect(village, 0, 0, 0, state, handPos, 0);
	int actualHandCount = state->handCount[currentPlayer];

	printf("Expected number of cards in hand: %d \tActual number of cards in hand: %d\n",
			expectedHandCount,
			actualHandCount
			);
	assertTrue(expectedHandCount == actualHandCount, "TEST FAILED: hand count incorrect after drawing/discarding.\n");

	// TEST 2: player gains 2 actions
	printf("\n >>> TESTING - playVillage(gameState*, int) <<<\n");
	printf(" playVillage increases actions by 2\n");
	handPos = 0;
	state->whoseTurn = 0;
	state->numActions = 1;

	int expectedActionCount = 3;

	cardEffect(village, 0, 0, 0, state, handPos, 0);
	int actualActionCount = state->numActions;

	printf("Expected number of actions: %d \tActual number actions: %d\n",
			expectedActionCount,
			actualActionCount
			);
	assertTrue(expectedActionCount == actualActionCount, "TEST FAILED: action count incorrect.\n");

	// TEST 3: player's deck count goes down by 1 after playing Village
	printf("\n >>> TESTING - playVillage(gameState*, int) <<<\n");
	printf(" playVillage decreases deck count by 1\n");
	handPos = 0;
	state->whoseTurn = 0;
	currentPlayer = state->whoseTurn;
	state->handCount[currentPlayer] = 5;
	state->deckCount[currentPlayer] = 10;
	int expectedDeckCount = 9;

	cardEffect(village, 0, 0, 0, state, handPos, 0);
	int actualDeckCount = state->deckCount[currentPlayer];

	printf("Expected number of cards in deck: %d \tActual number of cards in deck: %d\n",
			expectedDeckCount,
			actualDeckCount
			);
	assertTrue(expectedDeckCount == actualDeckCount, "TEST FAILED: deck count incorrect after drawing.\n");

	// TEST 4: player's hand increases by 1, then goes down 1 after discarding when deck count is 0
	printf("\n >>> TESTING - playVillage(gameState*, int) <<<\n");
	printf(" playVillage increases hand count by 1 and discards the card when deck count is 0\n");
	handPos = 0;
	state->whoseTurn = 0;
	currentPlayer = state->whoseTurn;
	state->discardCount[currentPlayer] = 5;
	state->deckCount[currentPlayer] = 0;
	state->handCount[currentPlayer] = 5;
	expectedHandCount = 5;

	cardEffect(village, 0, 0, 0, state, handPos, 0);
	actualHandCount = state->handCount[currentPlayer];

	printf("Expected number of cards in hand: %d \tActual number of cards in hand: %d\n",
		expectedHandCount,
		actualHandCount
	);
	assertTrue(expectedHandCount == actualHandCount, "TEST FAILED: hand count incorrect after drawing/discarding when deck count is 0.\n");

	// TEST 5: player's hand increases by 1, then goes down 1 after discarding when deck count is 1
	printf("\n >>> TESTING - playVillage(gameState*, int) <<<\n");
	printf(" playVillage increases hand count by 1 and discards the card when deck count is 1\n");
	handPos = 0;
	state->whoseTurn = 0;
	currentPlayer = state->whoseTurn;
	state->deckCount[currentPlayer] = 1;
	state->handCount[currentPlayer] = 5;
	expectedHandCount = 5;

	cardEffect(village, 0, 0, 0, state, handPos, 0);
	actualHandCount = state->handCount[currentPlayer];

	printf("Expected number of cards in hand: %d \tActual number of cards in hand: %d\n",
		expectedHandCount,
		actualHandCount
	);
	assertTrue(expectedHandCount == actualHandCount, "TEST FAILED: hand count incorrect after drawing/discarding when deck count is 1.\n");
	free(state);
}

int main() {
	testPlayVillage();
	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	return 0;
}

