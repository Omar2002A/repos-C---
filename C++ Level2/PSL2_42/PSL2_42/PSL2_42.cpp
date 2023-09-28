#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
	cout << "Enter number of elements : ";
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

int OddCount(int arr[100], int arrLength)
{
	int Counter = 0;
	for (int i = 0; i < arrLength; i++)
		if (arr[i] % 2 != 0)
			Counter++;
	return Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0;

	FillArrayWithRandomNumber(arr, arrLength);

	cout << "\nArray elements : \n";
	PrintArray(arr, arrLength);

	cout << "\nOdd numbers count is : " << OddCount(arr, arrLength) << endl;

	return 0;
}