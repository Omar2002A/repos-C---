#include <iostream>
using namespace std;

void ReadArraiData(int Arrai[100], int& Lenght)
{
	cout << "Enter Number Of Data : ";
	cin >> Lenght;
	cout << "\n\n";

	for (int Num = 0; Num <= Lenght - 1; Num++)
	{

		cout << "Enter Number " << Num + 1 << endl;
		cin >> Arrai[Num];

	}
}

void PrintArraiData(int Arrai[100], int Lenght)
{

	for (int Num = 0; Num <= Lenght - 1; Num++)
	{
		cout << "The Number For [" << Num + 1 << "] = " << Arrai[Num] << endl;
	}

}

int CalculaterArraySum(int Arrai[100], int Lenght)
{
	int Sum = 0;
	for (int i = 0; i < Lenght; i++)
	{
		Sum += Arrai[i];
	}
	return Sum;
}

float CalculaterArrayAvg(int Arrai[100], int Lenght)
{

	return (float)CalculaterArraySum(Arrai, Lenght) / Lenght;

}

void PrintResult()
{
	int Arrai[100], Lenght = 0;
	ReadArraiData(Arrai, Lenght);
	PrintArraiData(Arrai, Lenght);
	cout << "\n\n**********************\n";
	cout << "The Sum = " << CalculaterArraySum(Arrai, Lenght) << endl;
	cout << "The AVG = " << CalculaterArrayAvg(Arrai, Lenght) << endl;
}

int main()
{
	PrintResult();
}