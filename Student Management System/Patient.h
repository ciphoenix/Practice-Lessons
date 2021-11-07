#pragma once
#include <string>
using std::string;

class Patient
{
	
	int serialNumber;
	string firstName;
	string lastName;
	string address;
	char gender;
	int age;
	string occupation;
	
public:
	void getData();


	Patient(int ID, string FirstName, string LastName, string Address, char	Gender, int Age, string Occupation) 
	{
		serialNumber = ID;
		firstName = FirstName;
		lastName = LastName;
		address = Address;
		gender = Gender;
		age = Age;
		occupation = Occupation;
	}

};

