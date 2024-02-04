#include <iostream>
using namespace std;

enum enNumberType { Odd = 1, Even = 2 };

int ReadNumber()
{
	int Number;
	cout << "Please Enter The Number ? \n";
	cin >> Number;
	return Number;
}

enNumberType CheckNumberType(int Num)
{
	int Result = Num % 2;
	if (Result == 0)
	{
		return enNumberType::Even;
	}
	else
	{
		return enNumberType::Odd;
	}
}

void PrintNumberType(enNumberType NumberType)
{
	if (NumberType == enNumberType::Even)
	{
		cout << "\n The Number Is Even :) \n";
	}
	else
	{
		cout << "\n The Number Is Odd :) \n";
	}
}

int main()
{
	PrintNumberType(CheckNumberType(ReadNumber()));
	return 0;
}