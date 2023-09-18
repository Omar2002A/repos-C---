#include <iostream>
using namespace std;

enum enGrade { A = 1, B = 2, C = 3, D = 4, E = 5, F = 6 };

int ReadNumberInRange(int From,int To)
{
	int Grade;
	cout << "Enter Your Grade : ";
	cin >> Grade;

	if (Grade<From || Grade>To)
	{
		while (Grade<From || Grade>To)
		{
			cout << "Enter Invaalid Grade Between 0~100 ? \n";
			cin >> Grade;
		}
	}

	return Grade;
}

enGrade CheckGrade(int Grade)
{
	if (Grade >= 90)
		return enGrade::A;
	else if (Grade >= 80)
		return enGrade::B;
	else if (Grade >= 70)
		return enGrade::C;
	else if (Grade >= 60)
		return enGrade::D;
	else if (Grade >= 50)
		return enGrade::E;
	else
		return enGrade::F;
}

char WhatResult(enGrade chr)
{
	if (chr == enGrade::A)
		return 'A';
	else if (chr == enGrade::B)
		return 'B';
	else if (chr == enGrade::C)
		return 'C';
	else if (chr == enGrade::D)
		return 'D';
	else if (chr == enGrade::E)
		return 'E';
	else
		return 'F';
}

void PrintResult(char R)
{
	cout << R << endl;
}

int main()
{
	PrintResult(WhatResult(CheckGrade(ReadNumberInRange(0,100))));
	return 0;
}