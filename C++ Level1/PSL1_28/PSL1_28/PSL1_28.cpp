#include <iostream>
using namespace std;

enum enOddOrEven { odd = 1, even = 2 };

int ReadNumber()
{
	int N;
	cout << "Enter Number ? \n";
	cin >> N;
	cout << endl;
	return N;
}

enOddOrEven CheckOddOrEven(int Number)
{
	if (Number % 2 == 0)
		return enOddOrEven::even;
	else
		return enOddOrEven::odd;
}

int SumOddNumbersFrom1toNUsingFor(int Number)
{
	int Sum = 0;
	for (int i = 1; i <= Number; i++)
	{
		if (CheckOddOrEven(i) == enOddOrEven::odd)
		{
			Sum += i;
		}
	}
	return Sum;
}

int SumOddNumbersFrom1toNUsingWhile(int Num)
{
	int Sum = 0;
	int Counter = 1;
	while (Counter <= Num)
	{
		
		if (CheckOddOrEven(Counter) == enOddOrEven::odd)
			Sum += Counter;
		Counter++;
	}
	return Sum;
}

int SumOddNumbersFrom1toNUsingDoWhile(int N)
{
	int Sum = 0;
	int Counter = 1;
	do
	{
		if (CheckOddOrEven(Counter) == enOddOrEven::odd)
			Sum += Counter;
		Counter++;

	} while (Counter < N);
	return Sum;
}

int main()
{
	int N = ReadNumber();
	cout << SumOddNumbersFrom1toNUsingFor(N) << endl;
	cout << SumOddNumbersFrom1toNUsingWhile(N) << endl;
	cout << SumOddNumbersFrom1toNUsingDoWhile(N) << endl;
	return 0;
}