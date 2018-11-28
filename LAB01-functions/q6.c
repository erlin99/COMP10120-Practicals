/*LAB 1 QUESTION 6  	Written by ER LIN
Program to caluclate the total price depending on the number of beans purchased.*/
#include <stdio.h>

int beanPricer(int n); //prototype for function that the determines the price of beans 

int main(void)
{
	int n; //number of beans to be entered by user

	printf("Welcome to your beans price calculator.\n");//prompt message

	printf("Please introduce the number of beans:\n");//prompt message asking for the number of beans
	scanf("%d", &n); //read an integer

	printf("The total price %d beans is %d.\n", n, beanPricer(n));//calling beanPricer funcion
} 
//beans pirce calculator function definition
int beanPricer(int n)
{
	if (n <= 100 && n > 0)
	{
		return n * 5;//return this if number of beans between 1-100 
	}
	else if (n <= 250 && n > 100)
	{
		return 100*5 + (n-100)*3;//return this if number of beans between 100-250
	}
	else if (n <= 700 && n > 250)
	{
		return 100*5 + 150*3 + (n-250)*2;//return this if number of beans between 250-700
	}
	else if (n > 700)
	{
		return 100*5 + 150*3 + 450*2 + (n-700);//return this if number of beans is more than 700
	}
	else return 0;//return 0 if none of the above is satisfied
}