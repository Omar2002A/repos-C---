#include <iostream>

using namespace std;

int RandomNumber(short From, short To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrixWhithRandomNumber(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int aarr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("  %0*d   ", 2, aarr[i][j]);
		}
		cout << endl;
	}
}

int	SumMatrix(int arr[3][3], short Rows, short Cols)
{
	int SUjm = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			SUjm += arr[i][j];
		}
	}
	return SUjm;
}

int main() {
	srand((unsigned)time(NULL));

	int arr[3][3];
	short Rows = 3, Cols = 3;

	FillMatrixWhithRandomNumber(arr, Rows, Cols);
	cout << "\n The following is a 3x3 matrix : \n";
	PrintMatrix(arr, Rows, Cols);
	cout << "\n The Sum Of Matrix = " << SumMatrix(arr, Rows, Cols) << endl;

	system("pause>0");
}