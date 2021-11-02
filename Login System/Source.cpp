#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::endl;

int serialNumber = 1;
int recordIndex;

vector<string> usernames = { "defaultName" };
vector<string> passwords = { "defaultPass" };

bool isLoggedIn(string un, string pw);
void createAccount();
void loginAccount();



int main()
{
	int choice;
	cout << "1: Set up an account" << endl << "2: Sign in to your account" << endl << "what would you like to do: ";
	cin >> choice;
	switch (choice)
	{
		case 1:
			createAccount();
			system("cls");
			break;
		case 2:
			loginAccount();
			system("cls");
			break;
		default:
			cout << "invalid entry";
	}

	return 0;

}

bool isLoggedIn(string un, string pw)
{
	if (un == usernames[recordIndex] && pw == passwords[recordIndex])
	{
		return true;
	}
	else
		return false;
}

void createAccount()
{
	string username, password;
	cout << "Your serial number is " << serialNumber << endl;
	cout << "Enter your username: ";
	cin >> username;
	usernames.push_back(username);
	cout << "Enter your password: ";
	cin >> password;
	passwords.push_back(password);
	

	cout << "Would you like to create another account? Y/N: ";
	char resp;
	cin >> resp;
	if (resp == 'Y')
	{
		serialNumber++;
		createAccount();
	}
	else
		loginAccount();
}

void loginAccount()
{
	string username, password;
	cout << "Enter your serial Number: ";
	cin >> recordIndex;
	cout << "Welcome." << endl << "Please enter your username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	system("cls");
	if (isLoggedIn(username, password) == true)
	{

		cout << "Welcome " << usernames[recordIndex] << endl;
		system("pause>0");
	}
	else
		cout << "Wrong username or password";
}
