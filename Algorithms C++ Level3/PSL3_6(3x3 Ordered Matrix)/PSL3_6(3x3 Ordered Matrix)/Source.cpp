#include <iostream>

using namespace std;

void FillMatrixWithOrderedNumber(int arr[3][3], short Rows, short Cols) {
	int Order = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Order++;
			arr[i][j] = Order;
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

int main() {
	int arr[3][3];
	int Rows = 3, Cols = 3;

	FillMatrixWithOrderedNumber(arr, Rows, Cols);
	PrintMatrix(arr, Rows, Cols);

	system("pause>0");
}