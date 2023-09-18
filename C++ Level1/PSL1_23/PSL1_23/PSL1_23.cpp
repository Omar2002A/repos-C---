#include <iostream>
#include <cmath>
using namespace std;

void ReadNumbers(float& A, float& B, float& C)
{
	cout << "Enter A ? \n";
	cin >> A;

	cout << "Enter B ? \n";
	cin >> B;

	cout << "Enter C ? \n";
	cin >> C;

	cout << "\n THX\n" << endl;
}

float CircleAreaInscribedInAnIsoscelesTriangleFunction(float A, float B, float C)
{
	const float PI = 3.14159265359;
	float P = (A + B + C) / 2;
	float T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));
	float Area = PI * pow(T, 2);
	return Area;
}

void PrintResult(float Area)
{
	cout << "\n The Area = " << Area << endl;
}

int main()
{
	float A, B, C;
	ReadNumbers(A, B, C);
	PrintResult(CircleAreaInscribedInAnIsoscelesTriangleFunction(A, B, C));

	return 0;
}