/* These unit tests test the whoseTurn(gameState*) function from dominion.c */

#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <limits.h>

void assertTrue(int expression, char message[]) {
	if (!expression) {
		printf(message);
	}
}

void testWhoseTurn() {
	struct gameState *state = malloc(sizeof(struct gameState));

	// TEST 1: players have correct number of cards
	printf("\n >>> TESTING - whoseTurn(gameState*) <<<\n");
	printf(" whoseTurn is correct for all players. \n");
	for (i = 0; i < MAX_PLAYERS; i++) {
		state->whoseTurn = i;
		printf("Expected Player: %d \tActual Player: %d\n",
			state->whoseTurn,
			whoseTurn(state)
			);
		int expectedPlayerTurn = i;
		assertTrue(expectedPlayerTurn == whoseTurn(state), "TEST FAILED: Player Turn is incorrect.\n");
	}

	free(state);
}

int main() {
	testWhoseTurn();
	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	return 0;
}

