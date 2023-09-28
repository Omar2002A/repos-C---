#include <iostream>
using namespace std;

float GetFractionPart(float Number)
{
	return Number - (int)Number;
}

int MyRound(float Number)
{
	int IntPart;
	IntPart = int(Number);

	float FractionPart = GetFractionPart(Number);

	if (abs(FractionPart) >= 0.5)
	{
		if (Number > 0)
			return ++IntPart;
		else
			return --IntPart;
	}
	else
		return IntPart;
}

int ReadNumber()
{
	int Number = 0;
	cout << "Enter a number ? ";
	cin >> Number;
	return Number;
}

int main()
{
	float Number = ReadNumber();
	cout << "My Round Result : " << MyRound(Number) << endl;    
	cout << "C++ Round Result: " << round(Number) << endl;
	return 0;
}