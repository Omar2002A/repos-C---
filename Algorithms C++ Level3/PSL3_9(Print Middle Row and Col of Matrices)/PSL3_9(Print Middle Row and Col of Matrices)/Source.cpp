#include <iostream>


using namespace std;

int RandomNumber(short From, short To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("  %0*d   ", 2, arr[i][j]);
		}
		cout << endl;
	}
}

int	Middle(int Anywhere) {
	return Anywhere / 2;
}

void MiddleOfRows(int arr[3][3], short Rows, short Cols) {
	for (short j = 0; j < Cols; j++)
	{
		printf("  %0*d   ", 2, arr[Middle(Rows)][j]);
	}
	cout << endl;
}

void MiddleOfCols(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		printf("  %0*d   ", 2, arr[i][Middle(Cols)]);
	}
	cout << endl;
}

int main() {
	srand((unsigned)time(NULL));

	int arr[3][3];
	int Rows = 3, Cols = 3;
	
	FillMatrixWithRandomNumber(arr, Rows, Cols);
	cout << "\n The following is a 3x3 matrix : \n";
	PrintMatrix(arr, Rows, Cols);
	cout << "\n Middle row of matrix : \n";
	MiddleOfRows(arr, Rows, Cols);
	cout << "\n Middle cols of matrix : \n";
	MiddleOfCols(arr, Rows, Cols);
}