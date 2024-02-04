#include <iostream>
using namespace std;

int ReadPositiveNumber(string Messege)
{
	int Number = 0;
	while (Number <=0 )
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

void PrintPerfectNumberFrom1toN(int Number)
{
	cout << "The Perfect Number From 1 To " << Number << " Are : \n" << endl;
	for (int i = 1; i <= Number; i++)
	{
		if (isPerfectNumber(i))
			cout << i << endl;
	}
}

int main()
{
	PrintPerfectNumberFrom1toN(ReadPositiveNumber("Enter Number ? "));
	return 0;
}