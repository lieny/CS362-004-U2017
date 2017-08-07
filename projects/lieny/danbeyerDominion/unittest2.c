/*********************************************************************************************
 * Author: Ya Lien
 * Class: CS362 	Assignment: Assignment 3 - unittest2
 * Description: unit test for the fullDeckCount function
 * ******************************************************************************************/
#include <stdio.h>
//#include "assert.h"
#include "dominion.h"
#include "rngs.h"

int main()
{
	struct gameState game;
	int i, n, p = 0;
	int result;
	//Default cards, as defined in playDom
	int kCard[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	printf("Start testing fullDeckCount.\n");

	//initialize the game with 2 players and the kingdom cards
	initializeGame(2, kCard, 1, &game);

	n = whoseTurn(&game);
	game.deckCount[n] = 10; //player 1 has 10 deck, 10 hand, and 10 discards
	game.handCount[n] = 10;	//player 1 has 10 hand
	game.discardCount[n] = 10; //player 1 has 10 discards

	for(i = 0; i < 10; i++)
	{
		game.deck[n][i] = i; //initialize deck from 0 ~ 9
		game.hand[n][i] = i;
		game.discard[n][i] = i;
	}

	result = fullDeckCount(n, 2, &game);
	if(result == 3)  	// the cound for card #2 should be 3
	{
		printf("Test1 for fullDeckCount passed!\n");
		p += 1;
	}

	else
		printf("Test1 for fullDeckCount failed. Result is %d\n", result);


	endTurn(&game);
	n = whoseTurn(&game);

	game.deckCount[n] = 10; //player 2 has 10 deck, 10 hand, and 10 discards
	game.handCount[n] = 10;	//player 2 has 10 hand
	game.discardCount[n] = 10; //player 2 has 10 discards

	for(i = 0; i < 10; i++)
	{
		game.deck[n][i] = 3;
		game.hand[n][i] = 0;
		game.discard[n][i] = 3;
	}

	result = fullDeckCount(n, 2, &game);
	if(result == 0)		// the cound for card #2 should be 0
	{
		printf("Test2 for fullDeckCount passed!\n");
		p += 1;
	}

	else
		printf("Test2 for fullDeckCount failed. Result is %d\n", result);

	result = fullDeckCount(n, 3, &game);
	if(result == 20)
	{
		printf("Test3 for fullDeckCount passed!\n");
		p += 1;
	}

	else
		printf("Test3 for fullDeckCount failed. Result is %d\n", result);


	result = fullDeckCount(n, 0, &game);
	if(result == 10)
	{
		printf("Test4 for fullDeckCount passed!\n");
		p += 1;
	}

	else
		printf("Test4 for fullDeckCount failed. Result is %d\n", result);


	if(p == 4)
		printf("All test for fullDeckCount passed!\n");
	
	printf("\n");

	return 0;
}
