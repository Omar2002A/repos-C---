#include <iostream>
using namespace std;

int ReadNumber()
{
	int Num;
	cout << "Enter Number ~Range~ ? \n";
	cin >> Num;
	cout << endl;
	return Num;
}

void PrintRangeFrom1toN_UsingWhile(int N)
{
	int Counter = 0;
	cout << "Range printed using while Statment: \n";

	while (Counter < N)
	{
		Counter++;
		cout << Counter << endl;
	}
}

void PrintRangeFrom1toN_UsingFor(int N)
{
	cout << "Range printed using for Statment: \n";

	for (int i = 1; i <= N; i++)
	{
		cout << i << endl;
	}
}

void PrintRangeFrom1toN_UsingDoWhile(int N)
{
	int Counter = 0;
	cout << "Range printed using do while Statment: \n";

	do
	{
		Counter++;
		cout << Counter << endl;
	} while (Counter < N);
}

int main()
{
	int N = ReadNumber(); //Read Number Just One!
	PrintRangeFrom1toN_UsingDoWhile(N);
	PrintRangeFrom1toN_UsingFor(N);
	PrintRangeFrom1toN_UsingWhile(N);
	return 0;
}