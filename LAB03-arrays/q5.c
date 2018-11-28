/*LAB 3 QUESTION 5		Written by: Er Lin
Program that will keep track of how many vehicles are in a car park every hour. */
#include <stdio.h>

//function prototypes 
int carIn(int inBatch[]); //amount of vehicles that entered the car park within the hour and overall
int carOut(int outBatch[]); //amount of that left the car park within the hour and overall
void currentState(int x, int y); //number of vehicles remaining in the car park at a given time 
void salesMade(int i); //calculates the number of sales that have been made for the day at the time it was called

int NumberOfCarsThatEnteredSoFar; //cars that entered
int NumberOfCarsThatLeftSoFar; //cars that left

int main(void) //main function 
{
	int inBatch[] = {1, 2, 5}; //cars in, in 1 hour(every 20min)
	int outBatch[] = {1, 2 , 1}; //cars out in 1 hour(every 20min)

	//calling functions
	carIn(inBatch); 
	carOut(outBatch); 
	currentState(NumberOfCarsThatEnteredSoFar, NumberOfCarsThatLeftSoFar);
	salesMade(NumberOfCarsThatLeftSoFar);
}

//carIn function definition
int carIn(int inBatch[])
{
	int hourlyEntry = 0; //entry of cars per hour 

	//for loop to calculate entry of cars per hour 
	for (int i = 0; i < 3; i++)
	{
		hourlyEntry += inBatch[i];
	}
	//calculation of total vehicle entry
	NumberOfCarsThatEnteredSoFar += hourlyEntry;

	//prompt message displaying total and hourly vehicle entry 
	printf("Total vehicle entry: %d\n", NumberOfCarsThatEnteredSoFar);
	printf("Hourly vehicle entry: %d\n", hourlyEntry);

	return hourlyEntry;
}

//carOut function definition 
int carOut(int outBatch[])
{	
	int hourlyExit = 0; //exit of cars per hour

	//for loop to calculate exit of cars per hour 
	for (int i = 0; i < 3; i++)
	{
		hourlyExit += outBatch[i];
	}
	//calculation of total vehicle exit
	NumberOfCarsThatLeftSoFar += hourlyExit;

	//prompt messages diplaying the total and hourly vehicle exit
	printf("Total vehicle exit: %d\n", NumberOfCarsThatLeftSoFar);
	printf("Hourly vehicle exit: %d\n", hourlyExit);

	return hourlyExit;
}

//currentState function definition 
void currentState(int x, int y)
{	
	int remainingCars; //remaining cars to be calculated 
	remainingCars = x - y; //calculation of remaining cars

	//prompt message displaying the remaining cars in the car park
	printf("Vehicles remaining in the park : %d\n", remainingCars);
}

//salesMade function definition 
void salesMade(int i)
{
	double sales; //sales made to be calculated
	sales = i * 2.50; //calculation for sales made

	//prompt message displaying earnings of the car park 
	printf("The park has made Euros %.2f\n", sales);
}