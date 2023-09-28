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

bool isPalindromeNumber(int Number)
{
	return Number == ReverseNumber(Number);
}

void PrintResult(int Number)
{
	if (isPalindromeNumber(Number))
		cout << "Yes, it is a palindrome number. :)" << endl;
	else
		cout << "No, it is Not a palindrome number. :)" << endl;
}

int main()
{
	int Number = ReadPositiveNumber("Enter Positive Number ? ");
	PrintResult(Number);
	return 0;
}