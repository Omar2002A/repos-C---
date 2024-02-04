#include <iostream>
#include <string>
using namespace std;


struct stInfo
{

	/*string FirstName;
	string LastName;
	short Age;
	string Phone;*/

	string Name;
	short Age;
	string Country;
	string City;
	short MonthlySalary;
	int YearlySalary;
	char Gendor;
	bool Married;

};

void ReadInfo(stInfo &Info)
{

	/*cout << "Enter Your First Name : ";
	cin >> Info.FirstName;

	cout << "Enter Your Last Name : ";
	cin >> Info.LastName;

	cout << "Enter Your Age : ";
	cin >> Info.Age;

	cout << "Enter Your Phone : ";
	cin >> Info.Phone;

	cout << "THX\n\n" << endl;*/


	cout << "Enter Your Name : ";
	getline(cin, Info.Name);

	cout << "Enter Your Age : ";
	cin >> Info.Age;

	cout << "Enter Your Country : ";
	cin >> Info.Country;

	cout << "Enter Your City : ";
	cin >> Info.City;

	cout << "Enter Your MonthlySalary : ";
	cin >> Info.MonthlySalary;

	Info.YearlySalary = 12 * Info.MonthlySalary;

	cout << "Enter Your Gendor : ";
	cin >> Info.Gendor;

	cout << "You Are Married ?\nIf Yes Enter 1\nElse Enter 0 ";
	cin >> Info.Married;

	cout << "THX\n\n\n";

}

void PrintInfo(stInfo Info)
{

	/*cout << "**************************\n";
	cout << "First Name : " << Info.FirstName << "\n";
	cout << "Last Name : " << Info.LastName << "\n";
	cout << "Age : " << Info.Age << "\n";
	cout << "Phone : " << Info.Phone << "\n";
	cout << "**************************" << endl;*/

	cout << "****************************\n";
	cout << "Name : " << Info.Name << "\n";
	cout << "Age : " << Info.Age << "\n";
	cout << "Country : " << Info.Country << "\n";
	cout << "City : " << Info.City << "\n";
	cout << "MonthlySalary : " << Info.MonthlySalary << "\n";
	cout << "YearlySalary : " << Info.YearlySalary << "\n";
	cout << "Gendor : " << Info.Gendor << "\n";
	cout << "Married ?  " << Info.Married << "\n";
	cout << "****************************" << endl;

}

int main()
{
	stInfo Person1Info;
	ReadInfo(Person1Info);
	PrintInfo(Person1Info);
}