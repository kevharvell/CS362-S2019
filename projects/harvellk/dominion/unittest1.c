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
	struct gameState *state;
	state->whoseTurn = 0;
	state->handCount[state.whoseTurn] = 5;


	assert(numHandCards(state) == 5);
}

int main() {
	testNumHandCards();
	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	return 0;
}

