/*LAB 2 QUESTION 3 		Written by: ER LIN
Program that computes the Fibonacci sequence of n numbers */
#include <stdio.h>

int fibonacci(int n); //prototype for fibonacci function

int main(void) //main function
{
	int n; //amount of numbers in the fibonacci sequence to be entered by the user
	int j = 0;
	int i;

	printf("Welcome to a program to compute Fibonacci sequence of 'n' numbers.\n"); //prompt message

	printf("Please enter 'n'(the amount of numbers to be displayed from the Fibonacci sequence:\n"); //prompt message asking for n
	scanf("%d", &n); //read an integer

	//in the case that the user enters a 0, ask for a number greater than 0
	if (n == 0)
	{
		printf("NOT POSSIBLE!!\n");
		printf("Please enter a number greater than 0:\n");
		scanf("%d", &n); //read an integer
	}
	//for loop to print out all the number in the fibonaci sequence given by n
	for (i = 1; i <= n; i++)
	{
		printf("%d ", fibonacci(j));
		j++;
	}

	printf("\n");
}
//fibonacci function definition
int fibonacci(int n)
{
	//in the case of 1 or 0
	if (n == 0 || n == 1)
	{
		return n;
	}
	//in the case of any other number:
	else
		return (fibonacci(n-1) + fibonacci(n-2));
}
