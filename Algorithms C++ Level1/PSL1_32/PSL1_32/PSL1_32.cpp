#include <iostream>
#include <cmath>
using namespace std;

int ReadNumbers()
{
	int Number;
	cout << "Enter Number ? \n";
	cin >> Number;
	return Number;
}

int ReadPower()
{
	int Power;
	cout << "Enter Power ? \n";
	cin >> Power;
	return Power;
}

int CalculatNumberOfPower(int N, int P)
{
	/*if (P == 0)
		return 1;*/

	int Multi = 1;
	for (int i = 1; i <= P; i++)
	{
		Multi = Multi * N;
	}
	return Multi;
}

void PrintResult(int Multiple)
{
	cout << "The Number Of The Power Your Entered = " << Multiple << endl;
}

int main()
{
	int n = 0;
	int p = 0;
	PrintResult(CalculatNumberOfPower(ReadNumbers(), ReadPower()));
	return 0;
}