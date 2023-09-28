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

void PrintInvertedLetterPattern(int Number)
{
	for (int i = Number; i >= 1; i--)
	{
		cout << endl;
		for (int j = 1; j <= i; j++)
		{
			cout << char(64 + i);
		}
	}
}

int main()
{
	PrintInvertedLetterPattern(ReadPositiveNumber("Enter Positive Number ? "));
	return 0;
}