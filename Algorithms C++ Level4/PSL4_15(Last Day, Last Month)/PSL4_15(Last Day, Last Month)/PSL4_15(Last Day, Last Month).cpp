﻿#include <iostream>
using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

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

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

short ReadDay()
{
	short Day;
	cout << "enter a day ? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month;
	cout << "enter a month ? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "enter a year ? ";
	cin >> Year;
	return Year;
}

stDate ReadFullDate()
{
	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

int main()
{
	stDate Date1 = ReadFullDate();
	if (IsLastDayInMonth(Date1))
		cout << "\nYes, Day is Last Day in Month.";
	else
		cout << "\nNo, Day is Not Last Day in Month.";
	
	if (IsLastMonthInYear(Date1.Month))
		cout << "\nYes, Month is Last Month in Year.";
	else
		cout << "\nNo, Month is Not Last Month in Year.";
	
	system("pause>0");
	return 0;
}