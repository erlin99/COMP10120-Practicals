/*LAB 10 QUESTION 1    Written by Er Lin
Program that demonstrates function overloading creating 4 functions called addTwo
each has two arguments of the same type (floats, integers, doubles and longs) and
returns the two numbers added together.*/
#include <iostream>
using namespace std;

//function addTwo for int values
int addTwo(int x, int y)
{
  cout << "Integer: " << x << " + " << y << " = ";
  return x + y;
}
//function addTwo for long values
long addTwo(long x, long y)
{
  cout << "Long: " << x << " + " << y << " = ";
  return x + y;
}
//function addTwo for float values
float addTwo(float x, float y)
{
  cout << "Float: " << x << " + " << y << " = ";
  return x + y;
}
//function addTwo for float values
double addTwo(double x, double y)
{
  cout << "Double: " << x << " + " << y << " = ";
  return x + y;
}

int main()
{
  //depending on the types of integers entered, the program will know which function to use.
  //I had to force the third call to have float values, otherwise it would just run the double function
  //instead of the float.
  cout << addTwo(7, 8) << endl;
  cout << addTwo(7000000000, 8000000000) << endl;
  cout << addTwo((float)0.7, (float)0.3) << endl;
  cout << addTwo(1.4123456789, 2.4356721456) << endl;
}
