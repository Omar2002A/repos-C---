#include <iostream>
#include <string>
using namespace std;

void DisplayMyCardInfo()
{

	string FullName;
	cout << "Enter Your Name : ";
	getline(cin, FullName);

	short Age;
	cout << "Enter Youe Age : ";
	cin >> Age;

	string Country, City;
	
	cout << "Enter Your Country : ";
	cin >> Country;

	cout << "Enter Your City : ";
	cin >> City;


	cout << "\n\n***************************\n";

	cout << "Name : " << FullName << "\n";
	cout << "Age : " << Age << "\n";
	cout << "Country : " << Country << "\n";
	cout << "City : " << City << "\n";

	cout << "***************************" << endl;
}

void PrintSquareStars()
{
	string Stars = "*********";
	cout << Stars << "\n" << Stars << "\n" << Stars << "\n" << Stars << "\n" << Stars << endl;
}

void PrintILoveProgramming()
{
	cout << "I Love Programming\n\n";
	cout << "I Promise to be the best developer ever!\n\n";
	cout << "I Know it will take some time to practice, but I will achieve any goal.\n\n";
	cout << "Best Regords,\nMohammad Abu-Hadhoud" << endl;

}

void PrintH()
{
	cout << "*   *\n";
	cout << "*   *\n";
	cout << "*****\n";
	cout << "*   *\n";
	cout << "*   *" << endl;
}

int main()
{

}