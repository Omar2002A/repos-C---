#include <iostream>
using namespace std;

bool LeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	
	int arr12month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (LeapYear(Year) ? 29 : 28) : arr12month[Month - 1];
}

short ReadMonth()
{
	short Month;
	cout << "\nEnter a month to check ? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "\nEnter a year to check ? ";
	cin >> Year;
	return Year;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	cout << "\nNumber of Days in Month [" << Month << "] is " << NumberOfDaysInMonth(Month, Year);

	system("pause>0");
	return 0;
}