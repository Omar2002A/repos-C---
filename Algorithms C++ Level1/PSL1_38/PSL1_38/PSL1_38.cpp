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

enPrimeOrNot CheckNummberIsPrime(int Num)
{
	int M = round(Num / 2);
	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Num % Counter == 0)
			return enPrimeOrNot::NotPrime;
	}
	return enPrimeOrNot::Prime;
}

void PrintNumberType(int Number)
{
	switch (CheckNummberIsPrime(Number))
	{
	case Prime:
		cout << "The Number Is Prime!";
		break;
	case NotPrime:
		cout << "The Number Not Prime!";
		break;
	}
}

int main()
{
	PrintNumberType(ReadPositiveNumber("Enter Positive Number :) "));
	return 0;
}