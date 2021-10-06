
#include <iostream>
#include "Rectangle.h"

using std::cout;
using std::cin;

double length, width;
Rectangle newRectangle;

int main()
{
    cout << "This Program Calculates the Area of a Rectangle Given its Length and Width in meters\n";
    cout << "Enter the Length of the Rectangle: ";
    cin >> length;
    cout << "Enter the Width of the Rectangle: ";
    cin >> width;
    cout << "The Area of the Rectangle is " << newRectangle.area(length, width) << "meters.";
}
