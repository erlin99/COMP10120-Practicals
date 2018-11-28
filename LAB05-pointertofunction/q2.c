/*LAB 5 QUESTION 2    Written by Er Lin
Program that receives an integer array as a parameter and modifies the array elements by multiplying each one by 10*/
#include <stdio.h>

int main(void) //main function
{
  int array[] = {2,4,6,8,10,12,14,16,18,20}; //definiton of array
  int arraySize = sizeof(array)/sizeof(int); //calculation of the size of the array
  int *arrayPtr = array; //create arrayPtr and point to array

  printf("\nWelcome to a program that multiplies the elements in an array by 10\n");
  printf("Your array of integers is:\n"); //informing user of the current integer array elements
  //for loop to display the integers in the array
  for (size_t i = 0; i < arraySize; i++)
  {
    printf("%d  ", *(arrayPtr + i));
  }

  //display the new array with the integers multiplied by 10
  printf("\n\nThe new array is:\n");
  //for loop to modified elements in the array multiplied by 10
  for (size_t i = 0; i < arraySize; i++)
  {
    *(arrayPtr + i) = *(arrayPtr + i) * 10;
  }
  //for loop to display the new modified arrya
  for (size_t i = 0; i < arraySize; i++)
  {
    printf("%d  ", *(arrayPtr+i));
  }
  printf("\n");

  return 0;
}
