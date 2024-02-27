#include <iostream>

using namespace std;

void PrintFibonacciSeriesUsingLoop(short Number) {
	int FNumber = 0, Prev2 = 0, Prev1 = 1;
	cout << " 1  ";
	for (short i = 1; i < Number; ++i)
	{
		FNumber = Prev2 + Prev1;
		cout << FNumber << "  ";
		Prev2 = Prev1;
		Prev1 = FNumber;
	}
}

int main() {
	PrintFibonacciSeriesUsingLoop(10);

	system("pause>0");
}