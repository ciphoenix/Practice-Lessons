#include "Rectangle.h"

double Rectangle::area(double new_length, double new_width) // define the area method
{
	length = new_length;
	width = new_width;
	return length * width;
}