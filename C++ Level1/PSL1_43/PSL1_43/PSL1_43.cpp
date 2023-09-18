#include <iostream>
using namespace std;

struct strTaskDuration {
	int NumberOfDays, NumberOfHours, NumberOfMinuits, NumberOfSeconds;
};

int ReadPositiveNumber(string Messege)
{
	int Number = 0;
	do
	{
		cout << Messege << endl;
		cin >> Number;

	} while (Number <= 0);
	return Number;
}

strTaskDuration SecondsToTaskDuration(int Seconds)
{
	strTaskDuration TaskDurtion;

	const int SecondsPerDay = 24 * 60 * 60;
	const int SecondsPerHours = 60 * 60;
	const int SecondsPerMinuits = 60;

	int Remainder = 0;
	TaskDurtion.NumberOfDays = floor(Seconds / SecondsPerDay);
	Remainder = Seconds % SecondsPerDay;
	TaskDurtion.NumberOfHours = floor(Remainder / SecondsPerHours);
	Remainder = Remainder % SecondsPerHours;
	TaskDurtion.NumberOfMinuits = floor(Remainder / SecondsPerMinuits);
	Remainder = Remainder % SecondsPerMinuits;
	TaskDurtion.NumberOfSeconds = Remainder;

	return TaskDurtion;
}

void NumberOfDaysHoursMinutsSeconds(strTaskDuration Result)
{
	cout << "Number Of Days:Hours:Minuits:Seconds --> ";
	cout << Result.NumberOfDays << ":" << Result.NumberOfHours << ":" << Result.NumberOfMinuits << ":" << Result.NumberOfSeconds << endl;
}

int main()
{
	NumberOfDaysHoursMinutsSeconds(SecondsToTaskDuration(ReadPositiveNumber("Enter Total Seconds ? ")));
	return 0;
}