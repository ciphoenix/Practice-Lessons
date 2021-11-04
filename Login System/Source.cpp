#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>

using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::getline;
using std::fstream;

int serialNumber = 1;
int recordIndex;

vector<string> usernames = {};
vector<string> passwords = {};

bool isLoggedIn(string un, string pw);
void createAccount();
void loginAccount();
void begin();
bool readFiles();
void createFile();
void writeToFile();


int main()
{


	createFile();

	readFiles();
	
	begin();

	writeToFile();

	return 0;

}


void createFile()
{

	ifstream MyUsernames;
	ifstream MyPasswords;

	MyUsernames.open("usernames.txt");
	MyPasswords.open("passwords.txt");

	if (!MyPasswords && !MyUsernames)
	{
		fstream MyUsername("usernames.txt");
		fstream MyPasswords("passwords.txt");
	}


}

void writeToFile()
{
	ofstream MyUsernames;
	ofstream MyPasswords;
	MyUsernames.open("usernames.txt");
	MyPasswords.open("passwords.txt");
	for (int i = 0; i < usernames.size(); i++)
	{
		MyUsernames << usernames[i] << endl;
		MyPasswords << passwords[i] << endl;
		
	}
	
	MyUsernames.close();
	MyPasswords.close();

	
}

bool readFiles()
{
	string username, password;
	ifstream MyUsernames;
	ifstream MyPasswords;
	MyUsernames.open("usernames.txt");
	MyPasswords.open("passwords.txt");
	while (getline(MyUsernames, username))
	{
		usernames.push_back(username);
	}
	while (getline(MyPasswords, password))
	{
		passwords.push_back(password);
	}
	MyUsernames.close();
	MyPasswords.close();
	return true;
}

void begin()
{
	int choice;
	cout << "1: Set up an account" << endl << "2: Sign in to your account" << endl << "3. Exit Program" << endl << "what would you like to do: ";
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
	case 3:
		writeToFile();
		break;
	default:
		cout << "invalid entry";
	}
}

bool isLoggedIn(string un, string pw)
{
	recordIndex = recordIndex - 1;
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
		system("cls");
		createAccount();
	}
	else {
		system("cls");
		begin();
	}
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
	string prompt;
	cout << "Type 'Exit' to log out: ";
	cin >> prompt;
	if (prompt == "Exit")
		begin();
}
