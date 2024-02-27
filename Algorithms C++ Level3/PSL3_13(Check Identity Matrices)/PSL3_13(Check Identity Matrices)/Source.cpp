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
			arr[i][j] = RandomNumber(0, 1);
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

bool CheckIdentityMatrix(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && arr[i][j] != 1)
				return false;
			else if (i != j && arr[i][j] != 0)
				return false;
		}
	}
	return true;
}

int main() {
	srand((unsigned)time(NULL));

	int arr[3][3];
	short Rows = 3, Cols = 3;

	int arr2[3][3] = { {1,0,0},{0,1,0},{0,0,1} };

	FillMatrixWithRandomNumber(arr, Rows, Cols);
	cout << "\nThe following is a 3x3 matrix : \n";
	PrintMatrix(arr, Rows, Cols);

	if (CheckIdentityMatrix(arr, Rows, Cols))
		cout << "\nYes : Matrix is identity.\n";
	else
		cout << "\nNo : Matrix isn't identity.\n";

	system("pause>0");
}