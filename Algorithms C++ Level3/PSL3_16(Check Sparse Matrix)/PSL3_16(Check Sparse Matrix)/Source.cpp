#include <iostream>

using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++)
		{
			printf("  %0*d   ", 2, arr[i][j]);
		}
		cout << endl;
	}
}

int CounterNumberInMatrix(int arr[3][3], short Rows, short Cols, int Number) {
	int Num = 0;
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++)
		{
			if (arr[i][j] == Number)
				Num++;
		}
	}
	return Num;
}

bool CheckSparseMatrix(int arr[3][3], short Rows, short Cols) {
	int NumberInMatrix = Rows * Cols;
	int HalfNumber = NumberInMatrix / 2;
	
	return (CounterNumberInMatrix(arr, Rows, Cols, 0) >= (HalfNumber));
}

int main() {
	int Matrix1[3][3] = { {0,0,12},{9,9,1},{0,0,9} }; 
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (CheckSparseMatrix(Matrix1, 3, 3))
		cout << "\nYes : It's Sparse :) \n";
	else
		cout << "No : It's Not Sparse :( \n";

	system("pause>0");
}