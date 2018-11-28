/*LAB 2 QUESTION 2 		Written by: ER LIN
Program that accepts a date of birth as parameters and outputs the day of the week which an individual was born. */
#include <stdio.h>
#include <math.h>

int birthdayDay(int days, int month, int year); //prototype for birthdayDay function

int main(void) //main function
{
	int days; //day to be entered by the user
	int month; //month to be entered by the user
	int year; //year to be entered by the user

	printf("Welcome to a program that calculates the day of the week in which you were born.\n"); //prompt message

	printf("Please enter the day you were born:\n"); //prompt message asking for the day user was born 
	scanf("%d", &days); //read an integer

	printf("Please enter the month you were born:\n"); //prompt message asking for month user was born 
	scanf("%d", &month); //read an integer

	printf("Please enter the year you were born:\n"); //prompt message asking for year user was born 
	scanf("%d", &year); //read an integer

	birthdayDay(days, month, year); //calling birthdayDay function

}
//birthdayDay function definition
int birthdayDay(int days, int month, int year)
{	
	int h; //stating integer variable 

	//convert January and February to month 13 and 14 respectively as specified by Zeller’s Congruence Algorithm
	if (month == 1 || month == 2)	
	{
		month += 12;
	}
	//calculating 'h' using  Zeller’s Congruence Algorithm
	h = (days + ((13*(month+1))/5) + year%100 + ((year%100)/4) + ((year/100)/4) - 2*(year/100))%7;

	//this if statement solves the problem for those people who were born on the year 2000 onwards
	if (year/100 >= 20)
	{
		if (h == 0)
		{
			h = 6;
		}
		else h -= 1;
	}

	printf("You were born on ");//prompt message 
	
	if (h == 0)
	{
		printf("Saturday\n"); //for h=0 print Saturday
	}
	if (h == 1)
	{
		printf("Sunday\n");//for h=1 print Sunday
	}
	if (h == 2)
	{
		printf("Monday\n");//for h=2 print Monday
	}
	if (h == 3)
	{
		printf("Tuesday\n");//for h=3 print Tuesday
	}
	if (h == 4)
	{
		printf("Wednesday\n");//for h=4 print Wednesday
	}
	if (h == 5)
	{
		printf("Thursday\n");//for h=5 print Thursday
	}
	if (h == 6)
	{
		printf("Friday\n");//for h=6 print Friday
	}
	return 0;
}
