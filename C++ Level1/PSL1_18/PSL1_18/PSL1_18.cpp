#include <iostream>
#include <cmath>
using namespace std;

float ReadNumbers()
{
	float R;

	cout << "Please Enter R : ";
	cin >> R;

	cout << "\nTHX\n" << endl;
	return R;
}

float CircleArea(float R)
{
	const float PI = 3.141592653589793238;
	return (PI * pow(R, 2));
}

void PrintResult(float Area)
{
	cout << "\n The Area = " << Area << endl;
}

int main()
{
	PrintResult(CircleArea(ReadNumbers()));
	return 0;
}