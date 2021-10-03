#include <iostream>

using std::cout;
using std::cin;

int main()
{

	bool keepgoing = true;
	int answer = 1;
	int secretNumber = 25;
	int number; // Declare variable

	cout << "Welcome to Joshua's guessing game.\n";
	cout << "Guess the secret number: "; // Prompt user for input
	cin >> number; // save input to variable

	while (keepgoing) // Check correctness of guess
	{
		if (number > secretNumber)
		{
			cout << "Too High! Try again: ";
			cin >> number;
		}
		if (number == secretNumber)
		{
			cout << "Congratulations! You guessed correctly. Thank you for playing";
			answer = 0;
		}
		if (number < secretNumber)
		{
			cout << "Too Low! Try again: ";
			cin >> number;
		}

		if (answer == 0)
		{
			keepgoing = false;
		}

	}
	return 0;
}
