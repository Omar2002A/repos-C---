#include <iostream>
using namespace std;

void ReadNumbers(float& height, float& base)
{
	cout << "Enter a Height : ";
	cin >> height;

	cout << "Enter a Base : ";
	cin >> base;

	cout << "\nTHX\n" << endl;
}

float CalculateTriangleArea(float height, float base)
{
	return (0.5 * base * height);
}

void PrintResult(float Area)
{
	cout << "\n The Area = " << Area << endl;
}

int main()
{
	float H, B;
	ReadNumbers(H, B);
	PrintResult(CalculateTriangleArea(H, B));
}