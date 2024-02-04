#include <iostream>
#include <cmath>
using namespace std;

float ReadNumbers()
{
	float Diameter;
	cout << "Enter The Diameter : ";
	cin >> Diameter;

	cout << "\n THX\n" << endl;
	return Diameter;
}

float CalculateCircleAreaThroughDiameter(float Diameter)
{
	const float PI = 3.141592653589793238;
	return (PI * pow(Diameter, 2)) / 4;
}

void PrintResult(float Area)
{
	cout << "\n The Area = " << Area << endl;
}

int main()
{
	PrintResult(CalculateCircleAreaThroughDiameter(ReadNumbers()));
	return 0;
}