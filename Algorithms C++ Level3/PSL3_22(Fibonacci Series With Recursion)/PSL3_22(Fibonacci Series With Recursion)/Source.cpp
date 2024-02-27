#include <iostream>

using namespace std;

void PrintFibonacciSeriesUsingRecursion(short Number, short Prev1, short Prev2) {
	int FNumber = 0;

	if (Number > 0)
	{
		FNumber = Prev1 + Prev2;
		Prev2 = Prev1;
		Prev1 = FNumber;
		cout << FNumber << "   ";
		PrintFibonacciSeriesUsingRecursion(Number - 1, Prev1, Prev2);
	}
	
}

int main() {
	PrintFibonacciSeriesUsingRecursion(10, 0, 1);

	system("pause>0");
}