/*LAB 7 QUESTION 3    Written by Er Lin
Program that jumble the words, prints the words, and selects a random word our of a pointers array*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 12

void jumbleWords(int n[]); //prototype of function to shuffle the words
void printWords(char **myArray, int n[]); //prototype of function to print out the shuffled words
void randomWord(char **myArray); //prototype of functions to pick a random word

//main function
int main(void)
{
  //array of strings
  char *myArray[MAX] = {"COMP1020", "is", "my", "favourite", "module", "and", "I", "learn", "lots", "of", "interesting", "things"};

  int n[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

  //prompt message introducing the program
  printf("\nWelcome to a program that shuffles and prints an array of strings and picks a random word.\n");

  //display the original array of strings
  printf("The array is:\n");
  printWords(myArray, n); //calling function to print array

  //display the shuffled array of strings
  printf("The shuffled array is:\n");
  jumbleWords(n);//calling function to shuffle
  printWords(myArray, n);//calling function to print array

  //display a random word
  printf("The random word is:\n");
  randomWord(myArray); //calling function to pick random word

  printf("\n");
}
//function definition to shuffle the words
void jumbleWords(int n[])
{
  srand(time(NULL));

  //for loop to implement the shuffling algorithm
  for (size_t i = 0; i < MAX; i++)
  {
    int j = rand()%(i+1); //generate a random number between 0 and i

    //swap position i and j from the array
    int temp = n[i];
    n[i] = n[j];
    n[j] = temp;
  }
}
//function definition to print out the shuffled words
void printWords(char **myArray, int n[])
{
  //for loop to print out the shuffled elements of the array
  for (size_t i = 0; i < MAX; i++)
  {
    printf("%s ", myArray[n[i]]);
  }
  printf("\n");
}
//function definition to pick up a random word
void randomWord(char **myArray)
{
  int i = rand()%MAX; //generate a random number
  printf("%s\n", myArray[i]); //print out the i element of the array of strings
}
