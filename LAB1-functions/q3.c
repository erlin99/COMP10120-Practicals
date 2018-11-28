/*LAB 1 QUESTION 3		Written by ER LIN 
Program that takes a six-digit number as a parameter and prints the digits separated from one another by four spaces and the sum. */ 
#include <stdio.h>
#include <math.h>

int spacer(int x);//prototype for function spacer 

int main(void) //main function 
{
	int x; //6-digit number to be entered by the user

	printf("Welcome to the program.\n");//prompt message 
	printf("Please enter a six-digit number:\n");//prompt message asking user for the 6-digit number
	scanf("%d", &x); //read an integer from user

	printf("%d\n", spacer(x)); //call the spacer function 
	
}
//spacer function definition
int spacer(int x)
{
	int i;//integer variable to control for loop 
	int array[6];//array to save numbers 
	int divide = 100000;//this number divides the 6-digit number 

	for (i = 0; i < 6; i++)
	{	
		array[i] = x/divide;//integer division only keeps whole number 
		x %= divide;//take remainder from division 
		divide *= 0.1;//reduce divide by one 0

		printf("%d    ", array[i]);//prompt message displaying number separated by 4 spaces
	}

	x = array[0] +  array[1] + array[2] + array[3] + array[4] + array[5]; //calculate the sum of 6 numbers  

	return x; 
}