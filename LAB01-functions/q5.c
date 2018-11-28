/*LAB 1 QUESTION 5  	Written by ER LIN
Program to collect 3 integers and print the average, product, sum, largest and smallest*/
#include <stdio.h>

int mathTest(int x, int y, int z);//prototype for function 

int main(void)//main function
{
	int x; //1st number to be entered by the user
	int y; //2nd number to be entered by the user
	int z; //3rd number to be entered by the user

	printf("Welcome to a program to calculate the average, product, sum, largest and smallest out of 3 integers.\n");//prompt message

	printf("Please enter the 1st number:\n");//prompt message asking for 1st number 
	scanf("%d", &x);//read an integer

	printf("Please enter the 2nd number:\n");//prompt message asking for 2nd number 
	scanf("%d", &y);//read an integer

	printf("Please enter the 3rd number:\n");//prompt message asking for 3rd number 
	scanf("%d", &z);//read an integer

	mathTest(x, y, z);//call mathTest function

}
//math test function definition
int mathTest(int x, int y, int z)
{
	int largest, smallest; //integer variables for largest number and smallest

	if (x >= y && x >= z) 
	{
		largest = x; //if x is the largest number, assign x to largest
	}
	else if (y >= x && y >= z)
	{
		largest = y; //if y is the largest number, assign y to largest 
	}
	else largest = z; //if z is the largest number, assign z to largest 
	
	if (x <= y && x <= z)
	{
		smallest = x; //if x is the smallest number, assign x to smallest
	}
	else if (y <= x && y <= z)
	{
		smallest = y; //if y is the smallest number, assign y to smallest 
	}
	else smallest = z; //if z is the smallest number, assign z to smallest

	//prompt message giving result back to user
	printf("The three numbers are %d, %d and %d. The average is %.2f. The product is %d. The sum is %d. The largest is %d. The smallest is %d.\n", x, y, z, (x+y+z)/3.0, x*y*z, x+y+z, largest, smallest);
	
	return 0;
}
