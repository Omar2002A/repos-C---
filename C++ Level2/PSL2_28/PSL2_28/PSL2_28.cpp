#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	return (rand() % (To - From + 1) + From);
}

void FillAraayWithRandomNumbers(int arr[100], int& arrLength)
{
	cout << "\n Enter number of elements ? \n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
		arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void CoppyArray(int arrSource[100], int arrDestination[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arrDestination[i] = arrSource[i];
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength;
	FillAraayWithRandomNumbers(arr, arrLength);
	int arr2[100];
	CoppyArray(arr, arr2, arrLength);
	
	cout << "\n Array 1 Elements : \n";
	PrintArray(arr, arrLength);
	
	cout << "\n Array 2 Elements after copy : \n";
	PrintArray(arr2, arrLength);

	return 0;
}