#include <iostream>
using namespace std;

void ReadGrades(float Grades[3])
{
	cout << "Enter Mark1 ? ";
	cin >> Grades[0];

	cout << "Enter Mark2 ? ";
	cin >> Grades[1];

	cout << "Enter Mark3 ? ";
	cin >> Grades[2];
}

float CalculateAvgFunction(float Grades[3])
{

	return (Grades[0] + Grades[1] + Grades[2]) / 3;

}

void PrintGrades(float Grades[3])
{

	cout << "********************\n";
	cout << "The AVG = " << CalculateAvgFunction(Grades);

}

int main()
{

	float Grades[3];
	ReadGrades(Grades);
	PrintGrades(Grades);

}