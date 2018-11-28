/*LAB 8 QUESTION 1    Written by Er Lin
Program that shows the behaviour of a union.*/
#include <stdio.h>

//union definition
union example{
  char a;
  short b;
  int c;
  long d;
};

int main(void) //main function
{
  union example eg; //define union variable

  //prompt message asking for a character and scanning it
  printf("Enter a character: ");
  scanf("%c", &eg.a);

  //prompt message asking for a short integer and scanning it
  printf("Enter a number of type 'short': ");
  scanf("%hi", &eg.b);

  //prompt message asking for an integer and scanning it
  printf("Enter a number of type 'int': ");
  scanf("%d", &eg.c);

  //prompt message asking for a long integer and scanning it
  printf("Enter a number of type 'long': ");
  scanf("%ld", &eg.d);

  //prompt message displaying the size of the union in bytes
  printf("The size of the union is %lu bytes\n", sizeof(eg));

  //prompt messages displaying the different variables entered by user
  printf("Character: %c\n", eg.a);
  printf("Short Integer: %hi\n", eg.b);
  printf("Integer: %d\n", eg.c);
  printf("Long Integer: %ld\n", eg.d);
}
/*The union's size in bytes corresponds to the size of the largest member, this suggests that
all the members inside the union share the same storage.

This is why the final output will depend in the last member that is filled with a value.

Because this last one will occupy the only space available and therefore overwrite the
value that was previously entered.

In the case of my code, the last value entered is a 'long integer', therefore the final output
will be charracter: (corresponding character to the number in ASCII),
and for the other three it will be the value of 'long'. If the long number is too big,
when short is printed, it will be represented as a negative number.*/
