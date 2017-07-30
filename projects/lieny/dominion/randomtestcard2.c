/*********************************************************************************************
 * Author: Ya Lien
 * Class: CS362 	Assignment: Assignment 4 - randomtestcard2
 * Description: random tester for village card
 * Sources: 
 * ******************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "dominion.h"
#include "rngs.h"

#define NUM_TEST 500

int checkVillageCard(struct gameState *post)
{
	int r, p, preCount, postCount;
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));
	p = whoseTurn(post);
	r = villageCard(post, 0);
	
	pre.numActions += 2;	//+2 action
	pre.handCount[p]++;	//+1 card
//	discardCard(0, p, pre, 0);
	pre.handCount[p]--; 	//discard card

	preCount = pre.handCount[p];
	postCount = post->handCount[p];
	assert(r == 0);
	
	if(pre.numActions != post->numActions)
	{
		printf("num of action should be %d, actual count is %d.\n", pre.numActions, post->numActions);
		return 1;
	}
	else if(preCount != postCount)
	{
		printf("hand count should be %d, actual count is %d.\n", preCount, postCount);
		return 2;
	}

	return 0;
}

int main(){
	int r, p, i, n, seed, pass = 0, cfail = 0, hfail = 0;
	//set cards as defined in testBuyCard
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	srand(time(NULL));
	struct gameState G;

	printf("Testing Village Card. \n");
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

		r = checkVillageCard(&G);
		
		if(r == 0)
			pass++;
		else if(r == 1)
			cfail++;
		else if(r == 2)
			hfail++;
	}

	printf("Out of %d tests, %d passed, %d action count failed, %d hand count failed.\n", NUM_TEST, pass, cfail, hfail);
	printf("VillageCard Test Complete.\n\n");

	return 0;
}

