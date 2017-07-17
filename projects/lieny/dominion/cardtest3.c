/*******************************************************************************************
 * Author: Ya Lien
 * Class: CS362 	Assignment: Assignment 3 - cardtest3
 * Description: unit test for the village card implementation
 * ****************************************************************************************/
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

int main(){
	struct gameState game;
	int n, hc1, hc2, result, act1, act2;

	//Default cards, as defined in playDom
	int kCard[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	printf("Start testing Village Card\n");

	initializeGame(2, kCard, 1, &game);
	n = whoseTurn(&game);

	act1 = game.numActions;
	hc1 = game.handCount[n];

	result = villageCard(&game, 0);

	act2 = game.numActions;
	hc2 = game.handCount[n];

	if(act2 - act1 == 2) //action for playing this card is -1 AFTER this function exit
		printf("Village Card test1 passed!\n");

	else 
		printf("Village Card test1 failed.\n");

	if(hc2 + 1 - hc1 == 1)
		printf("Village Card test2 passed!\n");

	else 
		printf("Village Card test2 failed.\n");

	if(result == 0)
		printf("Village Card test3 passed!\n");

	else 
		printf("Village Card test3 failed.\n");

	endTurn(&game);

	printf("\n");

	return 0;
}
