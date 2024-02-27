#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumber(short From, short To) {
	return rand() % (To - From + 1) + From;
}

void FillMatricesWithRandomNumber(int arr[3][3], short Rows, short Cols) {
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

void MultiplyMatrix(int arr1[3][3], int arr2[3][3], int arrResult[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrResult[i][j] = arr1[i][j] * arr2[i][j];
		}
	}
}

int main() {
	srand((unsigned)time(NULL));

	int arr1[3][3], arr2[3][3], arrResult[3][3];
	short Rows = 3, Cols = 3;

	FillMatricesWithRandomNumber(arr1, Rows, Cols);
	FillMatricesWithRandomNumber(arr2, Rows, Cols);
	cout << "\n The following is a 3x3 matrix number : \n";
	PrintMatrix(arr1, Rows, Cols);
	cout << "\n The following is a 3x3 matrix number : \n";
	PrintMatrix(arr2, Rows, Cols);

	MultiplyMatrix(arr1, arr2, arrResult, Rows, Cols);
	cout << "\n The following is a result : \n";
	PrintMatrix(arrResult, Rows, Cols);

	system("pause>0");
}