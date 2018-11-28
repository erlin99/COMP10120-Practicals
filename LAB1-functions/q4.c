/*LAB 1 QUESTION 4    Written By ER LIN 
Program to calculate your BMI and determine your category*/
#include <stdio.h>
#include <math.h>

int BMICalculator(double weight, double height);//protype for function to calculate BMI

int main(void)//main function
{
	double weight;//weight to be entered by the user 
	double height;//height to be entered by the user
	
	printf("Welcome to a program to calculate your BMI and determine if you are underweight, normal weight or overweight\n");//prompt message
	
	printf("Please enter your weight in kg:\n");//prompt message asking for weight
	scanf("%lf", &weight);//read a double

	printf("Please enter your height in cm:\n");//prompt message asking for height
	scanf("%lf", &height);//read a double
	
	printf("Your category is: %d\n", BMICalculator(weight, height));//call BMICalculator function
}
//BMI Calculator function definition
int BMICalculator(double weight, double height)
{
	int a;//variable to store BMI 
	a = weight/((height/100) * (height/100));//calculating BMI
	
	if (a < 18.5)
	{
		return 1;//return integer 1 if underweight
	}
	else if (a >= 18.5 && a < 25)
	{
		return 0;//return integer 0 if normal weight
	}
	else return 2;//return intefger 2 if overweight

}
