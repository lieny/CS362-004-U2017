/********************************************************************************************
 * Author: Ya Lien
 * Class: CS362 	Assignment: Assignment 4 - randomtestcard1
 * Description: random tester for smithy card
 * Sources: testBuyCard from class repo
 * *****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "dominion.h"
#include "rngs.h"

#define NUM_TEST 100

int checkSmithyCard(struct gameState *post, int handPos){	
	int r, p, postCount = 0, preCount = 0;
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));
	r = smithyCard(post, 0); 
	p = whoseTurn(post);
	//draw 3 cards
	pre.handCount[p] += 3;
	//discard card from hand
	pre.handCount[p]--;

	postCount = post->handCount[p];
	preCount = pre.handCount[p];

	assert(r == 0);

	if(preCount != postCount)
	{
		printf("hand count should be: %d, actual count is %d.\n", preCount, postCount);
		return 1;
	}
		
	return 0;
}

int main(){
	int n, i, p, r, pass = 0, fail = 0, seed;

	//set smithy as one of the kingdom cards
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	srand(time(NULL));
	struct gameState G;

	printf("Testing smithyCard. \n");
	printf("Random Tests. \n");

	for(n = 0; n < NUM_TEST; n++)
	{
		for(i = 0; i < sizeof(struct gameState); i++)
		{
			((char*)&G)[i] = floor(Random() *256);
		}

		seed = rand();
		initializeGame(2, k, seed, &G);
		p = floor(Random() *2);
		G.deckCount[p] = floor(Random() * MAX_DECK);
    		G.discardCount[p] = floor(Random() * MAX_DECK);
    		G.handCount[p] = floor(Random() * MAX_HAND);

		r = checkSmithyCard(&G, 0);

		if(r == 0)
			pass++;
		else
			fail++;
	}

	printf("Out of %d tests, %d passed, %d failed.\n", NUM_TEST, pass, fail);
	printf("smithyCard Test Complete.\n\n");


	return 0;
}
