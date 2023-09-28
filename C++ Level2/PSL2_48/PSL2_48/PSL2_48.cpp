#include <iostream>
using namespace std;

float ReadNumber()
{
	float Number = 0;
	cout << "Enter a number ? ";
	cin >> Number;
	return Number;
}

int MyFloor(float Number)
{
	if (Number > 0)
		return  int(Number);
	else
		return (int)Number - 1;
}

int main()
{
	float Number = ReadNumber();
	
	cout << "My MyFloor Result : " << MyFloor(Number) << endl; 
	cout << "C++ floor Result  : " << floor(Number) << endl;
	
	return 0;
}