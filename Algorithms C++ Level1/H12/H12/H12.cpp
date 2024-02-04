#include <iostream>
using namespace std;
void MySumProcedure()
{
	
	short Num1, Num2;

	cout << "Enter First Number : ";
	cin >> Num1;

	cout << "Enter Second Number : ";
	cin >> Num2;

	cout << "*******************************\n";
	cout << "		  " << Num1 + Num2 << endl;

}

short MySumFunction(short Num1, short Num2)
{

	return Num1 + Num2;

}

int main()
{

	short Num1, Num2;

	cout << "Enter First Number : ";
	cin >> Num1;

	cout << "Enter Second Number : ";
	cin >> Num2;
	cout << "********************\n";
	cout << MySumFunction(Num1, Num2) << endl;

}