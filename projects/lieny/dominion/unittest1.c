/*********************************************************************************************
 * Author: Ya Lien
 * Class: CS362 	Assignment: Assignment 3 - unittest1
 * Description: unit test for the isGameOver function
 * ******************************************************************************************/
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

int main(){
	struct gameState game;
	int result, i, p = 0;
	int start = 0, end = 3;
	//Default cards, as defined in playDom
	int kCard[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	
	//initialize the game with 2 players and the kingdom cards
	initializeGame(2, kCard, 1, &game);
	
	result = isGameOver(&game);
	if(result == 0)
	{
		printf("Test1 for isGameOver passed!\n");
		p += 1;
	}

	else
		printf("Test1 for isGameOver failed. Result is %d\n", result);

	//test when Province card stack is empty
	game.supplyCount[province] = 0;
	result = isGameOver(&game);

	if(result == 1)
	{
		printf("Test2 for isGameOver passed!\n");
		p += 1;
	}

	else
		printf("Test2 for isGameOver failed. Result is %d\n", result);


	//test when three supply piles are at 0
	while(end < 25)
	{
		for(i = start; i < end; i++)
			game.supplyCount[i] = 0;

		result = isGameOver(&game);

		assert(result == 1);

		for(i = start; i < end; i++)
			game.supplyCount[i] = 1;

		start += 3;
		end += 3;
	}

	printf("Test3 for isGameOver passed!\n");
	p += 1;

	if(p == 3)
		printf("All test for isGameOver passed!\n\n");	


	return 0;
}
