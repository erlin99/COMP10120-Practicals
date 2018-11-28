/*LAB 10 QUESTION 2    Written by Er Lin
Program that demonstrates function overloading creating 4 functions that calculates
the average of 2 numbers.*/
#include <iostream>
using namespace std;

//function averageOfTwo for int values
int averageOfTwo(int x, int y)
{
  cout << "Integer average of " << x << " and " << y << " = ";
  return (x + y)/2;
}
//function averageOfTwo for long values
long averageOfTwo(long x, long y)
{
  cout << "Long average of " << x << " and " << y << " = ";
  return (x + y)/2;
}
//function averageOfTwo for float values
float averageOfTwo(float x, float y)
{
  cout << "Float average of " << x << " and " << y << " = ";
  return (x + y)/2;
}
//function averageOfTwo for float values
double averageOfTwo(double x, double y)
{
  cout << "Double average of " << x << " and " << y << " = ";
  return (x + y)/2;
}

int main()
{
  //depending on the types of integers entered, the program will know which function to use.
  //I had to force the third call to have float values, otherwise it would just run the double function
  //instead of the float.
  cout << '\n' << "Program that calculates the average of 2 numbers. Showing function overloading." << endl;
  cout << averageOfTwo(7, 8) << endl;
  cout << averageOfTwo(7000000000, 8000000000) << endl;
  cout << averageOfTwo((float)0.7, (float)0.3) << endl;
  cout << averageOfTwo(1.4123456789, 2.4356721456) << endl;
  cout << endl;
}
