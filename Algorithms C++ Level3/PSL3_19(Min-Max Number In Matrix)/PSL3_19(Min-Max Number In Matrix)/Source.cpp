#include <iostream>

using namespace std;

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

int MaxNumberInMatrix(int arr[3][3], short Rows, short Cols) {
	int Number = arr[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (arr[i][j] > Number)
				Number = arr[i][j];
		}
	}
	return Number;
}

int MinNumberInMatrix(int arr[3][3], short Rows, short Cols) {
	int Number = arr[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (arr[i][j] < Number)
				Number = arr[i][j];
		}
	}
	return Number;
}

int main() {
	int Matrix1[3][3] = { {77,5,12},{22,20,6},{14,3,9} };
	
	int Rows = 3, Cols = 3;

	cout << "\n The following is a 3x3 matrix : \n";
	PrintMatrix(Matrix1, Rows, Cols);

	cout << "\n\nMax Number is : ";
	cout << MaxNumberInMatrix(Matrix1, Rows, Cols);

	cout << "\n\nMix Number is : ";
	cout << MinNumberInMatrix(Matrix1, Rows, Cols);
	
	system("pause>0");
}