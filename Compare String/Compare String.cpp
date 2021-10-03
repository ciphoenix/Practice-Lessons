#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;



int main()
{
	string firstString;
	string secondString;
	bool goAgain = true;

	while (goAgain)
	{
		cout << "Enter a phrase: ";
		getline(cin, firstString);
		cout << "You entered " << "\"" << firstString << "\"" << ". Enter another phrase: ";
		getline(cin, secondString);

		if (firstString.length() > secondString.length())
		{
			cout << "The first phrase, " << "\"" << firstString << "\"" << ", is longer than the second phrase, " << "\"" << secondString << "\"" << ".\n";
		}
		if (secondString.length() > firstString.length())
		{
			cout << "The second phrase, " << "\"" << secondString << "\"" << ", is longer than the first phrase, " << "\"" << firstString << "\"" << ".\n";
		}
		if (firstString.length() == secondString.length())
		{
			cout << "The first phrase, " << "\"" << firstString << "\"" << ", is the same length as the second phrase, " << "\"" << secondString << "\"" << ".\n";
		}

		cout << "Would you like to compare another phrase? 0 for No and any other number for Yes: ";
		int answer;
		cin >> answer;
		if (answer == 0)
		{
			goAgain = false;
		}
		if (answer > 0)
		{
			goAgain = true;
		}
	}
	return 0;
}