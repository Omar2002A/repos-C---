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

float MonthlyInstallment(float LoanAmount, float HowManyMonths)
{
	return LoanAmount / HowManyMonths;
}

void PrintResult()
{
	float LA = ReadPositiveNumber("Enter Loan Amount ? ");
	float HM = ReadPositiveNumber("Enter How Many Month ? ");

	cout << "********************\n";
	cout << "Monthly Installment = " << MonthlyInstallment(LA, HM) << endl;
}

int main()
{
	PrintResult();
	return 0;
}