#include <iostream>

using namespace std;

int RandomNumber(short From, short To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumber(int Matrix[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Matrix[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("  %0*d   ", 2, Matrix[i][j]);
		}
		cout << endl;
	}
}

int SumOfMatrix(int arr[3][3], short Rows, short Cols) {
	int Sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Sum += arr[i][j];
		}
	}
	return Sum;
}

bool CheckMatrixEquality(int arr1[3][3], int arr2[3][3], short Rows, short Cols) {
	return (SumOfMatrix(arr1, Rows, Cols) == SumOfMatrix(arr2, Rows, Cols));
}

int main() {
	srand((unsigned)time(NULL));

	int arr[3][3], arr2[3][3];
	short Rows = 3, Cols = 3;

	FillMatrixWithRandomNumber(arr, Rows, Cols);
	cout << "\n The following is a 3x3 matrix1 : \n";
	PrintMatrix(arr, Rows, Cols);

	FillMatrixWithRandomNumber(arr2, Rows, Cols);
	cout << "\n The following is a 3x3 matrix2 : \n";
	PrintMatrix(arr2, Rows, Cols);

	if (CheckMatrixEquality(arr, arr2, Rows, Cols))
		cout << "\n Yes : Both Matrix Are Equal.\n";
	else
		cout << "\n No : Matrix Are Not Equal.\n";
	
	system("pause>0");
}