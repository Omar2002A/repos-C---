#include <iostream>
using namespace std;

int ReadTotalSales()
{
	int T;
	cout << "Enter Total Sales ? \n";
	cin >> T;
	return T;
}

float GetComissionPercentage(float TotalSales)
{
	if (TotalSales >= 1000000)
		return 0.01;
	else if (TotalSales >= 500000)
		return 0.02;
	else if (TotalSales >= 100000)
		return 0.03;
	else if (TotalSales >= 50000)
		return 0.05;
	else
		return 0.0;
}

float CalculateTotalComission(float TotalSales)
{
	return GetComissionPercentage(TotalSales) * TotalSales;
}

void PrintResult(float X)
{
	cout << "The Comission = " << X;
}

int main()
{
	PrintResult(CalculateTotalComission(ReadTotalSales()));
	return 0;
}