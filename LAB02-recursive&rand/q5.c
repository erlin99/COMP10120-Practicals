/*LAB 2 QUESTION 5 		Written by: ER LIN
Program that produces a list of all the values of type int that are simultaneously star numbers and triangle numbers between 1 and n*/
#include <stdio.h>

int StarAndTriangleNumbers(int max); //prototype for function 

int main(void) //main function
{
	int max; //number to be entered by user 

	printf("Welcome to a program that produces values that are star numbers and triangle numbers between 1 and n.\n"); //prompr message 
	printf("Please enter n:\n"); //prompt message asking user to introduce n
	scanf("%d", &max); //read an integer 

	StarAndTriangleNumbers(max); //calling function 
}
//fucntion definition
int StarAndTriangleNumbers(int max)
{
	int i, j, k, l;

	printf("1");
	for (i = 0; i <= max; i++)
	{
		k = (i*(i+1))/2;

		for (j = 0; j <= max; j++)
		{
			l = (6*j*(j+1))+1;

			if (k==l && k!=1)
			{
				printf(", %d", k);
			}
		}
	}
	return 0;
}