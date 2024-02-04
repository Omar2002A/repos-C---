#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
	cout << "Enter number of elements ? \n";
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

short FindNumberPositionInArray(int& Number, int arr[100], int arrLength)
{
	cout << "\nPlease enter a number to search for ? \n";
	cin >> Number;

	for (int i = 0; i < arrLength; i++)
	{
		if (Number == arr[i])
			return i;
	}
	return -1;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0, Number = 0;
	
	FillArrayWithRandomNumber(arr, arrLength);

	cout << "\nArray 1 elements : \n";
	PrintArray(arr, arrLength);

	short NumberPosition = FindNumberPositionInArray(Number, arr, arrLength);
	cout << "\nNumber you are looking for is : " << Number << endl;

	if (NumberPosition == -1)
		cout << "The number is not found :( \n";
	else
		cout << "The number found at position : " << NumberPosition 
		<< "\nThe number found its order : " << NumberPosition + 1 << endl;

	return 0;
}