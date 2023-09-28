#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number = 0;
	cout << "Enter a number ? ";
	cin >> Number;
	return Number;
}

void FillArray(int arr[100], int& arrLength)
{
	cout << "Enter number of elements : ";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
		arr[i] = ReadNumber();
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
	cout << endl;
}

bool IsPalindromeArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		if (arr[i] != arr[arrLength - i - 1])
			return false;
	return true;
}

int main()
{
	int arr[100], arrLength = 0;

	FillArray(arr, arrLength);

	cout << "\nArray Elements:\n";    
	PrintArray(arr, arrLength); 

	if (IsPalindromeArray(arr, arrLength))
		cout << "\nYes array is Palindrome\n";
	else        
		cout << "\nNO array is NOT Palindrome\n";

	return 0;
}