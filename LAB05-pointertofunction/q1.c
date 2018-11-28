/*LAB 5 QUESTION 1    Written by Er Lin
Program that reverses an array or mixes the elements in the array randomly depending on the user input*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void reverseArray(int arraySize, int a[]); //prototype of function to reverse array
void randomiseArray(int arraySize, int a[]); //prototype of function to mix order of elements in array
void printArray(int arraySize, int a[], void (*arrayFunction)(int arraySize, int a[])); //prototype of function to print the modified array

int main(void) //main function
{
  int myArray[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; //array containing integers
  int arraySize = sizeof(myArray) / sizeof(int); //calculation of the array's size
  int type;

  printf("Welcome to program that reverses an array or mixes the order of the elements.\n");
  printf("Your array of integers is: "); //prompt message to inform user of current array
  //for loop to print out current array
  for (size_t i = 0; i < arraySize; i++)
  {
    printf("%d  ", myArray[i]);
  }

  //prompt message to ask user which operation to perform
  printf("\nEnter 0 to reverse the array, else enter 1 to mix the numbers.\n");
  goback: scanf("%d", &type); //reads an integer

  //if 0 is entered print reversed array
  if (type == 0)
  {
    printf("The reversed array is:\n");
    printArray(arraySize, myArray, reverseArray);
  }
  //if 1 is entered print the array with numbers mixed randomly
  else if (type == 1)
  {
    printf("The randomised array is:\n");
    printArray(arraySize, myArray, randomiseArray);
  }
  //if different number entered, print warning message asking to enter a number available
  else
  {
    printf("Please enter 0 or 1 !!\n");
    goto goback; //go back to return point
  }
  printf("\n");

  return 0;
}
//function definition to reverse the array
void reverseArray(int arraySize, int a[])
{
  int temp;
  int end = arraySize-1;
  //swap first element with the last one and after each iteration move closer to the middle of the array
  for (size_t i = 0; i < arraySize/2; i++)
  {
    temp = a[i];
    a[i] = a[end];
    a[end] = temp;
    end--;
  }
}
//function definition to mix elements in the array
void randomiseArray(int arraySize, int a[])
{
  srand(time(NULL)); //initialization of the random number generator
  int temp;
  //for loop implementing fisher-yates shuffling algorithm
  for (size_t i = 1; i < arraySize; i++)
  {
    int j = rand()%(i+1); //select random integer between 0 and i
    //if this random integer is not the same as i, swap element j and i
    if(j != i)
    {
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }
}
//function definition for printing out the modified array
void printArray(int arraySize, int a[], void (*arrayFunction)(int arraySize, int a[]))
{
  (*arrayFunction)(arraySize, a); //calling one of the 2 functions
  for (size_t i = 0; i < arraySize; i++)
  {
    printf("%d  ", a[i]);
  }
}
