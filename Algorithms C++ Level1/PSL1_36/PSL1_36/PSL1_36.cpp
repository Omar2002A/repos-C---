#include <iostream>
using namespace std;

enum enOperatorType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

float ReadNumber(string Messege)
{
	int N;
	cout << Messege << endl;
	cin >> N;
	return N;
}

enOperatorType ReadOpType()
{
	char OT = '+';
	cout << "Enter +,-,*,/ ??? \n";
	cin >> OT;
	return (enOperatorType)OT;
}

float Calculate(float N1, float N2, enOperatorType OPT)
{
	switch (OPT)
	{
	case Add:
		return N1 + N2;
	case enOperatorType::Subtract:
		return N1 - N2;
	case Multiply:
		return N1 * N2;
	case Divide:
		return N1 / N2;
	default:
		return N1 + N2;
	}
}

void PrintResult(float R)
{
	cout << R << endl;
}

int main()
{
	PrintResult(Calculate(ReadNumber("Enter First Number ? "), ReadNumber("Enter Second Number ? "), ReadOpType()));
	return 0;
}