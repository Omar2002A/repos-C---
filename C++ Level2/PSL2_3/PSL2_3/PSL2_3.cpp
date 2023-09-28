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

bool isPerfectNumber(int Number)
{
	int Sum = 0;
	for (int i = 1; i < Number; i++)
	{
		if (Number % i == 0)
			Sum += i;
	}
	return Sum == Number;
}

void PrintResult(int Number)
{
	if (isPerfectNumber(Number))
		cout << Number << " is a Perfect Number :)" << endl;
	else
		cout << Number << " is Not Perfect Number :( " << endl;
}

int main()
{
	PrintResult(ReadPositiveNumber("Enter Number ? "));
	return 0;
}