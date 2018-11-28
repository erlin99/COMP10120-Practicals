/*LAB 3 QUESTION 4 		Written by: Er Lin
Program for the taxi company.*/
#include <stdio.h>

void maxSpeed (int i[]); //prototype for maximum speed function
void AverageSpeed(int i[]); //prototype for average speed function

int main(void) //main function
{
	int speed[7]; //array of 7 elements
	int i;

	printf("Welcome to the taxi program.\n"); //prompt message
	printf("Please enter the 7 speeds.\n"); //prompt message asking for the 7 sample speeds
	//for loop to read in the 7 elements of the array
	for (i = 0; i < 7; i++)
	{
		scanf("%d", &speed[i]); //read an integer
	}
	//display the sample speeds to the user
	printf("The 7 sample speeds are: ");
	for (i = 0; i < 7; i++)
	{
		printf("%d  ", speed[i]);
	}
	printf("\n");

	maxSpeed(speed); //calling maximum speed function

	AverageSpeed(speed); //calling average speed function
}
//maximum speed function definition
void maxSpeed (int i[])
{
	int max = 0; //max speed to be found
	int j;
	//for loop to find maximum speed and store it in 'max'
	for (j = 0; j < 7; j++)
	{
		if (max < i[j])
		 {
		 	max = i[j];
		 }
	}
	//give the maximum speed back to the user
	printf("The max speed is %d mph\n", max);
}
//average speed function definition
void AverageSpeed(int i[])
{
	int average = 0;
	int j;

	//for loop to calculate the sum of the elements in the array
	for (j = 0; j < 7; j++)
	{
		average += i[j];
	}
	//divide by 7 to obtain the average of the speeds
	average = average/7;

	printf("The average speed is : %d mph\n", average); //give the average speed back to the user

	if (average <= 5)
	{
		//if average speed is 5 or below, discount is earned
		printf("You have earned a discount!\n");
	}
	//if average speed is not 5 or below, no discount
	else printf("There is no discount!\n");
}
