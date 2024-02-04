#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLenght)
{
	cout << "\nEnter number of elements : \n";
	cin >> arrLenght;

	for (int i = 0; i < arrLenght; i++)
		arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int MinNumberInArray(int arr[100], int arrLength)
{
	int Min = arr[0];
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] < Min)
			Min = arr[i];
	}
	return Min;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLenght;
	FillArrayWithRandomNumbers(arr, arrLenght);
	cout << "Elements of array : ";
	PrintArray(arr, arrLenght);
	cout << "The Min Value : " << MinNumberInArray(arr, arrLenght) << endl;

	return 0;
}