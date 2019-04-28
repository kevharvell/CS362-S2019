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
	printf(" >>> TESTING - numHandCards(gameState*) <<<\n");
	printf(" Number of Cards in all players' hands is correct\n");
	int i;
	int numCards = 1; 
	for (i = 0; i < MAX_PLAYERS; i++) {
		state->whoseTurn = i;
		state->handCount[state->whoseTurn] = numCards;
		printf("Player: %d \tExpected Number of Cards in hand: %d \tActual Number of Cards in hand: %d\n",
			state->whoseTurn,
			numCards,
			numHandCards(state));
		int expectedNumCards = numHandCards(state);
		assert(expectedNumCards == numCards);
		numCards++;
	}

	// TEST 2: players have correct number of cards after gaining cards
	printf(" >>> TESTING - numHandCards(gameState*) <<<\n");
	printf(" Number of Cards in all players' hands is correct after gaining 2 cards.\n");
	for (i = 0; i < MAX_PLAYERS; i++) {
		state->whoseTurn = i;
		state->handCount[state->whoseTurn] += 2;
		printf("Player: %d \tExpected Number of Cards in hand: %d \tActual Number of Cards in hand: %d\n",
			state->whoseTurn,
			state->handCount[state->handCount] + 2,
			numHandCards(state));
		int expectedNumCards = numHandCards(state);
		assert(expectedNumCards == state->handCount[state->handCount] + 2);
	}
	
	free(state);
}

int main() {
	testNumHandCards();
	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	return 0;
}

