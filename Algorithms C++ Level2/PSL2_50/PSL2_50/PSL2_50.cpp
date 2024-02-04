#include <iostream>
using namespace std;

float ReadNumber()
{
	float Number = 0;
	cout << "Enter a number ?? ";
	cin >> Number;
	return Number;
}

int MySqrt(float Number)
{
	return pow(Number, 0.5);
}

int main()
{
	float Number = ReadNumber();

	cout << "My MySqrt Result : " << MySqrt(Number) << endl; 
	cout << "C++ sqrt Result: " << sqrt(Number) << endl;

	return 0;
}