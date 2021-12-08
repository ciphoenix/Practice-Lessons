/* Get day of the week from the date given */

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int* saveDate(int day, int month, int year);
string getDayOfWeek(int* date);

string WeekDay[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


int main()
{

	int day, month, year;
	cout << "Enter a date separated by spaces: ";
	cin >> day >> month >> year;
	int* date = saveDate(day, month, year);

	cout << "The day is a " << getDayOfWeek(date);
}

int* saveDate(int day, int month, int year)
{
	static int date[3];
	date[0] = day;
	date[1] = month;
	date[2] = year;

	return date;
}

string getDayOfWeek(int* date)
{
	int DayIndex;
	int day = date[0];
	int month = date[1];
	int year = date[2];

	month -= 2;
	if (month < 1)
	{
		month += 12;
		--year;
	}

	// Get Day Index usiing formula based on Zeller's Congruence

	DayIndex = ((26 * month - 2) / 10 + day + (year % 100) + (year % 100) / 4 + (year / 100) / 4 + 5 * (year / 100)) % 7;

	return WeekDay[DayIndex];
}