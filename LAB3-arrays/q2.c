/*LAB 3 QUESTION 2		Written by: Er Lin
Program that creates and prints any NxN matrix.*/
#include <stdio.h>
void create2DMatrix(int i); //prototype for create2DMatrix function

int main(void)//main function
{
	int order; //order matrix to be entered by the user

	printf("Welcome to a program that creates and prints any NxN matrix.\n");//prompt message
	printf("Please introduce the order matrix you want:\n");//prompt message asking for order matrix
	scanf("%d", &order); //read an integer

	create2DMatrix(order); //calling create2DMatrix function
}
//create2DMatrix function definition
void create2DMatrix(int i)
{
	int matrix[i][i]; //3x3 matrix
	int j, k;
	int l = 1;

	for (j = 0; j < i; ++j) //for rows
	{
		for (k = 0; k < i; ++k) //for columns
		{
			matrix[j][k] = l;
			l++;
			printf("%d |", matrix[j][k]);
		}
		printf("\n");
	}
}
