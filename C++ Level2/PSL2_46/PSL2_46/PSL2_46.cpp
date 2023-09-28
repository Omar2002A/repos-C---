#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number = 0;
	cout << "Enter a number ? ";
	cin >> Number;
	return Number;
}

float MyABS(float Number)
{
	if (Number < 0)
		return Number * -1;
	return Number;
}

int main()
{
	float Number = ReadNumber();
	
	cout << "My abs Result : " << MyABS(Number) << endl;
	cout << "C++ abs Result: " << abs(Number) << endl;
	
	return 0;
}