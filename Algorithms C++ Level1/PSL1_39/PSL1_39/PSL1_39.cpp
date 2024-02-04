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

float CalculateRemainder(float TB, float CP)
{
	cout << "\n The Total Bill = " << TB;
	cout << "\n The Cach Paid = " << CP;
	cout << "\n ********************";
	return CP - TB;
	cout << endl;
}

void PrintRemainder(float Remainder)
{
	cout << "\n The Remainder = " << Remainder << endl;
}

int main()
{
	/*float TotalBill = ReadPositiveNumber("Enter Total Bill ? ");
	float CachPaid = ReadPositiveNumber("Enter Cach Paid ? ");
	PrintRemainder(CalculateRemainder(TotalBill, CachPaid));*/
	PrintRemainder(CalculateRemainder(ReadPositiveNumber("Enter Total Bill ? "), ReadPositiveNumber("Enter Cach Paid ? ")));
	return 0;
}