#include <iostream>
#include <string>
using namespace std;

void ReadNumbers(int& Num1, int& Num2, int& Num3)
{
	cout << "Please Enter The First Number : \n";
	cin >> Num1;

	cout << "Please Enter The Second Number : \n";
	cin >> Num2;

	cout << "Please Enter The Third Number : \n";
	cin >> Num3;
}

int SumOf3Numbers(int Num1, int Num2, int Num3)
{
	return Num1 + Num2 + Num3;
}

float CalculateAvgOf3Numbers(int Number1, int Number2, int Number3)
{
	return (float)SumOf3Numbers(Number1, Number2, Number3) / 3;
}

void PrintSumResultes(int Total)
{
	cout << "\n The Sum = " << Total << endl;
}

void PrintAvgResultes(float AVG)
{
	cout << "\n The AVG = " << AVG << endl;
}

int main()
{
	int Num1, Num2, Num3;
	ReadNumbers(Num1, Num2, Num3);
	PrintSumResultes(SumOf3Numbers(Num1, Num2, Num3));
	PrintAvgResultes(CalculateAvgOf3Numbers(Num1, Num2, Num3));
}

