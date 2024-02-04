#include <iostream>
#include <cmath>
using namespace std;

float ReadNumbers()
{
	float LengthOfSquare;
	cout << "Enter The Lenght Of Side Square : ";
	cin >> LengthOfSquare;

	cout << "\nTHX\n" << endl;
	return LengthOfSquare;
}

float CircleAreaInscribedinAsquare(float LenthOfSquare)
{
	const float PI = 3.141592653589793238;
	return ((pow(LenthOfSquare, 2) * PI) / 4);
}

void PrintResults(float Area)
{
	cout << "\n The Area = " << Area << endl;
}

int main()
{
	PrintResults(CircleAreaInscribedinAsquare(ReadNumbers()));
	return 0;
}