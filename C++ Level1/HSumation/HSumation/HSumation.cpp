#include <iostream>
using namespace std;

enum enAllOrOddOrEven { All = 0, Odd = 1, Even = 2 };

int ReadNumber()
{
	int Number;
	cout << "Enter Number ? \n";
	cin >> Number;
	cout << endl;
	return Number;
}

enAllOrOddOrEven AllOrOddOrEven()
{
	int N;
	cout << "Enter Number of type sum you need : \n1)Odd 2)Even ,If You need All Number Enter Any Number :) !!\n";
	cin >> N;
	if (N == 1)
		return enAllOrOddOrEven::Odd;
	else if (N == 2)
		return enAllOrOddOrEven::Even;
	else
		return enAllOrOddOrEven::All;
}

enAllOrOddOrEven CheckEvenOrOdd(int N)
{
	if (N % 2 == 0)
		return enAllOrOddOrEven::Even;
	else
		return enAllOrOddOrEven::Odd;
}

int SumNumbers(int N,enAllOrOddOrEven What)
{
	int Sum = 0;
	if (What == enAllOrOddOrEven::All)
	{
		for (int i = 1; i <= N; i++)
		{
			Sum += i;
		}
		return Sum;
	}
	else if (What == enAllOrOddOrEven::Even)
	{
		for (int i = 1; i <= N; i++)
		{
			if (CheckEvenOrOdd(i) == enAllOrOddOrEven::Even)
				Sum += i;
		}
		return Sum;
	}
	else if (What == enAllOrOddOrEven::Odd)
	{
		for (int i = 1; i <= N; i++)
		{
			if (CheckEvenOrOdd(i) == enAllOrOddOrEven::Odd)
				Sum += i;
		}
		return Sum;
	}
}

void PrintResult(int Sum)
{
	cout << "\nThe Sum = " << Sum << endl;
}

int main()
{
	PrintResult(SumNumbers(ReadNumber(), AllOrOddOrEven()));
}