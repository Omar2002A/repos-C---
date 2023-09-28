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

int MaxNumberInArray(int arr[100],int arrLenght)
{
	int Max = 0;
	for (int i = 0; i < arrLenght; i++)
	{
		if (arr[i] > Max)
			Max = arr[i];
	}
	return Max;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength;
	FillArrayWithRandomNumbers(arr, arrLength);
	cout << "\nArry Elements : ";
	PrintArray(arr, arrLength);
	cout << "\n Max Number is : " << MaxNumberInArray(arr, arrLength) << endl;
	return 0;
}