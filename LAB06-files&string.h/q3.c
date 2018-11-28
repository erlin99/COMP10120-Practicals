/*LAB 6 QUESTION 3    Written by Er Lin
Program which demonstrates copying the string below to a new string using pointer notation.*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void printArray(char *slogan); //function protoype to print original and old string

int main(void)//main function
{
  char *slogan = "Comp10120 is my favourite modules"; //original string
  printf("Welcome to a program to display string with no consonants and uppercase.\n"); //prompt message introducing the program

  printArray(slogan); //calling function
}
//function definition to print original and old string
void printArray(char *slogan)
{
  char newString[strlen(slogan)]; //for the new string

  int i = 0;
  int j = 0;

  //display the original string
  printf("\nOriginal String:\n");
  printf("%s\n\n", slogan);

  //display new string
  printf("New String:\n");
  //new string will only contain uppercase vowels + numbers
  //while loop to create the new string with only the uppercase vowels, numbers and spaces.
  while (slogan[i] != '\0')
  {
    if (slogan[i] == 'a' || slogan[i] == 'e' || slogan[i] == 'i' || slogan[i] == 'o' || slogan[i] == 'u')
    {
      newString[j] = toupper(slogan[i]);
      j++;
    }
    else if (slogan[i] == 'A' || slogan[i] == 'E' || slogan[i] == 'I' || slogan[i] == 'O' || slogan[i] == 'U')
    {
      newString[j] = (slogan[i]);
      j++;
    }
    else if (slogan[i] == ' ' || (slogan[i] >= 48 && slogan[i] <= 57))
    {
      newString[j] = (slogan[i]);
      j++;
    }
    i++;
  }
  newString[j] = '\0'; //adding null terminator at the end of the string to avoid trash values
  printf("%s\n\n", newString); //print out the new string
}
