#include<iostream>
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

short NumberOfDayInMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;

	int Day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : Day[Month - 1];
}

bool isLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDayInMonth(Date.Month, Date.Year));
}

bool isLastMonthInYear(short Month)
{
	return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (isLastDayInMonth(Date))
	{
		if (isLastMonthInYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
} 

short ReadMonth()
{
	short Month;
	cout << "Please enter a Month? ";   
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year; 
	cout << "Please enter a Year? ";
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

	Date1 = IncreaseDateByOneDay(Date1);
	cout << "\nDate after adding one day is:" << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	system("pause>0");
	return 0;
}