/*LAB 8 QUESTION 3    Written by Er Lin
Program calculates the average number from an array entered by the user
using calloc and realloc to create the array and manage the array if user wants to enter mmore numbers.*/
#include <stdio.h>
#include <stdlib.h>

int main(void)//main function
{
  int numbType, elements;

  //prompt message introducing the program
  printf("\nWelcome to a program to calculate the average of the elements enter by the user.\n");

  //do-while loop asking user for type of elements (int or float)
  //loop ensuring only valid inputs is accepted
  do {
    printf("Please state what type of numbers are to be used (integer = 0, float = 1)\n");
    scanf("%d", &numbType);
  } while(numbType != 0 && numbType != 1 );

  //prompt message asking for number of elements to enter
  printf("How many elements do you wish to store in the array:\n");
  scanf("%d", &elements);

  if (numbType == 0) //if integer type is selected
  {
    int *array;
    int sum = 0;
    float average = 0;

    array = (int*) calloc(elements, sizeof(int)); //creating memory for integer array

    //if memory cannot be created, prompt error message and exit
    if (array == NULL)
    {
      printf("ERROR! Memory not allocated.");
      return 0;
    }
    else
    {
      //ask user to enter all elements of the integer array
      printf("Enter %d integers into the array: \n", elements);
      for (size_t i = 0; i < elements; i++)
      {
        scanf("%d", &array[i]);
        sum += array[i]; //calculating sum of all the elements
      }
      average = (float) sum/elements; //calculate the average of all elements
      printf("The average of the numbers entered is: %.2f.\n", average);

      //ask user if there are more elements to add to the array
      do {
        printf("Do you want to add more elements? (YES = 1, NO = 0)\n");
        scanf("%d", &numbType);

        if (numbType == 1) //if more elements have to be added:
        {
          int extraElements = 0;

          //ask user how many extra elements
          printf("How many more elements?\n");
          scanf("%d", &extraElements);

          array = (int*) realloc(array, extraElements*sizeof(int)); //reallocate memory

          //ask user to enter the extra elements
          printf("Enter %d extra elements into the array:\n", extraElements);
          for (size_t i = 0; i < extraElements; i++)
          {
            scanf("%d", &array[i]);
            sum += array[i]; //calculating sum of elements
          }
          elements += extraElements;
          average = (float) sum/elements; //calculating average
          printf("The average of the numbers entered is: %.2f\n", average);
        }
      } while(numbType == 1);
    }
  }
  else //if float type is selected
  {
    float *array;
    float sum = 0;
    float average = 0;

    array = (float*) calloc(elements, sizeof(float));
    //if memory cannot be created, prompt error message and exit
    if (array == NULL)
    {
      printf("ERROR! Memory not allocated.");
      return 0;
    }
    else
    {
      //ask user to enter all elements of the integer array
      printf("Enter %d integers into the array: \n", elements);
      for (size_t i = 0; i < elements; i++)
      {
        scanf("%f", &array[i]);
        sum += array[i]; //calculating sum of all the elements
      }
      average = sum/elements; //calculate the average of all elements
      printf("The average of the numbers entered is: %.2f.\n", average);

      //ask user if there are more elements to add to the array
      do {
        printf("Do you want to add more elements? (YES = 1, NO = 0)\n");
        scanf("%d", &numbType);

        if (numbType == 1) //if more elements have to be added:
        {
          int extraElements = 0;

          //ask user how many extra elements
          printf("How many more elements?\n");
          scanf("%d", &extraElements);

          array = (float*) realloc(array, extraElements*sizeof(float)); //reallocate memory

          //ask user to enter the extra elements
          printf("Enter %d extra elements into the array:\n", extraElements);
          for (size_t i = 0; i < extraElements; i++)
          {
            scanf("%f", &array[i]);
            sum += array[i]; //calculating sum of elements
          }
          elements += extraElements;
          average = (float) sum/elements; //calculating average
          printf("The average of the numbers entered is: %.2f\n", average);
        }
      } while(numbType != 0);
    }
  }
}
