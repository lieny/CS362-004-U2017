/*******************************************************************************************
 * Author: Ya Lien
 * Class: CS362 	Assignment: Assignment 3 - cardtest2
 * Description: unit test for the smithy card implementation
 * ****************************************************************************************/
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

int main(){
	struct gameState game;
	int n, hc1, hc2, result;

	//Default cards, as defined in playDom
	int kCard[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	printf("Start testing Smithy Card\n");
	
	initializeGame(2, kCard, 1, &game);
	n = whoseTurn(&game);

	hc1 = game.handCount[n];
	result = smithyCard(&game, 0);

	hc2 = game.handCount[n];

	printf("hc2 = %d\n", hc2);
	if(hc2 +1 - hc1 == 3)	//+1 since smithy is disgarded in its own function
		printf("Smithy Card test1 passed!\n");

	else 
		printf("Smithy Card test1 failed.\n");
	 

	if(result == 0)
		printf("Smithy Card test2 passed!\n");

	else 
		printf("Smithy Card test2 failed.\n");

	printf("\n");

	endTurn(&game);
	
	return 0;
}
