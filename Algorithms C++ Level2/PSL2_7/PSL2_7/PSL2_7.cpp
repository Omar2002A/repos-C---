#include <iostream>
using namespace std;

int ReadPositiveNumber(string Messege)
{
	int Number = 0;
	while (Number <= 0)
	{
		cout << Messege << endl;
		cin >> Number;
	}
	return Number;
}

int PrintReverseNumber(int Number)
{
	int Number2 = 0;
	int Remainder = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		Number2 = Number2 * 10 + Remainder;
	}
	return Number2;
}

int main()
{
	cout << "The Reverse Number : " 
		<< PrintReverseNumber(ReadPositiveNumber("Enter Positive Number ? "));
	return 0;
}