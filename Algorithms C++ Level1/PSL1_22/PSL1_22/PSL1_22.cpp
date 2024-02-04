#include <iostream>
using namespace std;

void ReadNumbers(float& A, float& B)
{
	cout << "Enter a : ";
	cin >> A;

	cout << "Enter b : ";
	cin >> B;

	cout << "\nTHX" << endl;
}

float circleAreaInscribedInAnIsoscelestriangleformula(float a, float b)
{
	const float PI = 3.14159265359;
	return (PI * ((pow(b, 2)) / 4) * (((2.0 * a) - b) / ((2.0 * a) + b)));
}

void PrintResults(float Area)
{
	cout << "\n The Area = " << Area << endl;
}

int main()
{
	float A, B;
	ReadNumbers(A, B);
	PrintResults(circleAreaInscribedInAnIsoscelestriangleformula(A, B));
	return 0;
}