﻿#include <iostream>
using namespace std;

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;

	int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
	short TotalDays = 0;

	for (int i = 1; i <= Month-1; i++)
	{
		TotalDays += NumberOfDaysInMonth(i, Year);
	}
	TotalDays += Day;

	return TotalDays;
}

short ReadDay()
{
	short Day;
	cout << "Enter a day ? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month;
	cout << "Enter a month ? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "Enter a year ? ";
	cin >> Year;
	return Year;
}

int main()
{
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();

	cout << "\nNumber of Days from the begining of the year is : " << NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);

	system("pause>0");
	return 0;
}