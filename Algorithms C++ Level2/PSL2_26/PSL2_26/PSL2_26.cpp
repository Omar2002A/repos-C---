#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	return (rand() % (To - From + 1) + From);
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLenght)
{
	cout << "\n Enter Number Of Element ? \n";
	cin >> arrLenght;

	for (int i = 0; i < arrLenght; i++)
		arr[i] = RandomNumber(1, 100);
}	

void PrintArray(int arr[100], int arrLenght)
{
	for (int i = 0; i < arrLenght; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int SumArray(int arr[100], int arrLenght)
{
	int Sum = 0;
	for (int i = 0; i < arrLenght; i++)
		Sum += arr[i];
	return Sum;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLenght;
	FillArrayWithRandomNumbers(arr, arrLenght);
	cout << "\n Elements of array : ";
	PrintArray(arr, arrLenght);
	cout << "\n  The Sum Of Elements = " << SumArray(arr, arrLenght) << endl;

	return 0;
}