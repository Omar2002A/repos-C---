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

void PrintNumberPattern(int Number)
{
	for (int i = 1; i <= Number; i++)
	{
		cout << endl;
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}
	}
}

int main()
{
	PrintNumberPattern(ReadPositiveNumber("Enter Positive Number ? "));
	return 0;
}