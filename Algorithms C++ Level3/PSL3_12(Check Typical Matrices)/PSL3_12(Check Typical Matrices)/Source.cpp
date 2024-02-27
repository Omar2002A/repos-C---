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

bool CheckTypicalMatrix(int arr1[3][3], int arr2[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (arr1[i][j] != arr2[i][j])
				return false;
		}
	}
	return true;
}

int main() {
	srand((unsigned)time(NULL));

	int arr1[3][3], arr2[3][3];
	short Rows = 3, Cols = 3;

	FillMatrixWithRandomNumber(arr1, Rows, Cols);
	FillMatrixWithRandomNumber(arr2, Rows, Cols);

	cout << "\nThe following is a 3x3 matrix1 : \n";
	PrintMatrix(arr1, Rows, Cols);

	cout << "\nThe following is a 3x3 matrix1 : \n";
	PrintMatrix(arr2, Rows, Cols);

	if (CheckTypicalMatrix(arr1, arr2, Rows, Cols))
		cout << "\nYES : both martices are typical.\n";
	else
		cout << "\nNo : Matrices Are Not Equal.\n";

	system("pause>0");
}