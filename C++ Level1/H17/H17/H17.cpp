#include <iostream>
using namespace std;
enum enCountry { Jordan = 1, Palstine = 2, Turkia = 3, SudiArebia = 4 };
int main()
{
	cout << "Jordan = 1, Palstine = 2, Turkia = 3, SudiArebia = 4\nEnter Number : " << endl;
	short Number;
	enCountry Country;
	cin >> Number;
	Country = (enCountry)Number;

	switch (Country)
	{
	case Jordan:
		cout << "Your Country Jordan";
		break;

	case enCountry::Palstine:
		cout << "Palstine";
		break;

	case enCountry::Turkia:
		cout << "Turki";
		break;

	case SudiArebia:
		cout << "Sudia";
		break;

	default:
		cout << "Invaild Number!";
		break;
	}
}