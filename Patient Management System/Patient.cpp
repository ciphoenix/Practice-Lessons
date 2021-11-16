#include <iostream>
#include "Patient.h"

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

void Patient::getVitals()
{
	cout << "Temperature: " << Temperature << endl;
	cout << "Blood Pressure: " << SystolicBP << "/" << DiastolicBP << endl;
	cout << "Pulse Rate: " << PulseRate << endl;
	cout << "Respiratory Rate: " << RespiratoryRate << endl;
}

void Patient::AddReviewNote()
{
	string NewNote;
	cout << "Write out your review note. Press 'TAB' to Submit:" << endl;
	std::getline(std::cin, NewNote, '\t');
	std::cin.ignore();
	ReviewNotes.push_back(NewNote);
}

void Patient::PrintLastReview()
{
	cout << ReviewNotes[ReviewNotes.size()] << endl;
}