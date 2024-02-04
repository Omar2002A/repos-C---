#include <iostream>
using namespace std;

int ReadPositiveNumber(string Messege)
{
	int Number = 0;
	while (Number <=0 )
	{
		cout << Messege << endl;
		cin >> Number;
	}
	return Number;
}

int ReverseNumber(int Number)
{
	int Remainder = 0, Number2 = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		Number2 = Number2 * 10 + Remainder;
	}
	return Number2;
}

void PrintDigits(int Number)
{
	int Reminder = 0;
	while (Number > 0)
	{
		Reminder = Number % 10;
		Number = Number / 10;
		cout << Reminder << endl;
	}
}


int main()
{
	PrintDigits(ReverseNumber(ReadPositiveNumber("Enter Positive Number ? ")));
	return 0;
}