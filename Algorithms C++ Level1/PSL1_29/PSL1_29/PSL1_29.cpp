#include <iostream>
using namespace std;

enum enOddOrEven { Odd = 1, Even = 2 };

int ReadNumber()
{
	int N;
	cout << "Enter The Number ? \n";
	cin >> N;
	cout << endl;
	return N;
}

enOddOrEven CheckOddOrEven(int Number)
{
	if (Number % 2 == 0)
		return enOddOrEven::Even;
	else
		return enOddOrEven::Odd;
}

int SumEvenNumbersFrom1toNUsingFor(int Number)
{
	int Sum = 0;
	for (int i = 1; i <= Number; i++)
	{
		if (CheckOddOrEven(i) == enOddOrEven::Even)
			Sum += i;
	}
	return Sum;
}

int SumEvenNumbersFrom1toNUsingWhile(int Number)
{
	int Sum = 0;
	int Counter = 1;

	while (Counter <= Number)
	{
		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
			Sum += Counter;
		Counter++;
	}
	return Sum;
}

int SumEvenNumbersFrom1toNUsingDoWhile(int Number)
{
	int Sum = 0;
	int Counter = 1;

	do
	{
		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
			Sum += Counter;
		Counter++;

	} while (Counter <= Number);
	return Sum;
}

void PrintResult(int Sum)
{
	cout << "The Sum = " << Sum << endl;
}

int main()
{
	PrintResult(SumEvenNumbersFrom1toNUsingDoWhile(ReadNumber()));
	return 0;
}