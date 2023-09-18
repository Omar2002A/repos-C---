#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please Enter The Number ? \n";
	cin >> Number;

	return Number;
}

float CalculateHalfNumber(int Number)
{ 
	return (float)Number / 2;
}

void PrintHalfNumber(int Number)
{
	string Result = "Half Of " + to_string(Number) + " is " + to_string(CalculateHalfNumber(Number));
	cout << Result << endl;
}

int main()
{
	PrintHalfNumber(ReadNumber());
}