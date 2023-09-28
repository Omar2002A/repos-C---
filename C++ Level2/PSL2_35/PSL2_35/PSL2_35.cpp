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

bool isNumberInArray(int& Number, int arr[100], int arrLength)
{
	cout << "\nPlease enter a number to search for? \n";
	cin >> Number;

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == Number)
			return true;
	}
	return false;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0, Number = 0;

	FillArrayWithRandomNumber(arr, arrLength);

	cout << "\nArray 1 elements : \n";
	PrintArray(arr, arrLength);

	bool TRUE = isNumberInArray(Number, arr, arrLength);
	cout << "\nNumber you are looking for is : " << Number << endl;

	if (TRUE)
		cout << "\n Yes, The number is found :)\n";
	else
		cout << "\n No, The number is not found :(\n";

	return 0;
}