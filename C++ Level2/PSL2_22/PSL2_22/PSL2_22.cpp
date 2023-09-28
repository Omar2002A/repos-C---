#include <iostream>
using namespace std;

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

void ReadArray(int arr[100], int& arrLength)
{
	cout << "\n Enter Number Of Elements : \n";
	cin >> arrLength;

	//arrLength = ReadPositiveNumber(" Enter Number Of Elements :");

	cout << "\n Enter Arry Elements : \n";
	for (int i = 1; i <= arrLength; i++)
	{
		cout << "Element [" << i << "] : ";
		cin >> arr[i - 1];
	}
	cout << endl;
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 1; i <= arrLength; i++)
	{
		cout << arr[i - 1] << " ";
	}
	cout << endl;
}

int TimesRepeated(int Number, int arr[100], int arrLenght)
{
	int Count = 0;
	for (int i = 1; i <= arrLenght; i++)
	{
		if (Number == arr[i - 1])
			Count++;
	}
	return Count;
}

int main()
{
	int arr[100], arrLength, NumberToCheck;

	ReadArray(arr, arrLength);
	NumberToCheck = ReadPositiveNumber("Enter the number you want to check ? ");
	cout << "Original array : ";
	PrintArray(arr, arrLength);
	cout << "\n Number " << NumberToCheck << " is repeated " 
		<< TimesRepeated(NumberToCheck, arr, arrLength) << " time(s)\n";
	return 0;
}