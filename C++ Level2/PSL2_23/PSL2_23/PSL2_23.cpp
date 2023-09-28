#include <iostream>
#include <cstdlib>
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

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLenght)
{
	cout << "\nEnter number of elements : \n";
	cin >> arrLenght;

	for (int i = 0; i < arrLenght; i++)
		arr[i] = RandomNumber(1, 100);
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

	int arr[100], arrLenght;

	FillArrayWithRandomNumbers(arr, arrLenght);

	cout << "Array Elements : ";
	PrintArray(arr, arrLenght);

	return 0;
}