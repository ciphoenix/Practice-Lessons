#include "stdafx.h"


vector<Patient> Patients;
int RegID;

void createNewPatient();
void viewPatientData();
void startPage();
void backToStart();
void insertData(pqxx::work& DemoWork, string FirstName, string LastName, int age, string gender, string address, string occupation);
//void viewDataBase(pqxx::work& DemoWork, std::string scope, std::string database);
string initialiseDB(string DBName);

int main()
{

	startPage();

	return 0;
}


void startPage()
{
	int choice;
	cout << "\n\n\n**********MENU**********" << endl;
	cout << "1. Create New Patient Record\n";
	cout << "2. View Specific Patient Data\n";
	cout << "3. Exit Program\n\n";

	cout << "Choose an option: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		createNewPatient();
		break;
	case 2:
		viewPatientData();
		break;
	case 3:
		break;

	default:
	{
		cout << "Invalid option. Try again";
		startPage();
		break;
	}
	}
}

void backToStart()
{
	char choice = 'N';
	while (choice == 'N')
	{
		cout << "\n\nwould you like to go back? Y/N: ";
		cin >> choice;
	}

	if (choice == 'Y')
		startPage();
}

void viewPatientData()
{
	int index;
	cout << "Enter Patient's ID Number: ";
	cin >> index;

	ifstream RegFile("Register.txt"); //Check If That Number Exists
	int RegNum;
	while (RegFile >> RegNum) //Check register line by line for presence of the requested number
	{
		if (RegNum != index)
			cout << "Patient Records Not Found!";
	}

	string PatientInfo;
	string filename = "Patient_Data_" + std::to_string(index) + ".txt";
	ifstream DataFile;
	DataFile.open(filename);
	while (getline(DataFile, PatientInfo)) // Read Data File Line by line and print it out
	{
		cout << PatientInfo << endl;
	}



	backToStart();
}

void createNewPatient()
{
	
	string FirstName, LastName, Gender, Address, Occupation;
	int Age;


	cout << "First Name: ";
	cin >> FirstName;
	cout << "Last Name: ";
	cin >> LastName;
	cin.ignore();
	cout << "Address: ";
	getline(cin, Address);
	cout << "Gender(M/F): ";
	cin >> Gender;
	cout << "Age(Years): ";
	cin >> Age;
	cin.ignore();
	cout << "Occupation: ";
	getline(cin, Occupation);

	string Connect = initialiseDB("PatientRecords");

	try
	{
		pqxx::connection connectionObject(Connect.c_str());

		pqxx::work worker(connectionObject);

		insertData(worker, FirstName, LastName, Age, Gender, Address, Occupation);

		worker.commit();
		
		cout << "Record created for " << FirstName << " " << LastName << "\nHospital ID is " << RegID << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	backToStart();
}

void insertData(pqxx::work& DemoWork, string FirstName, string LastName, int age, string gender, string address, string occupation)
{

	string query = "INSERT INTO Patient_Data (firstname, lastname, age, gender, address, occupation)VALUES ('"
		+ FirstName + "', '" + LastName + "', " + to_string(age) + ", '" + gender + "', '" + address + "', '" + occupation + "') returning hospital_id_number;";
	pqxx::result response = DemoWork.exec(query.c_str());
	RegID = response[0][0].as<int>();	
}

string initialiseDB(string DBName)
{
	std::string connectionString = "host=localhost port=5432 dbname=" + DBName + " user=postgres password =G0r0k233.dll";
	return connectionString;
}
