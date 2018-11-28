/*LAB 1 QUESTION 2    Written By ER LIN
Program to determine if a child is living in a overcrowded dwelling*/
#include <stdio.h>

int overCrowded(int rooms, int people); //prototype for function overCrowded

int main(void) //main function
{
	int rooms; //number of rooms to be entered by user
	int people;//number of people to be entered by user

	printf("Welcome to a program to determine if your child is living in an overcrowded dwelling.\n");//prompt message

	printf("Please enter the number of rooms in the dwelling:\n");//prompt message asking for nº of rooms
	scanf("%d", &rooms);//read an integer

	printf("Please enter the number of people living in the dwelling:\n");//prompt message asking for nº of people
	scanf("%d", &people);//read an integer 

	printf("\nYour result is: %d\n", overCrowded(rooms, people));//call overCrowded function

	return 0;
}
//determining overcrowding for a child function definition
int overCrowded(int rooms, int people)
{
	if (people/(rooms * 1.0) > 2)
	{
		return 1;//return 1 if it is over crowded for child
	}
	else return 0; //return 0 if it is not over crowded for child
}
