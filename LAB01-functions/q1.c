/* LAB 1 QUESTION 1   Written by ER LIN 
Program to convert Celcius to Farenheit and viceversa*/
#include <stdio.h>
#include <math.h>
double tempConverterCelc(double tempCelc); //prototype for function 1(Celcius to Farenheit)
double tempConverterFah(double tempFah); //prototype for function 2(Farenheit to Celcius)

int main(void) //main function
{

	int a; //integer type variable
	double tempCelc;//temp in Celcius entered by user
	double tempFah;//temp in Farenheit entered by user

	//prompt messages asking what he wants to do
	printf("Welcome to a program to convert temperatures.\n");
	printf("If you wish to convert Celcius to Farenheit, please press 1.\n");
	printf("If viceversa, please press 2.\n");

	scanf("%d", &a); //read an integer

	if (a == 1)//in the case of 1:
	{	
		//prompt message asking temp. in Celcius
		printf("Please enter the temperature in Celcius that you wish to convert:\n");
		scanf("%lf", &tempCelc);//read a double

		printf("The conversion of %.2fºC is %.2fºF\n", tempCelc, tempConverterCelc(tempCelc)); //call function and display temp in Farenheit
	}
	else
	{
		//prompt message asking temp. in Farenheit
		printf("Please enter the temperature in Farenheit that you wish to convert:\n");
		scanf("%lf", &tempFah);//read a double

		printf("The conversion of %.2fºC is %.2fºF\n", tempFah, tempConverterFah(tempFah));//call function and display temp. in Farenheit
	}
	return 0;
}
//Convert Celcius to Farenheit function definition 
double tempConverterCelc(double tempCelc)
{	
	//returns temperature in Farenheit as a double
	return tempCelc * 9/5 + 32;
}
//Convert Farenheit to Celcius function definition
double tempConverterFah(double tempFah)
{
	//returns temperature in Celcius as a double
	return (tempFah - 32) * 5/9;
}