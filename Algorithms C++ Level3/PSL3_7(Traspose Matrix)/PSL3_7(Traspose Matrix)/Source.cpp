#include <iostream>

using namespace std;

void FillMatrixWithOrderedNumber(int arr[3][3], short Rows, short Cols) {
	int order = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			order++;
			arr[i][j] = order;
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	cout << "\n The following is a 3x3 ordered matrix : \n";
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << arr[i][j] << "     ";
		}
		cout << endl;
	}
}

void PrintTrasposeMatrix(int arr[3][3], short Rows, short Cols) {
	cout << "\n The following is the traspose matrix : \n";
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << arr[j][i] << "     ";
		}
		cout << endl;
	}
}

void TrasposeMatrix(int arr[3][3], int arrTraspose[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrTraspose[i][j] = arr[j][i];
		}
	}
}

int main() {
	int arr[3][3];
	int Rows = 3, Cols = 3;
	int arrTraspose[3][3];

	FillMatrixWithOrderedNumber(arr, Rows, Cols);
	PrintMatrix(arr, Rows, Cols);
	PrintTrasposeMatrix(arr, Rows, Cols);

	cout << "\n An Other Way : \n";
	TrasposeMatrix(arr, arrTraspose, Rows, Cols);
	PrintMatrix(arrTraspose, Rows, Cols);

	system("pause>0");
}