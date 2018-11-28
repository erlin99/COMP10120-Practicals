/*LAB 9 QUESTION 1    Written by Er Lin
Program that writes each struct to a binary file named customers.data*/
#include <stdio.h>

//structure definition
struct zip_cuts {
  int zip_code;
  int customer_count;
};

int main(void) //main function
{
  //2D array with data from customers
  int myCustomers [5][2] = {{86956, 1}, {36568, 3}, {006565, 0}, {999555, 22}, {85446, 88}};

  //intialize array of structs type zip_cuts
  struct zip_cuts customerData[5];

  FILE *filePtr; //pointer to the file

  //if file cannot be created print error message
  if ((filePtr = fopen("customers.dat", "wb")) == NULL)
  {
    printf("ERROR: files could not be created!\n");
  }
  else
  {
    int j = 0;

    //for loop to fill in struct and print to the customers.dat file
    for (size_t i = 0; i < 5; i++)
    {
      customerData[i].zip_code = myCustomers[i][j];
      customerData[i].customer_count = myCustomers[i][j+1];

      fprintf(filePtr, "%d %d\n", customerData[i].zip_code, customerData[i].customer_count);
    }
  }
  fclose(filePtr); //close file
}
