#include "imports.cpp"


int Reg_ID = 1;
vector<Patient> Patients;

void createNewPatient();
void viewPatientData();
void startPage();
void backToStart();


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
	char choice = 'Y';
	
	ofstream RegFile;  //save current serial number to Register
	RegFile.open("Register.txt");

	while (choice == 'Y')
	{
		string FirstName, LastName, Address, Occupation, filename;
		int Age;
		char Gender;
		
		RegFile << Reg_ID << endl;
		

		cout << "First Name: ";
		cin >> FirstName;
		cout << "Last Name: ";
		cin >> LastName;
		cin.ignore();
		cout << "Address: ";
		getline (cin, Address);
		cout << "Gender(M/F): ";
		cin >> Gender;
		cout << "Age(Years): ";
		cin >> Age;
		cin.ignore();
		cout << "Occupation: ";
		getline(cin, Occupation);

		Patient PatientData(Reg_ID, FirstName, LastName, Address, Gender, Age, Occupation);
		Patients.push_back(PatientData);

		
		filename = "Patient_Data_" + std::to_string(Reg_ID);
		string extension = ".txt";

		ofstream newFile;
		filename = filename + extension;
		newFile.open(filename.c_str());
		newFile.close();

		ofstream DataFile;
		DataFile.open(filename.c_str());
		DataFile << "Hospital ID Number: " << Reg_ID << endl;
		DataFile << "Name: " << FirstName << " " << LastName << endl;
		DataFile << "Age: " << Age << endl;
		DataFile << "Gender: " << Gender << endl;
		DataFile << "Address: " << Address << endl;
		DataFile << "Occupation: " << Occupation << endl;
		DataFile.close();

		cout << "Record created for " << FirstName << " " << LastName << " with Hospital ID Number: " << Reg_ID << endl;

		Reg_ID++;

		cout << "Create Another? Y/N: ";
		cin >> choice;
	}

	RegFile.close(); //Close Register File
	
	backToStart();
}
