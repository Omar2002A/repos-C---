#include <iostream>
using namespace std;

float ReadNumbers()
{
	float LenghtOfCircumference;
	cout << "Enter The Lenght Of Circumference : ";
	cin >> LenghtOfCircumference;

	cout << "\nTHX\n" << endl;
	return LenghtOfCircumference;
}

float CircleAreaAlongtheCircumference(float LenghtOfCircumference)
{
	const float PI = 3.14159265359;
	return ((pow(LenghtOfCircumference, 2)) / (4 * PI));
}

void PrintResults(float Area)
{
	cout << "\n The Area = " << Area << endl;
}

int main()
{
	PrintResults(CircleAreaAlongtheCircumference(ReadNumbers()));
}