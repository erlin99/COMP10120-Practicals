/*LAB 4 QUESTION 3     Written by ER LIN
Program to demonstrate the address structure in arrays.*/
#include <stdio.h>
#include "q3-addressOfArrays.h" //including function definition from another file (addressOfArrays)
#include "q3-oneDimensional.h" //including function definition form another file (oneDimensional)
#define SIZE 2

int main(void)//main function
{
  //one dimensional arrays
  int intA[SIZE];
  float floatA[SIZE];
  double doubleA[SIZE];
  char charA[SIZE];

  //two dimensional arrays
  int intB[SIZE][SIZE];
  float floatB[SIZE][SIZE];
  double doubleB[SIZE][SIZE];
  char charB[SIZE][SIZE];

  //addresses of each of the one-dimensional arrays
  // printf("ADDRESSES OF ONE-DIMENSIONAL ARRAYS\n");
  // addressOfArrays(intA, floatA, doubleA, charA);

  //addresses of each of the two-dimensional arrays
  printf("\nADDRESSES OF TWO-DIMENSIONAL ARRAYS\n");
  // addressOfArrays(intB, floatB, doubleB, charB);
  printf("Address of integer type array: %p\n", intB);
  printf("Address of float type array: %p\n", floatB);
  printf("Address of double type array: %p\n", doubleB);
  printf("Address of char type array: %p\n", charB);

  //address of each element in one dimensional array
  // printf("\nADRESSES OF ELEMENTS IN ONE-DIMENSIONAL ARRAY\n");
  // oneDimensional(intA, floatA, doubleA, charA);

  //address of each element in two dimensional arrays
  printf("\nADRESSES OF ELEMENTS IN TWO-DIMENSIONAL ARRAY\n");
  int i, j, k;
  //display adresses of elements from integer type array
  printf("Integer Array:\n");
  k = 1;
  for (i = 0; i < SIZE; i++) //controlling rows
  {
    for (j = 0; j < SIZE; j++) //controlling columns
    {
      printf("Element %d address is: %p\n", k, &intB[i][j]);
      k++;
    }
  }
  //display adresses of elements from float type array
  printf("Float Type Array:\n");
  k = 1;
  for (i = 0; i < SIZE; i++) //controlling rows
  {
    for (j = 0; j < SIZE; j++) //controlling columns
    {
      printf("Element %d address is: %p\n", k, &floatB[i][j]);
      k++;
    }
  }
  //display adresses of elements from double type array
  printf("Double Type Array:\n");
  k = 1;
  for (i = 0; i < SIZE; i++) //controlling rows
  {
    for (j = 0; j < SIZE; j++) //controlling columns
    {
      printf("Element %d address is: %p\n", k, &doubleB[i][j]);
      k++;
    }
  }
  //display adresses of elements from char type array
  printf("Char Type Array:\n");
  k = 1;
  for (i = 0; i < SIZE; i++) //controlling rows
  {
    for (j = 0; j < SIZE; j++) //controlling columns
    {
      printf("Element %d address is: %p\n", k, &charB[i][j]);
      k++;
    }
  }
  return 0;
}
