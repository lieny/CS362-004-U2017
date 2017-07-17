/*********************************************************************************************
 * Author: Ya Lien
 * Class: CS362 	Assignment: Assignment 3 - unittest4
 * Description: unit test for the scoreFor function
 * ******************************************************************************************/
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"

int main(){
	struct gameState game;
	int result, n, p = 0;
	//Default cards, as defined in playDom
	int kCard[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	
	printf("Start testing scoreFor.\n");
	//initialize the game with 2 players and the kingdom cards
	initializeGame(2, kCard, 1, &game);

	n = whoseTurn(&game);

	//test score from hand
	game.discardCount[n] = 0; //make sure only testing hand
	game.deckCount[n] = 0;
	game.handCount[n] = 6;
	game.hand[n][1] = curse;	//-1
	game.hand[n][2] = estate;	//+1
	game.hand[n][3] = duchy;	//+3
	game.hand[n][4] = province;	//+6
	game.hand[n][5] = great_hall;	//+1
	game.hand[n][0] = gardens;	//if score a garden, you get a victor point per every 10 cards in your deck
	
	result = scoreFor(n, &game);
	if(result == 10)
	{
		printf("Test score from hand passed!\n");
		p += 1;
	}
	else
		printf("Test score from hand failed. The score is %d\n", result);


	//test score from discard
//	game.deck[n][0] = -1;
	game.discardCount[n] = 6; //make sure only testing discard
	game.deckCount[n] = 0;
	game.handCount[n] = 0;
	game.discard[n][1] = curse;
	game.discard[n][2] = estate;
	game.discard[n][3] = duchy;
	game.discard[n][4] = province;
	game.discard[n][5] = great_hall;
	game.discard[n][0] = gardens;	//if score a garden, you get a victor point per every 10 cards in your deck

	result = scoreFor(n, &game);
	if(result == 10)
	{
		printf("Test score from discard passed!\n");
		p += 1;
	}

	else
		printf("Test score from discard failed. The score is %d\n", result);

	//test score from deck
	game.discardCount[n] = 0; //make sure only testing discard
	game.deckCount[n] = 6;
	game.handCount[n] = 0;
	game.deck[n][1] = curse;
	game.deck[n][2] = estate;
	game.deck[n][3] = duchy;
	game.deck[n][4] = province;
	game.deck[n][5] = great_hall;
	game.deck[n][0] = gardens;	//if score a garden, you get a victor point per every 10 cards in your deck

	result = scoreFor(n, &game);
	if(result == 10)
	{
		printf("Test score from deck passed!\n");
		p += 1;
	}

	else
		printf("Test score from deck failed. The score is %d\n", result);

	if(p == 3)
		printf("All test for scoreFor passed!\n");

	printf("\n");
	return 0;
}
