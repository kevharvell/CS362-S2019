#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <limits.h>

//int numHandCards(struct gameState *state) {
//	return state->handCount[whoseTurn(state)];
//}

void testNumHandCards() {
	struct gameState *state = malloc(sizeof(struct gameState));

	// TEST 1: players have correct number of cards
	printf("\n >>> TESTING - numHandCards(gameState*) <<<\n");
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
	printf("\n >>> TESTING - numHandCards(gameState*) <<<\n");
	printf(" Number of Cards in all players' hands is correct after gaining 2 cards.\n");
	numCards = 1;
	for (i = 0; i < MAX_PLAYERS; i++) {
		state->whoseTurn = i;
		state->handCount[state->whoseTurn] = numCards;
		state->handCount[state->whoseTurn] += 2;
		numCards += 2;
		printf("Player: %d \tExpected Number of Cards in hand: %d \tActual Number of Cards in hand: %d\n",
			state->whoseTurn,
			numCards,
			numHandCards(state));
		int expectedNumCards = numHandCards(state);
		assert(expectedNumCards == numCards);
		numCards++;
	}
	
	// TEST 3: players have correct number of cards after losing cards
	printf("\n >>> TESTING - numHandCards(gameState*) <<<\n");
	printf(" Number of Cards in all players' hands is correct after losing 2 cards.\n");
	numCards = 3;
	for (i = 0; i < MAX_PLAYERS; i++) {
		state->whoseTurn = i;
		state->handCount[state->whoseTurn] = numCards;
		state->handCount[state->whoseTurn] -= 2;
		numCards -= 2;
		printf("Player: %d \tExpected Number of Cards in hand: %d \tActual Number of Cards in hand: %d\n",
			state->whoseTurn,
			numCards,
			numHandCards(state));
		int expectedNumCards = numHandCards(state);
		assert(expectedNumCards == numCards);
		numCards+=3;
	}

	// TEST 4: players can gain a lot of cards
	printf("\n >>> TESTING - numHandCards(gameState*) <<<\n");
	printf(" Number of Cards in all players' hands is correct after gaining a lot of cards.\n");
	numCards = 0;
	for (i = 0; i < MAX_PLAYERS; i++) {
		state->whoseTurn = i;
		state->handCount[state->whoseTurn] = numCards;
		state->handCount[state->whoseTurn] += INT_MAX;
		printf("Player: %d \tExpected Number of Cards in hand: %d \tActual Number of Cards in hand: %d\n",
			state->whoseTurn,
			INT_MAX,
			numHandCards(state));
		int expectedNumCards = numHandCards(state);
		assert(expectedNumCards == INT_MAX);
	}
	free(state);
}

int main() {
	testNumHandCards();
	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	return 0;
}

