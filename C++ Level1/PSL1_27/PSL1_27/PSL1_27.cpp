#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;
	cout << "Enter Number ? \n";
	cin >> Number;
	cout << endl;
	return Number;
}

void PrintRangeFromNTo1_UsingFor(int N)
{
	cout << "Print from N to 1 using for Statment : \n";
	for (int i = N; i >= 1; i--)
	{
		cout << i << endl;
	}
}

void PrintRangeFromNTo1_UsingWhile(int N)
{
	int Counter = N + 1;
	cout << "Print from N to 1 using for Statment : \n";
	while (Counter > 1)
	{
		Counter--;
		cout << Counter << endl;
	}
}

void PrintRangeFromNTo1_UsingDoWhile(int N)
{
	int Counter = N;
	cout << "Print from N to 1 using Do..While Statment : \n";
	do
	{
		cout << Counter << endl;
		Counter--;

	} while (Counter >= 1);
}

int main()
{
	int N = ReadNumber();
	PrintRangeFromNTo1_UsingFor(N);
	PrintRangeFromNTo1_UsingWhile(N);
	PrintRangeFromNTo1_UsingDoWhile(N);
	return 0;
}