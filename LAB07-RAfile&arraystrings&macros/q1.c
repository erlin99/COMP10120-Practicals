/*LAB 7 QUESTION 1    Written by Er Lin
Program that defines and uses a macro which calculates the minimum of 2 integers.
Extended with another macro that calculates the minimum of 4 integers.*/
#include <stdio.h>

//macro to calculate minimum of 2 integers
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
//macro to calculate the minimum of 4 integers using "MIN" macro
#define MINIMUM_OF_4(a, b, c, d) (MIN((MIN(a, b)), (MIN(c, d))))

int main(void) //main function
{
  int a, b, c, d;
  printf("\nWelcome to a program to calculate the minimum of 4 integers.\n"); //prompt message introducing the program

  //prompt messages asking the user for the 4 integers
  printf("Please enter the 1st number:\n");
  scanf("%d", &a);

  printf("Please enter the 2nd number:\n");
  scanf("%d", &b);

  printf("Please enter the 3rd number:\n");
  scanf("%d", &c);

  printf("Please enter the 4th number:\n");
  scanf("%d", &d);

  //print result back to user
  printf("The minimum number is: %d\n", MINIMUM_OF_4(a, b, c, d));

  return 0;
}
