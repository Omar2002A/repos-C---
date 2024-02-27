#include <iostream>

using namespace std;

//int RandomNumber(short From, short To) {
//	return rand() % (To - From + 1) + From;
//}
//
//void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols) {
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			arr[i][j] = RandomNumber(0, 10);
//		}
//	}
//}

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

bool CheckScalarMatrix(int arr[3][3], short Rows, short Cols) {
	
	int FirstDiagElement = arr[0][0];
	
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i != j && arr[i][j] != 0)
				return false;
			else if (i == j && arr[i][j] != FirstDiagElement)
				return false;
		}
	}
	return true;
}

int main() {
	int arr[3][3]= { {9,0,0},{0,9,0},{0,0,9} };

	cout << "\nMatrix1:\n";      
	PrintMatrix(arr, 3, 3);     
	if (CheckScalarMatrix(arr, 3, 3))           
		cout << "\nYES: Matrix is scalar."; 
	else          
		cout << "\nNo: Matrix is NOT scalar.";
	system("pause>0");
}