/*LAB 7 QUESTION 2    Written by Er Lin
Program that defines and uses 2 macros; one macro should print the elements of an
integer array and the other macro should print the elements in reverse order.*/
#include <stdio.h>

//macro to print out the elements of an array
#define PRINT_ARRAY(x) for(size_t i = 0; i < 5; i++){ printf("%d  ", x[i]);}

//macro to print out elements of an array in reverse order
#define REVERSE_ARRAY(x) for (int j = 4; j >= 0; j--) { printf("%d  ", x[j]);}

int main(void) //main function
{
  int myArray[5] = {1, 4, 8, 16, 32}; //integer array

  //display the integer array using macro
  printf("\nYour array is: ");
  PRINT_ARRAY(myArray);

  //display the reversed array using macro
  printf("\nThe Reverse array is: ");
  REVERSE_ARRAY(myArray);
  printf("\n\n");

  return 0;
}
