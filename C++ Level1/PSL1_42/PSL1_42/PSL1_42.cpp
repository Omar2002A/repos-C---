#include <iostream>
using namespace std;

struct strTaskDuration
{
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

strTaskDuration ReadTaskDuration()
{
	strTaskDuration Info;

	Info.NumberOfDays = ReadPositiveNumber("Enter Number Of Days ? ");
	Info.NumberOfHours = ReadPositiveNumber("Enter Number Of Hours ? ");
	Info.NumberOfMinuits = ReadPositiveNumber("Enter Number Of Minuits ? ");
	Info.NumberOfSeconds = ReadPositiveNumber("Enter Number Of Seconds ? ");

	return Info;
}

int TaskDurationInSecond(strTaskDuration TaskDuration)
{
	int DurationInSecond = 0;

	DurationInSecond = TaskDuration.NumberOfDays * 24 * 60 * 60;
	DurationInSecond += TaskDuration.NumberOfHours * 60 * 60;
	DurationInSecond += TaskDuration.NumberOfMinuits * 60;
	DurationInSecond += TaskDuration.NumberOfSeconds;

	return DurationInSecond;
}

void PrintNumOfSecond(int Seconds)
{
	cout << "\n Number Of Seconds = " << Seconds << endl;
}

int main()
{
	PrintNumOfSecond(TaskDurationInSecond(ReadTaskDuration()));
	return 0;
}