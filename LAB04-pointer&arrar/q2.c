/*LAB 4 QUESTION 2     Written by ER LIN
Program that takes integer as parameter, if it is prime, it calculates the square of the number*/
#include <stdio.h>

//function prototypes
void primeByRef(int *i); //calculating the square passing by reference
int primeByVal(int i); //calculating the square passing by value

int main(void)//main function
{
  int n; //number to be entered by the user

  printf("Welcome to a program that calculates the square of prime numbers.\n"); //prompt message
  printf("Please enter a number to get the square of:\n"); //prompt message asking user to enter number
  scanf("%d", &n); //read an integer

  printf("The value of n is: %d\n",primeByVal(n)); //calling pass by value function
  primeByRef(&n); //calling pass by reference function

  return 0;
}
//pass by reference function definition
void primeByRef(int *i)
{
  int j;
  //for loop to check if the number entered by user is prime
  for (j = 2; j < *i; j++)
  {
    if (*i%j == 0)
    {
      printf("The new value of n is: 0\n"); //if not prime print 0 and exit.
      break;
    }
  }
  if (j == *i) //if the number is prime
  {
    //print the number squared
    printf("The new value of n is: %d\n", *i * *i);
  }
}
//pass by value function definition
int primeByVal(int i)
{
  int j;
  //for loop to check if the number entered by user is prime
  for (j = 2; j < i; j++)
  {
    if (i%j == 0)
    {
      return 0; //if not prime then return 0
    }
  }
  if (j == i) //if the number is prime
  {
    return i * i; //return the number squared
  }
  return 0;
}
