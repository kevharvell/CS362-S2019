/* These random tests test the playSmithy(gameState*, int) function from dominion.c */

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

void checkPlaySmithy() {
	
}

int main() {
	int i, n, r, p, deckCount, discardCount, handCount;

	int k[10] = { adventurer, council_room, feast, gardens, mine,
				  remodel, smithy, village, baron, great_hall };

	struct gameState G;

	printf("Testing playSmithy\n");
	printf("RANDOM TESTS\n");

	SeleceStream(2);
	Put

	checkPlaySmithy();
	printf("\n >>>>> SUCCESS: Testing complete <<<<<\n\n");
	return 0;
}