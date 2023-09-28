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

int CountDigitFrequency(short DigitToCheck, int Number)
{
	int Remainder = 0, CountFrequency = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		if (Remainder == DigitToCheck)
		{
			CountFrequency++;
		}
		Number = Number / 10;
	}
	return CountFrequency;
}

int main()
{
	int Number = ReadPositiveNumber("Please Enter Positive Number ? ");
	short Digit = ReadPositiveNumber("Enter One Digit To Check ? ");

	cout << "Digit " << Digit << " Frequency is " << CountDigitFrequency(Digit, Number) << " Time(s)." << endl;
	return 0;
}
