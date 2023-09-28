#include <iostream>
using namespace std;

float ReadNumber()
{
	float Number = 0;
	cout << "Enter a number ? ";
	cin >> Number;
	return Number;
}

float GetFractionPart(float Number)
{
	return Number - (int)Number;
}

int MyCeil(float Number)
{
	if (abs(GetFractionPart(Number)) > 0)
		if (Number > 0)
			return (int)Number + 1;
		else
			return int(Number);
	return Number;
}

int main()
{
	float Number = ReadNumber(); 
	cout << "My MyCeil Result : " << MyCeil(Number) << endl;
	cout << "C++ ceil Result: " << ceil(Number) << endl; 
	return 0;
}