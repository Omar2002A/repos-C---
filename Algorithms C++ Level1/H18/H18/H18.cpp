#include <iostream>
using namespace std;

enum enWeekDay { Sun = 1, Mon = 2, Tue = 3, Wen = 4, Thu = 5, Fri = 6, Sar = 7 };

void ShowWeekDayMenue()
{
	cout << "*******************\n";
	cout << "	Week Days	\n";
	cout << "*******************\n";
	cout << "(1) Sunday\n";
	cout << "(2) Monday\n";
	cout << "(3) Tuesday\n";
	cout << "(4) Wensday\n";
	cout << "(5) Thursday\n";
	cout << "(6) Friday\n";
	cout << "(7) Saturday\n";
	cout << "*******************\n";
	cout << "Enter The Number of Day ? " << endl;
}

enWeekDay ReadWeekDay()
{
	enWeekDay WeekDay;
	short Number;
	cin >> Number;
	return (enWeekDay)Number;
}

string GetWeekDayName(enWeekDay WeekDay)
{
	switch (WeekDay)
	{
	case enWeekDay::Sun:
		return "Sunday";
		break;

	case enWeekDay::Mon:
		return "Monday";
		break;

	case enWeekDay::Tue:
		return "Tueseday";
		break;

	case enWeekDay::Wen:
		return "Wensday";
		break;

	case enWeekDay::Thu:
		return "Thursday";
		break;

	case enWeekDay::Fri:
		return "Friday";
		break;

	case enWeekDay::Sar:
		return "Saterday";
		break;

	default:
		return "Invalid Day";
		break;
	}
}

void PrintWeekDay()
{
	cout << "Day is " << GetWeekDayName(ReadWeekDay()) << endl;
}

int main()
{

	ShowWeekDayMenue();

	PrintWeekDay();


}