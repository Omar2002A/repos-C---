#include <iostream>
#include <cstdlib>
using namespace std;

enum enPrimeOrNot { Prime = 1, NotPrime = 2 };

enPrimeOrNot CheckPrime(int Number)
{
	int M = round(Number / 2);
	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)
			return enPrimeOrNot::NotPrime;
	}
	return enPrimeOrNot::Prime;
}

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
	cout << "Please enter number of elements : ";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
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

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
	arr[arrLength] = Number;
	arrLength++;
}

void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (CheckPrime(arrSource[i]) == enPrimeOrNot::Prime)
			AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arr2[100], arrLength = 0, arr2Length = 0;

	FillArrayWithRandomNumber(arr, arrLength);

	CopyPrimeNumbers(arr, arr2, arrLength, arr2Length);

	cout << "\nArray 1 elements : \n";
	PrintArray(arr, arrLength);
	cout << "\n Array 2 Prime numbers : \n";
	PrintArray(arr2, arr2Length);

	return 0;
}