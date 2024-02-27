#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int RandomNumber(short From, short To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	cout << "\n The following is a 3x3 random matrix : \n";
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << endl;
	}
}

int RowsSum(int arr[3][3], short RowNumber, short Cols) {
	int Sum = 0;
	for (short i = 0; i < Cols; i++)
	{
		Sum += arr[RowNumber][i];
	}
	return Sum;
}

void SumMatrixRowsInArray(int arr[3][3], int ArrSum[3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		ArrSum[i] = RowsSum(arr, i, Cols);
	}
}
  
void PrintRowsSumArray(int ArrSum[3], short Rows) {
	cout << "\nThe the following are the sum of each row in the matrix:\n";
	for (short i = 0; i < Rows; i++)
	{
		cout << "\n Row " << i + 1 << " Sum = " << ArrSum[i] << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));

	int arr[3][3];
	int ArrSum[3];
	short Rows = 3, Cols = 3;

	FillMatrixWithRandomNumbers(arr, Rows, Cols);
	PrintMatrix(arr, Rows, Cols);

	SumMatrixRowsInArray(arr, ArrSum, Rows, Cols);
	PrintRowsSumArray(ArrSum, Rows);

	system("pause>0");
	//return 0;
}