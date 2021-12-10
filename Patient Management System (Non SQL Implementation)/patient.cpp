#include "patient.h"
#include <iostream>

using std::cout;
using std::endl;


void Patient::getData()
{
	cout << "Hospital ID Number: " << serialNumber << endl;
	cout << "Name: " << firstName << " " << lastName << endl;
	cout << "Age: " << age << endl;
	cout << "Gender: " << gender << endl;
	cout << "Address: " << address << endl;
	cout << "Occupation: " << occupation << endl;
}