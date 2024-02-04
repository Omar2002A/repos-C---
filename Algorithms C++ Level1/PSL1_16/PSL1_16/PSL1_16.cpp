#include <iostream>
#include <cmath>
using namespace std;

void ReadNumbers(float& Side, float& Diagonal)
{
	cout << "Enter The Side ? \n";
	cin >> Side;

	cout << "Enter The Diagonal ? \n";
	cin >> Diagonal;
	cout << "\nTHX\n*********************" << endl;
}

float CalculateRectangleAriaBySideAndDiagonal(float Side, float Diagonal)
{
	return (Side * (sqrt(pow(Diagonal, 2) - pow(Side, 2))));
}

void PrintResult(float Area)
{
	cout << "Rectangle Aria By Side And Diagonal = " << Area << endl;
}

int main()
{
	float S, D;
	ReadNumbers(S, D);
	PrintResult(CalculateRectangleAriaBySideAndDiagonal(S, D));
}