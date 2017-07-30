/********************************************************************************************
 * Author: Ya Lien
 * Class: CS362 	Assignment: Assignment 4 - randomtestadventurer.c
 * Description: random tester for adventurer card
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

#define NUM_TEST 500

int checkAdventurerCard(int p, struct gameState *post){
	int newCards = 2;	
	int r, i, card, postCount = 0, preCount = 0;
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));
	r = adventurerCard(post); 
	if(pre.deckCount[p] > 0)	//draw 2 treasure cards
	{
		pre.handCount[p] += newCards;
		pre.hand[p][pre.handCount[p] - 1] = copper;
		pre.hand[p][pre.handCount[p] - 2] = gold;
	}

	for(i = 0; i < post->handCount[p]; i++)	//count treasure card in post
	{
		card = post->hand[p][i];
		if(card == copper || card == silver || card == gold)
			postCount++;
	}

	for(i = 0; i < pre.handCount[p]; i++) //count treasure card in pre
	{
		card = pre.hand[p][i];
		if(card == copper || card == silver || card == gold)
			preCount++;
	}

	assert(r == 0);
	if(preCount == postCount)
		return 0;
	else
	{
		printf("Treasure card should be: %d, actual count is %d\n", preCount, postCount);
		return 1;
	}
}	

int main(){
	int n, i, p, r, pass = 0, fail = 0, seed;

	//set cards as defined in testBuyCard
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	srand(time(NULL));
	struct gameState G;

	printf("Testing adventurerCard. \n");
	printf("Random Tests. \n");

//	SelectStream(2);
//	PutSeed(3);

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

		r = checkAdventurerCard(p, &G);

		if(r == 0)
			pass++;
		else
			fail++;
	}
	
	printf("Out of %d tests, %d passed, %d failed.\n", NUM_TEST, pass, fail);
	printf("AdventurerCard Test Complete.\n\n");




	return 0;
}
