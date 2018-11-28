/*LAB 2 QUESTION 4 		Written by: ER LIN
Program that converts decimal to binary numbers(base-10 to base-2)*/
#include <stdio.h>

long long base10to2 (int base10_number); //prototype for base10to2 function 

int main(void) //main function
{
	int base10_number; //number in decimal to be entered by user

	printf("Welcome to a base 10 to 2 number calculator.\n"); //prompt message
	printf("Please enter the number in decimal that you want to convert:\n");//prompt message asking for decimal number
	scanf("%d", &base10_number);//read an integer

	printf("%lld\n", base10to2(base10_number)); //calling base10to2 function
}	
//base10to2 fucntion definition
long long base10to2 (int base10_number)
{
	int mod = base10_number % 2; // decimal number mod 2
	int div = base10_number / 2; // decimal number divided by 2

	//in the case of decimal number=0:
	if (base10_number == 0)
		return 0;
	//in the case of any other number:
	else return (mod + 10 * base10to2(div));
}