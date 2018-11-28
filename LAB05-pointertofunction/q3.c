/*LAB 5 QUESTION 3    Written by Er Lin
Program that receives a character array as a parameter and
modifies the array elements by converting each to an uppercase letter.*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) //main function
{
  char array[80]; //character array
  char *arrayPtr = array; //initialize pointer to point the array

  printf("\nWelcome to a program that modifies the string entered to uppercase letters.\n");
  printf("Please enter a string:\n"); //asking user to enter a string
  fgets(array, 80, stdin); //read in a string from the command line

  //remove '\n' and replace with '\0' at end of the string
  array[strlen(array)-1] = '\0';

  //while loop to convert all the letters in the string to uppercase
  while (*arrayPtr != '\0')
  {
    *arrayPtr = toupper(*arrayPtr);
    arrayPtr++; //increase pointer to point to the next location
  }
  //diplay the new string
  printf("\nThis is the new string:\n");
  printf("%s\n\n", array);

  return 0;
}
