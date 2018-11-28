/*LAB 2 QUESTION 1 		Written by: ER LIN
Program to calculate the volume of a square pyramid */
#include <stdio.h>

double pyVolCalculator(double i, double j); //prototype for Volume Calculator function 

int main(void) //main function
{
	double i; //height of the pyramid to be entered by the user 
	double j; //base lentgh t of the pyramid to be entered by the user

	printf("Welcome to a program that calculates the volume of a square pyramid.\n"); //prompt message

	printf("Please enter the height of the pyramid:\n"); //prompt message asking for the height 
	scanf("%lf", &i); //read a double 

	printf("Please enter the length of the base edge\n"); //prompt message asking for the length
	scanf("%lf", &j); //read a double 

	printf("The volume of your square pyramid is: %.2f.\n", pyVolCalculator(i, j)); //calling VolCalculator function
}
//Volume Calculator function definition
double pyVolCalculator(double i, double j)
{
	//returns the volume of the pyramid
	return i*i*(j/3); 
}
