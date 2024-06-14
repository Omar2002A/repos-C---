#include <iostream>
using namespace std;

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberDayInMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;

	int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}

struct sDate
{
	short Day;
	short Month;
	short Year;
};

short NumberOfDaysFromTheBeginingOfTheYear(short day, short month, short year)
{
	short TotalDays = 0;

	for (int i = 1; i <= month - 1; i++)
		TotalDays += NumberDayInMonth(i, year);

	TotalDays += day;

	return TotalDays;
}

sDate DateAddDays(short Days, sDate Date)
{
	short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);

	short MonthDays = 0;

	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberDayInMonth(Date.Month, Date.Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}

	return Date;
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

short ReadDaysToAdd()
{
	short Add;
	cout << "\nHow many days need to add ? ";
	cin >> Add;
	return Add;
}

sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

int main()
{
	sDate Date = ReadFullDate();
	short DaysAdd = ReadDaysToAdd();

	Date = DateAddDays(DaysAdd, Date);

	cout << "\nDate after adding [" << DaysAdd << "] days is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;
}