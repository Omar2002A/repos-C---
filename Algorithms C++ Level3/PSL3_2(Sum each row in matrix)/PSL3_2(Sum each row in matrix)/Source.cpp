#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int RandomNumber(int From ,int To) {
	int random = rand() % (To - From + 1) + From;
	return random;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++) {
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++) {
			cout << setw(3) << arr[i][j]<<"     ";
		}
		cout << endl;
	}
}

int RowsSum(int arr[3][3], short RowNumber, short cols) {
	int Sum = 0;
	for (short i = 0; i < cols; i++) {
		Sum += arr[RowNumber][i];
	}
	return Sum;
}

void PrintEeachRowSum(int arr[3][3], short rows, short cols) {
	cout << "\nThe following are the sum of each row in the matrix : \n";
	for (short i = 0; i < rows; i++) {
		cout << "Sum of row " << i + 1 << " is: " << RowsSum(arr, i, cols) << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));
	
	int arr[3][3];
	
	FillMatrixWithRandomNumbers(arr, 3, 3);
	
	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);
	
	PrintEeachRowSum(arr, 3, 3);
	system("pause>0");
}