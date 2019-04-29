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
	printf("\n >>> TESTING - playVillage(gameState*, int) <<<\n");
	printf(" playVillage increases hand count by 1 and discards the card\n");
	int handPos = 0;
	state->whoseTurn = 0;
	int currentPlayer = state->whoseTurn;
	state->handCount[currentPlayer] = 5;
	int expectedHandCount = 7;

	playSmithy(state, handPos);
	int actualHandCount = state->handCount[currentPlayer];

	printf("Expected number of cards in hand: %d \tActual number of cards in hand: %d\n",
			expectedHandCount,
			actualHandCount
			);
	assertTrue(expectedHandCount == actualHandCount, "TEST FAILED: hand count incorrect after drawing/discarding.\n");

	free(state);
}

int main() {
	testPlaySmithy();
	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	return 0;
}

