#include <iostream>
using namespace std;

float ReadPositiveNumber(string Messege)
{
	float Number = 0;
	do
	{
		cout << Messege << endl;
		cin >> Number;

	} while (Number <= 0);
	return Number;
}

float HoursToDays(float NumberOfHours)
{
	return NumberOfHours / 24;
}

float HoursToWeeks(float NumberOfHours)
{
	return (NumberOfHours / 24) / 7;
}

void PrintResult(float NumberOfDays, float NumberOfWeeks)
{
	cout << "Number Of Days = " << NumberOfDays;
	cout << "\nNumber Of Weeks = " << NumberOfWeeks << endl;
}

int main()
{
	float NumberOfHours = ReadPositiveNumber("Enter Number Of Hours ? ");
	PrintResult(HoursToDays(NumberOfHours), HoursToWeeks(NumberOfHours));
	return 0;
}