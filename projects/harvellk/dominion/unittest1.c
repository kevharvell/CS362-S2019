#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>

//int numHandCards(struct gameState *state) {
//	return state->handCount[whoseTurn(state)];
//}

void testNumHandCards() {
	struct gameState *state = (gameState*)malloc(sizeof(struct gameState));
	state->whoseTurn = 0;
	printf("Whose Turn: %d", state->whoseTurn);
	state->handCount[state->whoseTurn] = 5;
	printf("\nNumber of cards: %d", state->handCount[state->whoseTurn]);

	int expectedNumCards = numHandCards(state);
	assert(expectedNumCards == 5);
	free(state);
}

int main() {
	testNumHandCards();
	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	return 0;
}

