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

void PrintLetterPattern(int Number)
{
	for (int i = 1; i <= Number; i++)
	{
		cout << endl;
		for (int j = 1; j <= i; j++)
		{
			cout << char(i + 64);
		}
	}
}

int main()
{
	PrintLetterPattern(ReadPositiveNumber("Enter Positive Number ? "));
	return 0;
}