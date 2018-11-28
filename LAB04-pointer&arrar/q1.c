/*LAB 4 QUESTION 1     Written by ER LIN
Program that takes a number as an input parameter and prints its multiplication table up to 15. */
#include <stdio.h>

void multiplicationTable(int n); //prototype of multiplication table function

int main(void) //main function
{
  int number; //number to be entered by the user

  printf("Welcome to program that prints the multiplication table of a number up to 15.\n"); //prompt message
  printf("Enter a value:\n"); //prompt message asking for number
  scanf("%d", &number);//reads an integer

  multiplicationTable(number); //calling multiplication table function
}
//multiplication table function definition
void multiplicationTable(int n)
{
  //for loop to print out multiplication table
  for (int i = 1; i <= 15; i++)
  {
    printf("%d x %d = %d\n", n, i, n*i);
  }
}
