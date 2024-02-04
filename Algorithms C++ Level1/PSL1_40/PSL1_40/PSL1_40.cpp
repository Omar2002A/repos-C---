#include <iostream>
using namespace std;

float ReadPositiveNumber(string Messege)
{
	float Number = 0;
	do
	{
		cout << Messege << endl;
		cin >> Number;

	} while (Number <= 0);
	return Number;
}

float CalculateTotalBillAfterServiceAndTax(float TotalBill)
{
	TotalBill *= 1.1;
	TotalBill *= 1.16;
	return TotalBill;
}

int main()
{
	float TotalBill = ReadPositiveNumber("Enter Total Bill ? ");
	cout << endl;
	cout << "The Total Bill = " << TotalBill << endl;
	cout << "The Total Bill After Service And Tax = " << CalculateTotalBillAfterServiceAndTax(TotalBill) << endl;
	return 0;
}