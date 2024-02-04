#include <iostream>
using namespace std;

enum enPrimeOrNot { Prime = 1, NotPrime = 2 };

int ReadPositiveNumber(string Messege)
{
	int Number = 0;
	do
	{
		cout << Messege << endl;
		cin >> Number;

	} while (Number <= 0);
	return Number;
}

enPrimeOrNot CheckIfPrime(int Number)
{
	int M = round(Number / 2);
	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)
			return enPrimeOrNot::NotPrime;
	}
	return enPrimeOrNot::Prime;
}

void PrintPrimeNumberFrom1toN(int Number)
{
	cout << "\n Prime Number From 1 to " << Number << " are : " << endl;
	for (int i = 1; i <= Number; i++)
	{
		if (CheckIfPrime(i) == enPrimeOrNot::Prime)
		{
			cout << i << endl;
		}
	}
}

int main()
{
	PrintPrimeNumberFrom1toN(ReadPositiveNumber("Enter Number ? "));
	return 0;
}