/*LAB 3 QUESTION 1 		Written by: Er Lin
Program that reverses the order of any string inputted */
#include <stdio.h>
char* reverseString(char text[], int numberOfLetters); //prototype for reverseString function 

int main(void) //main function 
{
	char text[120]; //string to be entered by the user
	int numberOfLetters; //number of letters in string to be entered by the user 

	printf("Welcome to a program that reverses the order of any string inputted.\n");//prompt message 
	printf("Please write in the string.\n"); //prompr message asking user to input the string 
	scanf("%s", text); //read a string 

	printf("Please enter the number of letters in the string.\n"); //prompr message asking for number of letters in the string 
	scanf("%d", &numberOfLetters); //read an integer 

	reverseString(text, numberOfLetters); //calling reverseString function 
}
//reverseString function definition
char* reverseString(char text[], int numberOfLetters) 
{
	int i; //declaring variable to use in for loop 
	int temp; 
	int end = numberOfLetters - 1; 

	//for loop to reverse the elements in the string 
	for (i = 0; i < numberOfLetters/2; i++)
	{	
		temp = text[i];
		text[i] = text[end];
		text[end] = temp;

    	end--;
	}
	//give result back to the user 
	printf("%s\n", text);
	
	return 0;
}