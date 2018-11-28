/*LAB 4 QUESTION 4     Written by ER LIN
Program which prints the size (in bytes) of the following variables to the screen:
char, int, long, long long, double, long double, float, an array of integers, a pointer to an array*/
#include <stdio.h>

int main(void)
{
  //establishing all variable types
  char a;
  int b;
  long c;
  long long d;
  double e;
  long double f;
  float g;
  int array[5];
  int *Ptr = array;

  //printing out the size in bytes of each variable
  printf("The size(in bytes) of char is %d byte.\n", sizeof(a));
  printf("The size(in bytes) of int is %d bytes.\n", sizeof(b));
  printf("The size(in bytes) of long is %d bytes.\n", sizeof(c));
  printf("The size(in bytes) of long long is %d bytes.\n", sizeof(d));
  printf("The size(in bytes) of double is %d bytes.\n", sizeof(e));
  printf("The size(in bytes) of long double is %d bytes.\n", sizeof(f));
  printf("The size(in bytes) of float is %d bytes.\n", sizeof(g));
  printf("The size(in bytes) of integer array of 5 elements is %d bytes.\n", sizeof(array));
  printf("The size(in bytes) of pointer to the integer array is %d bytes.\n", sizeof(*Ptr));

  return 0;
}
