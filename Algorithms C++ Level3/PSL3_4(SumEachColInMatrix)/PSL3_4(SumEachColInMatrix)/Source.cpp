#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int RandomNumber(short From, short To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	cout << "\n The following is a 3x3 matrix random number : \n";
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << endl;
	}
}

int ColSum(int arr[3][3], short Rows, short ColsNumber) {
	int Sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		Sum += arr[i][ColsNumber];
	}
	return Sum;
}

void PrintEachColSum(int arr[3][3], short Rows, short Cols) {
	cout << "\n The the following are the sum of each col in the matrix : \n";
	for (short i = 0; i < Cols; i++)
	{
		cout << "Col " << i + 1 << " Sum = " << ColSum(arr, Rows, i) << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));
	
	int arr[3][3];
	short Rows = 3, Cols = 3;

	FillMatrixWithRandomNumber(arr, Rows, Cols);
	PrintMatrix(arr, Rows, Cols);
	PrintEachColSum(arr, Rows, Cols);

	system("pause>0");
}