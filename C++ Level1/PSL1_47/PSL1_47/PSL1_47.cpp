#include <iostream>
using namespace std;

float ReadPositiveNumber(string Messege)
{
	int Number = 0;
	do
	{
		cout << Messege << endl;
		cin >> Number;

	} while (Number <= 0);
	return Number;
}

float CalculateMonths(float LoanAmount,float MonthlyPayment)
{
	return LoanAmount / MonthlyPayment;
}

int main()
{
	float LA, MP;
	LA = ReadPositiveNumber("Enter LoanAmount ? ");
	MP = ReadPositiveNumber("Enter MonthlyPayment ? ");

	cout << "**********************\n";
	cout << "Number Of Months = " << ceil(CalculateMonths(LA, MP)) << endl;
	return 0;
}