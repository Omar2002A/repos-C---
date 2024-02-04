#include <iostream>
using namespace std;

int ReadPositiveNumber(string Messege)
{
	int Num;
	do
	{
		cout << Messege << endl;
		cin >> Num;

	} while (Num <= 0);

	return Num;
}

int Factorial(int Number)
{
	int Multi = 1;
	for (int i = Number; i >= 1; i--)
	{
		Multi *= i;
	}
	return Multi;
}

void PrintResult(int Fac)
{
	cout << "The Factoril for Number Your Entered = " << Fac << endl;
}

int main()
{
	PrintResult(Factorial(ReadPositiveNumber("Enter Number ? ")));
	return 0;
}