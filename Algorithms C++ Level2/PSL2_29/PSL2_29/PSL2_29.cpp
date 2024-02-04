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
	return (rand() % (To - From + 1) + From);
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	cout << "\n Enter number of elements : \n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
{
	int Counter = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (CheckPrime(arrSource[i]) == enPrimeOrNot::Prime)
		{
			arrDestination[Counter] = arrSource[i];
			Counter++;
		}
	}
	arr2Length = --Counter;
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength;
	FillArrayWithRandomNumbers(arr, arrLength);

	int arr2[100], arr2Length = 0;
	CopyOnlyPrimeNumbers(arr, arr2, arrLength, arr2Length);

	cout << "\n Array 1 elements : \n";
	PrintArray(arr, arrLength);
	
	cout << "\n Prime Numbers in Array2 : \n";
	PrintArray(arr2, arr2Length);

	return 0;
}