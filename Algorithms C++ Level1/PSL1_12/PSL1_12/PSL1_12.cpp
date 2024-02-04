#include <iostream>
using namespace std;

void ReadNumbers(int& Num1, int& Num2, int& Num3)
{
	cout << "Enter First Number ? \n";
	cin >> Num1;

	cout << "Enter Second Number ? \n";
	cin >> Num2;

	cout << "Enter Third Number ? \n";
	cin >> Num2;
}

int MaxOf3Numbers(int Num1, int Num2, int Num3)
{
	/*if ((Num1 > Num2) && (Num1 > Num3))
		return Num1;
	else if ((Num2 > Num1) && (Num2 > Num3))
		return Num2;
	else
		return Num3;*/

	if (Num1 > Num2)
		if (Num1 > Num3)
			return Num1;
		else
			return Num3;
	else
		if (Num2 > Num3)
			return Num2;
		else
			return Num3;

}

void PrintMaxNum(int Max)
{
	cout << "\n The Max Number = " << Max << endl;
}

int main()
{
	int Number1, Number2, Number3;
	ReadNumbers(Number1, Number2, Number3);
	PrintMaxNum(MaxOf3Numbers(Number1, Number2, Number3));
}