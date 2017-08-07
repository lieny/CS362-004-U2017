/*******************************************************************************************
 * Author: Ya Lien
 * Class: CS362 	Assignment: Assignment 3 - cardtest1
 * Description: unit test for the adventurer card implementation
 * ****************************************************************************************/
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

int main(){
	struct gameState game;
	int n, i, result, tCount1 = 0, tCount2 = 0;
	int card;
	//Default cards, as defined in playDom
	int kCard[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	initializeGame(2, kCard, 1, &game);
	n = whoseTurn(&game);
	game.handCount[n] = 5;	//holds 5 card on hand

	printf("Start testing Adventurer Card\n");

	//count current treasure card on hand
	for(i = 0; i < game.handCount[n]; i++)
	{
		card = game.hand[n][i];
		if(card == copper || card == silver || card == gold)
			tCount1++;
	}

	game.deckCount[n] = 10;	//not to shuffle
	game.deck[n][0] = copper;
	game.deck[n][3] = silver;
	game.deck[n][4] = gold;
	
	result = AdventurerRe(&game);

	for(i = 0; i < game.handCount[n]; i++)
	{
		card = game.hand[n][i];
		if(card == copper || card == silver || card == gold)
			tCount2++;
	}

	if(tCount2 - tCount1 == 2)	//should draw 2 additional treasure cards to hand
		printf("Adventurer Card test1 passed!\n");

	else 
	{
		printf("Adventurer Card test1 failed.\n");
		printf("Treasure card should be: %d, current count is %d\n", tCount2, tCount1);
	}
	 

	if(result == 0)	
		printf("Adventurer Card test2 passed!\n");

	else 
		printf("Adventurer Card test2 failed.\n");

	printf("\n");


	return 0;
}
