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
	cout << endl;
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int SumArray(int arr[100], int arrLength)
{
	int Sum = 0;
	for (int i = 0; i < arrLength; i++)
		Sum += arr[i];
	return Sum;
}

float AVGArray(int arr[100], int arrLength)
{
	return (float)SumArray(arr, arrLength) / arrLength;	
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength;
	FillAraayWithRandomNumbers(arr, arrLength);
	cout << "\nThe Element : ";
	PrintArray(arr, arrLength);
	cout << "\n Average of all number is : " << AVGArray(arr, arrLength) << endl;

	return 0;
}