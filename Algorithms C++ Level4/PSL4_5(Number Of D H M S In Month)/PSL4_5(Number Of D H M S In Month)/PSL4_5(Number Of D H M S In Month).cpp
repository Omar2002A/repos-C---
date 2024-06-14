#include <iostream>
using namespace std;

bool LeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
	{
		return 0;
	}

	if (Month == 2)
	{
		return LeapYear(Year) ? 29 : 28;
	}

	short arr31days[7] = { 1, 3, 5, 7, 8, 10, 12 };
	for (short i = 1; i <= 7; i++)
	{
		if (arr31days[i - 1] == Month)
			return 31;
	}

	return 30;
}

short NumberOfHoursInMonth(short Month, short Year)
{
	return NumberOfDaysInMonth(Month, Year) * 24;
}

int NumberOfMinutesInMonth(short Month, short Year)
{
	return NumberOfHoursInMonth(Month, Year) * 60;
}

int NumberOfSecondsInMonth(short Month, short Year)
{
	return NumberOfMinutesInMonth(Month, Year) * 60;
}

short ReadMonth()
{
	short Month;
	cout << "\nPlz enter a month to check ? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "\nPlz enter a year to check ? ";
	cin >> Year;
	return Year;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInMonth(Month, Year);
	cout << "\nNumber of Hours   in Month [" << Month << "] is " << NumberOfHoursInMonth(Month, Year);
	cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutesInMonth(Month, Year);
	cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSecondsInMonth(Month, Year);

	system("pause>0");
	return 0;
}