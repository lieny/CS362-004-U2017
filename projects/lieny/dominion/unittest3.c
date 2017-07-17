/*********************************************************************************************
 * Author: Ya Lien
 * Class: CS362 	Assignment: Assignment 3 - unittest3
 * Description: unit test for the buyCard function
 * ******************************************************************************************/
#include <stdio.h>
//#include "assert.h"
#include "dominion.h"
#include "rngs.h"

int main()
{
	struct gameState game;
//	int i;
	int result, p = 0;

	//Default cards, as defined in playDom
	int kCard[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	printf("Start testing buyCard. \n");

	//initialize the game with 2 players and the kingdom cards
	initializeGame(2, kCard, 1, &game);

	
	//test when numBuys is < 1
	game.numBuys = 0;
	game.supplyCount[2] = 8; //make sure there are enough card to buy
	game.coins = 10; //make sure player has enough coins
	result = buyCard(2, &game);
	if(result == -1)
	{
		printf("Test1 for buyCard passed!\n");
		p += 1;
	}

	else
		printf("Test1 for buyCard failed. Result is %d\n", result);


	//test when supplyCount is < 1
	game.numBuys = 1;
	game.supplyCount[2] = 0;	
	result = buyCard(2, &game);
	if(result == -1)
	{
		printf("Test2 for buyCard passed!\n");
		p += 1;
	}

	else
		printf("Test2 for buyCard failed. Result is %d\n", result);

	//test when coins is < cost of card #2
	game.supplyCount[2] = 8;
	game.coins = 0;
	result = buyCard(2, &game);
	if(result == -1)
	{
		printf("Test3 for buyCard passed!\n");
		p += 1;
	}

	else
		printf("Test3 for buyCard failed. Result is %d\n", result);

	//test on successfully buying card
	game.numBuys = 1;
	game.supplyCount[2] = 8;
	game.coins = 10; //make sure player has enough coins

	result = buyCard(2, &game);
	if(game.phase == 1)
	{
		printf("Test4 for buyCard passed!\n");
		p += 1;
	}

	else
		printf("Test4 for buyCard failed. game.phase is %d\n", game.phase);

//	i = getCost(2);
	if(game.coins == 5)	 //coins left should be 10 - card of card#2
	{
		printf("Test5 for buyCard passed!\n");
		p += 1;
	}

	else
		printf("Test5 for buyCard failed. game.coins is %d\n", game.coins);

	if(game.numBuys == 0)	 //numBuys should be 1 -1 
	{
		printf("Test6 for buyCard passed!\n");
		p += 1;
	}

	else
		printf("Test6 for buyCard failed. game.numBuys is %d\n", game.numBuys);

	if(result == 0)
	{
		printf("Test7 for buyCard passed!\n");
		p += 1;
	}

	else
		printf("Test7 for buyCard failed. Result is %d\n", result);

	if(p == 7)
		printf("All tests for buyCard passed!\n\n");

	return 0;
}
