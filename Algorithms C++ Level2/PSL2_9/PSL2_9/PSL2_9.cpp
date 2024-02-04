#include <iostream>
using namespace std;

int ReadPositiveNumber(string Messege)
{
	int Number = 0;
	while (Number <= 0)
	{
		cout << Messege << endl;
		cin >> Number;
	}
	return Number;
}

int CountDigitFrequency(short DigitCheck, int Number)
{
	int CounterFreq = 0, Remainder = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		if (DigitCheck == Remainder)
		{
			CounterFreq++;
		}
	}
	return CounterFreq;
}

void PrintAllDigitFrequency(int Number)
{
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		short DigitFrequency = CountDigitFrequency(i, Number);
		if (DigitFrequency > 0)
		{
			cout << "Digit " << i << " Frequency is " << DigitFrequency << " Time(s).\n";
		}
	}
}

int main()
{
	PrintAllDigitFrequency(ReadPositiveNumber("Enter Positive Number ? "));
	return 0;
}