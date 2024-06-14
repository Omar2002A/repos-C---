#include <iostream>
using namespace std;

bool LeapYear(short Year)
{
	if (Year % 100 == 0)
	{
		return true;
	}
	else if (Year % 4 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

short ReadYear()
{
	short Year;
	cout << "\nPlease enter a year to check ? ";
	cin >> Year;
	return Year;
}

int main()
{
	short Year = ReadYear();
	if (LeapYear(Year))
		cout << "\nYes, Year [" << Year << "] is a leap year :)\n";
	else
		cout << "\nNo, Year [" << Year << "] is Not a leap year :)\n";

	system("pause>0");
	return 0;
}