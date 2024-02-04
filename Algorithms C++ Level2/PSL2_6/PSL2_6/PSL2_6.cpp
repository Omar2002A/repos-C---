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

int PrintSumDigits(int Number)
{
	int Sum = 0;
	int Remainder = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Sum += Remainder;
		Number = Number / 10;
	}
	return Sum;
}

int main()
{
	cout << "The Sum = " << PrintSumDigits(ReadPositiveNumber("Enter Positive Number ? ")) << endl;
	return 0;
}