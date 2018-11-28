/*LAB 3 QUESTION 3 		Written by: Er Lin
Program that computes the determinant of a 3x3 square matrix.*/
#include <stdio.h>

void detCalculator(int matrix[][3], int order); //prototype for determinant calculator function

int main(void) //main function
{
	int matrix[3][3]; //array with 3 rows and 3 columns
	int i, j;

	printf("Welcome to a program that computes the determinant of a 3x3 matrix.\n"); //prompt message
	printf("Please enter in order the 9 elements of the matrix:\n"); //prompt message asking for matrix elements
	//for loop to read in the 9 elements of the matrix
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &matrix[i][j]); //reading integers
		}
	}
	//display the elements in the form of the matrix
	printf("Your matrix is:\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d  ", matrix[i][j]);
		}
		printf("\n");
	}

	printf("The determinant is: ");//prompt message to give result back to user

	detCalculator(matrix, 3); //calling determinant calculator function
}
//determinant calculator function definition
void detCalculator(int matrix[3][3], int order)
{
	int det; //determinant to be calculated

	//calculations to find determinant
	det = matrix[0][0] * ((matrix[1][1]*matrix[2][2]) - (matrix[2][1]*matrix[1][2])) -matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);

	printf("%d\n", det); //give result back to user (prompt message)
}
