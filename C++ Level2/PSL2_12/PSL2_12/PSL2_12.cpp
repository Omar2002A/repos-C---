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

void PrintInvertedNumberPattern(int Number)
{
	for (int i = Number; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}
		cout << endl;
	}
}

int main()
{
	PrintInvertedNumberPattern(ReadPositiveNumber("Enter Positive Number ? "));
	return 0;
}