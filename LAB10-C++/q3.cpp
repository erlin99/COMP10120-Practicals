/*LAB 10 QUESTION 3    Written by Er Lin
Program that calculates the area of different shapes wehre they are given defaul values,
but they can also change them. */
#include <iostream>
#include <iomanip>
#define PI 3.14159265359

//function prototypes for areas with default arguments.
float triangleArea(float height = 1.0, float base = 2.3);
float squareArea(float side = 10);
float rectangleArea(float height, float length = 20);
float rhombusArea(float diagonal1 =10.2, float diagonal2 = 3.8);
float circleArea(float radius = 3.6);
float trapezoidArea(float height, float base1, float base2 = 8);

int main()
{
  int yesOrNo;
  int choice; //user's choice

  std::cout << std::setprecision(2) << std::fixed; //set ouput to 2 decimal places.

  //ask user which shape they want to do.
  std::cout << '\n' << "What shape area would you like to calculate: " << '\n';
  std::cout << "1. Triangle" << '\t' << "2. Square" << '\n' << "3. Rectangle" << '\t';
  std::cout << "4. Rhombus" << '\n' << "5. Circle" << '\t' << "6. Trapezoid" << '\n' << "Your choice: ";

  std::cin >> choice;//user's choice
  //make sure valid input
  while (choice > 6 || choice <= 0)
  {
    std::cout << "Enter a valid INPUT!" << '\n';
    std::cin >> choice;
  }
  if (choice == 1) //triangleArea
  {
    //prompt default values and change if user's want
    std::cout << '\n' << "Default values: height = 1, base = 2.3" << '\n';
    std::cout << "Do you want to change them? (YES = 1, NO = 0)" << '\n';
    std::cin >> yesOrNo;
    if (yesOrNo == 1) //if yes ask for new numbers
    {
      float height, base;
      //read in new valuse from user
      std::cout << "Height: "; std::cin >> height;
      std::cout << "Base: "; std::cin >> base;
      std::cout << "The area of the triangle is: " << triangleArea(height, base) << '\n';
    }
    else { //if no
      std::cout << "The area of the triangle is: " << triangleArea() << '\n';
    }
  }
  else if (choice == 2) //squareArea
  {
    //prompt default values and change if user's want
    std::cout << '\n' << "Default value: side = 10" << '\n';
    std::cout << "Do you want to change this value? (YES = 1, NO = 0)" << '\n';
    std::cin >> yesOrNo;
    if (yesOrNo == 1) //if yes ask for new numbers
    {
      float side;
      //read in new value from user
      std::cout << "Side: "; std::cin >> side;
      std::cout << "The area of the square is: " << squareArea(side) << '\n';
    }
    else { //if no
      std::cout << "The area of the square is: " << squareArea() << '\n';
    }
  }
  else if (choice == 3) //rectangleArea
  {
    //prompt default values and change if user's want
    std::cout << '\n' << "Default value: length = 20" << '\n';
    std::cout << "Do you want to change this value? (YES = 1, NO = 0)" << '\n';
    std::cin >> yesOrNo;

    //read in the height
    float height;
    std::cout << "Height: "; std::cin >> height;

    if (yesOrNo == 1) //if yes ask for new numbers
    {
      float length;
      //read in new value from user
      std::cout << "Length: "; std::cin >> length;
      std::cout << "The area of the rectangle is: " << rectangleArea(height, length) << '\n';
    }
    else { //if no
      std::cout << "The area of the triangle is: " << rectangleArea(height) << '\n';
    }
  }
  else if (choice == 4) //rhombusArea
  {
    //prompt default values and change if user's want
    std::cout << '\n' << "Default value: diagonal1 = 10.2, diagonal2 = 3.8" << '\n';
    std::cout << "Do you want to change these values? (YES = 1, NO = 0)" << '\n';
    std::cin >> yesOrNo;

    if (yesOrNo == 1) //if yes ask for new numbers
    {
      float diagonal1, diagonal2;
      //read in new value from user
      std::cout << "Diagonal1: "; std::cin >> diagonal1;
      std::cout << "Diagonal2: "; std::cin >> diagonal2;
      std::cout << "The area of the rhombus is: " << rhombusArea(diagonal1, diagonal2) << '\n';
    }
    else { //if no
      std::cout << "The area of the rhombus is: " << rhombusArea() << '\n';
    }
  }
  else if (choice == 5) //circleArea
  {
    //prompt default values and change if user's want
    std::cout << '\n' << "Default value: radius = 3.6" << '\n';
    std::cout << "Do you want to change this value? (YES = 1, NO = 0)" << '\n';
    std::cin >> yesOrNo;

    if (yesOrNo == 1) //if yes ask for new numbers
    {
      float radius;
      //read in new value from user
      std::cout << "Radius: "; std::cin >> radius;
      std::cout << "The area of the circle is: " << circleArea(radius) << '\n';
    }
    else { //if no
      std::cout << "The area of the circle is: " << circleArea() << '\n';
    }
  }
  else //trapezoidArea
  {
    //prompt default values and change if user's want
    std::cout << '\n' << "Default value: base2 = 8" << '\n';
    std::cout << "Do you want to change this value? (YES = 1, NO = 0)" << '\n';
    std::cin >> yesOrNo;

    //read in the height and the base from the user's input
    float height, base1;
    std::cout << "Height: "; std::cin >> height;
    std::cout << "Base1: "; std::cin >> base1;

    if (yesOrNo == 1) //if yes ask for new numbers
    {
      float base2;
      //read in new value from user
      std::cout << "Base2: "; std::cin >> base2;
      std::cout << "The area of trapezoid is: " << trapezoidArea(height, base1, base2) << '\n';
    }
    else { //if no
      std::cout << "The area of the trapezoid is: " << trapezoidArea(height, base1) << '\n';
    }
  }

}

//function definitions to calculate area of each of the shapes.
float triangleArea(float height, float base)
{
  return 0.5 * base * height;
}
float squareArea(float side)
{
  return side * side;
}
float rectangleArea(float height, float length)
{
  return height * length;
}
float rhombusArea(float diagonal1, float diagonal2)
{
  return 0.5 * diagonal1 * diagonal2;
}
float circleArea(float radius)
{
  return PI * radius * radius;
}
float trapezoidArea(float height, float base1, float base2)
{
  return 0.5 * (base1 + base2) * height;
}
