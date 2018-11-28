/*LAB 2 QUESTION 6 		Written by: ER LIN
Program that simulates a game of BEAT THAT*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(void); //prototype function for rollinbg the dices

int main(void)//main function 
{	
	int player1; //score for player 1
	int player2; //score for player 2

	srand(time(NULL));//randomize random number generator using current time

	printf("Welcome to the game of 'Beat That'.\n");//prompt message
	START: printf("PLAYER 1, please press enter to roll the dice.\n");//prompt message asking player1 to throw dices
	//Next 2 lines accept enter as an input
	char enter = 0;
	while (enter != '\r' && enter != '\n') { enter = getchar(); }

	player1 = rollDice();
	printf("Number to beat: %d.\n", player1);//prompt message displaying result and number to beat
	
	printf("\nPLAYER 2, please press enter to roll the dice.\n");//prompt message asking player2 to throw dices 
	//Next 2 lines accept enter as an input					
	enter = 0;
	while (enter != '\r' && enter != '\n') { enter = getchar(); }
	
	player2 = rollDice();
	printf("PLAYER 2 number: %d.\n", player2); //prompt message displaying result for player 2

	//in the case that both players get the same number
	if (player1 == player2)
	{
		printf("\nSAME NUMBER!! Throw dice again.\n");//prompt message informing same number 
		goto START; //go back to ask to throw dice again
	}

	//if second number greater than first one 
	if (player2 > player1)
	{
		printf("\nPLAYER 2 WINS!!\n");
	}
	//if first number greater than the first one
	else if (player1 > player2)
	{
		printf("\nPLAYER 1 WINS!!\n");
	}
}
//rollDice function definiton
int rollDice(void)
{
	int die1 = 1 + (rand()%6); //value for die 1
	int die2 = 1 + (rand()%6); //value for die 2

	printf("Die 1 = %d. Die 2 =  %d.\n", die1, die2); //results for each dice 

	//depending on the result of the dice put one number before the other one 
	if (die1 <= die2)
	{	
		return die2*10 + die1;
	}
	else if (die2 <= die1)
	{
		return die1*10 + die2;
	}
	return 0;
}