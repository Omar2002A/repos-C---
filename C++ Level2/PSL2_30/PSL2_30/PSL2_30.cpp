#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	return (rand() % (To - From + 1) + From);
}

int ReadPositiveNumber(string Messege)
{
	int Number = 0;
	while (Number <= 0)
	{
		cout << Messege << endl;
		cin >> Number;
	}
	return Number;
}

void FillArrayWithRandomNumbers(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
	cout << endl;
}

void SumArray(int arr[100], int arr2[100], int arrSum[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arrSum[i] = arr[i] + arr2[i];
	}
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arr2[100], arrSum[100];
	int arrLength = ReadPositiveNumber("Enter number of elements ? ");
	
	FillArrayWithRandomNumbers(arr, arrLength);
	FillArrayWithRandomNumbers(arr2, arrLength);
	SumArray(arr, arr2, arrSum, arrLength);

	cout << "\nArray 1 elements : \n";
	PrintArray(arr, arrLength);

	cout << "\nArray 2 elements : \n";
	PrintArray(arr2, arrLength);

	cout << "\nSum of array1 and array2 elements : \n";
	PrintArray(arrSum, arrLength);
}