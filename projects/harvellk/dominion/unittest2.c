/* These unit tests test the playSmithy(gameState*, int) function from dominion.c */

#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

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

void assertTrue(int expression, char message[]) {
	if (!expression) {
		printf(message);
	}
}

void testPlaySmithy() {
	struct gameState *state = malloc(sizeof(struct gameState));
	
	// TEST 1: player's hand increases by 3, then goes down 1 after discarding
	printf("\n >>> TESTING - playSmithy(gameState*, int) <<<\n");
	printf(" playSmithy increases hand count by 3 and discards the card\n");
	int handPos = 0;
	state->whoseTurn = 0;
	int currentPlayer = state->whoseTurn;
	state->deckCount[currentPlayer] = 10;
	state->handCount[currentPlayer] = 5;
	int expectedHandCount = 7;

	playSmithy(state, handPos);
	int actualHandCount = state->handCount[currentPlayer];

	printf("Expected number of cards in hand: %d \tActual number of cards in hand: %d\n",
			expectedHandCount,
			actualHandCount
			);
	assertTrue(expectedHandCount == actualHandCount, "TEST FAILED: hand count incorrect after drawing/discarding.\n");

	// TEST 2: player's hand increases by 3, then goes down 1 after discarding when deck count is 0
	printf("\n >>> TESTING - playSmithy(gameState*, int) <<<\n");
	printf(" playSmithy increases hand count by 3 and discards the card when deck count is 0\n");
	handPos = 0;
	state->whoseTurn = 0;
	currentPlayer = state->whoseTurn;
	state->deckCount[currentPlayer] = 0;
	state->handCount[currentPlayer] = 5;
	expectedHandCount = 7;

	playSmithy(state, handPos);
	actualHandCount = state->handCount[currentPlayer];

	printf("Expected number of cards in hand: %d \tActual number of cards in hand: %d\n",
		expectedHandCount,
		actualHandCount
	);
	assertTrue(expectedHandCount == actualHandCount, "TEST FAILED: hand count incorrect after drawing/discarding when deck count is 0.\n");

	// TEST 3: player's deck count decreases by 3 (when deck has 3 cards)
	printf("\n >>> TESTING - playSmithy(gameState*, int) <<<\n");
	printf(" playSmithy decreases deck count by 3 (when deck has 3 cards)\n");
	handPos = 0;
	state->whoseTurn = 0;
	currentPlayer = state->whoseTurn;
	state->deckCount[currentPlayer] = 3;
	state->handCount[currentPlayer] = 5;
	int expectedDeckCount = 7;

	playSmithy(state, handPos);
	int actualDeckCount = state->deckCount[currentPlayer];

	printf("Expected number of cards in deck: %d \tActual number of cards in deck: %d\n",
		expectedDeckCount,
		actualDeckCount
	);
	assertTrue(expectedDeckCount == actualDeckCount, "TEST FAILED: deck count incorrect after drawing when deck count is 3.\n");

	free(state);
}

int main() {
	testPlaySmithy();
	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	return 0;
}

