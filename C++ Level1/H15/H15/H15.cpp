#include <iostream>
using namespace std;

struct strInformation
{

	string FirstName;
	string LastName;
	short Age;
	string Phone;

};

void ReadInfo(strInformation &Info)
{

	cout << "Enter Your First Name : ";
	cin >> Info.FirstName;

	cout << "Enter Your Last Name : ";
	cin >> Info.LastName;

	cout << "Enter Your Age : ";
	cin >> Info.Age;

	cout << "Enter Your Phone : ";
	cin >> Info.Phone;

	cout << "THX\n\n";
}

void PrintInfo(strInformation Info)
{

	cout << "*********************\n";
	cout << "Name : " << Info.FirstName << " " << Info.LastName << ".\n";
	cout << "Age : " << Info.Age << "\n";
	cout << "Phone : " << Info.Phone << "\n";
	cout << "*********************\n" << endl;

}

void ReadPersonsInfo(strInformation Persons[100], short& NumOfPersons)
{

	cout << "Enter Number Of Persons : ";
	cin >> NumOfPersons;
	cout << "\n\n";

	for (int Num = 0; Num <= NumOfPersons - 1; Num++)
	{
		cout << "Enter Info For Person " << Num + 1 << " ? \n";
		ReadInfo(Persons[Num]);
	}

}

void PrintPersonsInfo(strInformation Persons[100], short NumOfPersons)
{

	for (int Num = 0; Num <= NumOfPersons - 1; Num++)
	{
		cout << "Person's " << Num + 1 << " Info : \n";
		PrintInfo(Persons[Num]);
	}

}

int main()
{

	strInformation Persons[100];
	short N = 1;

	ReadPersonsInfo(Persons, N);
	PrintPersonsInfo(Persons, N);

	return 0;

}