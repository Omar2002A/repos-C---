#include <iostream>

using namespace std;

int RandomNumber(short From, short To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
		for (short j = 0; j < Cols; j++)
			arr[i][j] = RandomNumber(1, 10);
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

int CountNumberInMatrix(int arr[3][3], short Rows, short Cols, int Number) {
	int Num = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (arr[i][j] == Number)
				Num++;
		}
	}
	return Num;
}


int main() {
	srand((unsigned)time(NULL));

	int arr[3][3];
	short Rows = 3, Cols = 3;

	FillMatrixWithRandomNumber(arr, Rows, Cols);
	PrintMatrix(arr, Rows, Cols);

	int Number;
	cout << "\n Enter The Number To Count In Matrix ? \n  ";
	cin >> Number;

	cout << "\n Number " << Number << " Count in matrix is " << CountNumberInMatrix(arr, Rows, Cols, Number);

	system("pause>0");
}