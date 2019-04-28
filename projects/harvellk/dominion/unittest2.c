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
	int i;

	// TEST 1: players' turns are correct
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

	// TEST 2: Player's turn cannot be negative
	printf("\n >>> TESTING - whoseTurn(gameState*) <<<\n");
	printf(" whoseTurn is cannot be negative for players. \n");
	for (i = 0; i < MAX_PLAYERS; i++) {
		state->whoseTurn = i * -1;
		printf("Player turn: %d\n",
			whoseTurn(state)
		);
		assertTrue(whoseTurn(state) >= 0, "TEST FAILED: Player Turn cannot be negative.\n");
	}

	// TEST 2: Player's turn cannot exceed MAX_PLAYERS - 1
	printf("\n >>> TESTING - whoseTurn(gameState*) <<<\n");
	printf(" whoseTurn is cannot exceed (MAX_PLAYERS - 1) for players. \n");
	for (i = MAX_PLAYERS - 1; i < MAX_PLAYERS + MAX_PLAYERS; i++) {
		state->whoseTurn = i;
		printf("Player turn: %d\n",
			whoseTurn(state)
		);
		assertTrue(whoseTurn(state) >= 0, "TEST FAILED: Player Turn cannot exceed (MAX_PLAYERS - 1).\n");
	}

	free(state);
}

int main() {
	testWhoseTurn();
	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	return 0;
}

