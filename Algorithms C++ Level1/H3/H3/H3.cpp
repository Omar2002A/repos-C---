#include <iostream>
using namespace std;
int main()
{
	string Name;
	unsigned short int Age;
	string City, Country;
	float MonthlySalary;
	signed char Gender;
	bool Married;
	

	cout << "Please Enter Your Name : " << endl;
	cin >> Name;

	cout << "Please Enter Your Age : " << endl;
	cin >> Age;

	cout << "Please Enter Your City : " << endl;
	cin >> City;
	cout << "Please Enter Your Country : " << endl;
	cin >> Country;

	cout << "Please Enter Your Monthly Salary : " << endl;
	cin >> MonthlySalary;
	float YearlySalary = 12 * MonthlySalary;

	cout << "Please Enter Your Gender M/F : " << endl;
	cin >> Gender;

	cout << "If you married enter 1 if not enter 0, THX" << endl;
	cin >> Married;





	cout << "***********************************\n";
	cout << "Name : " << Name << "\n";
	cout << "Age : " << Age << " Years.\n";
	cout << "City : " << City << ".\nCountry : " << Country <<".\n";
	cout << "Monthly Salary : " << MonthlySalary << "\nYearly Salary : " << YearlySalary << "\n";
	cout << "Gender : " << Gender << "\n";
	cout << "Married : " << Married << "\n";
	cout << "***********************************\n";


	/*int Num1, Num2, Num3;
	cout << "Please Enter Number 1 : ";
	cin >> Num1;
	cout << "Please Enter Number 2 : ";
	cin >> Num2;
	cout << "Please Enter Number 3 : ";
	cin >> Num3;

	int Sum = Num1 + Num2 + Num3;
	cout << Num1 << " +\n" << Num2 << " +\n" << Num3 << " \n-----------------\n" << Sum << endl;*/

	/*int Age;
	cout << "Please Enter Your Age : ";
	cin >> Age;
	cout << "Alter 5 years you will be " << Age + 5 << " years old.\n";*/

	return 0;
}
