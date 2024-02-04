#include <iostream>
using namespace std;

void ReadWidthAndHeight(float& Width, float& Height)
{
	cout << "Enter The Width : ";
	cin >> Width;

	cout << "Enter The Height : ";
	cin >> Height;
	cout << "THX\n********************" << endl;
}

float CalculateRectangleArea(float Width, float Height)
{
	return Width * Height;
}

void PrintResult(float Area)
{
	cout << "\n Rectangle Area = " << Area << endl;
}

int main()
{
	float width, height;
	ReadWidthAndHeight(width, height);
	PrintResult(CalculateRectangleArea(width, height));
	return 0;
}