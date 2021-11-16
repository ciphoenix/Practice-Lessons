#pragma once
#include <string>
#include <vector>
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
	std::vector<string>  ReviewNotes;
	
	int PulseRate;
	int RespiratoryRate;
	float Temperature;
	int SystolicBP;
	int DiastolicBP;

public:
	void getData();
	void getVitals();
	void AddReviewNote();
	void PrintLastReview();


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

