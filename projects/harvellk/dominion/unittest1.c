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
	struct gameState *state = malloc(sizeof(struct gameState));

	// TEST 1: players have correct number of cards
	printf("*** TESTING - numHandCards(gameState*) - Number of Cards in all players' hands is correct ***");
	int i;
	int numCards = 1; 
	for (i = 0; i < MAX_PLAYERS; i++) {
		state->whoseTurn = i;
		state->handCount[state->whoseTurn] = numCards;
		printf("Player: %d \tExpected Number of Cards in hand: %d \tActual Number of Cards in hand: %d\n", 
			state->whoseTurn, 
			numCards, 
			numHandCards(state))
		int expectedNumCards = numHandCards(state);
		assert(expectedNumCards == numCards);
		numCards++;
	}
	
	free(state);
}

int main() {
	testNumHandCards();
	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	return 0;
}

