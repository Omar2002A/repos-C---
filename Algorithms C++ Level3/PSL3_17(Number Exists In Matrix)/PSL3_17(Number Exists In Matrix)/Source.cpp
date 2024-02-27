#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumber(short From, short To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrixWhitRandomNumber(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << endl;
	}
}

bool NumExistsInMatrix(int arr[3][3], short Rows, short Cols, int Number) {
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (arr[i][j] == Number)
				return true;
		}
	}
	return false;
}

int main() {
	srand((unsigned)time(NULL));

	int arr[3][3];
	int Rows = 3, Cols = 3, Number;

	FillMatrixWhitRandomNumber(arr, Rows, Cols);
	PrintMatrix(arr, Rows, Cols);

	cout << "\n Please Enter the number to look for in matrix ? ";
	cin >> Number;

	if (NumExistsInMatrix(arr, Rows, Cols, Number))
		cout << "\n Yes It's There :) \n";
	else
		cout << "\n No It's Not There :( \n";

	system("pause>0");
}