/*******************************************************************************************
 * Author: Ya Lien
 * Class: CS362 	Assignment: Assignment 3 - cardtest4
 * Description: unit test for the steward card implementation
 * ****************************************************************************************/
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

int main(){
	struct gameState game;
	int n, hc1, hc2, coin1, coin2;
	int coin_bonus;

	//Default cards, as defined in playDom
	int kCard[10] = {adventurer, steward, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	printf("Start testing Steward Card\n");

	initializeGame(2, kCard, 1, &game);
	n = whoseTurn(&game);
	
	hc1 = game.handCount[n];
	coin1 =game.coins;

//	stewardCard(&game, 1, 0, 0, 0);	//choose choice 1, add 2 cards
	cardEffect(steward, 1, 0, 0, &game, 0, &coin_bonus);
	hc2 = game.handCount[n];
	coin2 = game.coins;

	if(coin2 - coin1 == 2)
		printf("Test1 for Steward Card passed!\n");
	else
		printf("Test1 for Steward Card failed\n");

	game.handCount[n] = hc1;	//set back to original value
	game.coins = coin1;

//	stewardCard(&game, 2, 0, 0, 0); //choose to add 2 coins
	cardEffect(steward, 2, 0, 0, &game, 0, &coin_bonus);
	hc2 = game.handCount[n];
	coin2 = game.coins;

	if(hc2 == hc1 && coin2 - coin1 == 2)	//choose
		printf("Test2 for Steward Card passed!\n");
	else
		printf("Test2 for Steward Card failed\n");

	game.handCount[n] = hc1;	//set back to original value
	game.coins = coin1;

//	stewardCard(&game, 3, 1, 1, 0);	//choose to trash 2 cards
	cardEffect(steward, 3, 1, 1, &game, 0, &coin_bonus);
	hc2 = game.handCount[n];
	coin2 = game.coins;

	if(hc2 + 2 - 1 == hc1)
		printf("Test3 for Steward Card passed!\n");
	else
	{
		printf("handcount before: %d, after: %d\n", hc1, hc2);
		printf("Test3 for Steward Card failed\n");
	}
	printf("\n");

	return 0;
}

