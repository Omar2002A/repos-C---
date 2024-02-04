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
	return (rand() % (To - From + 1) + From);
}

void Swap(int& A, int& B)
{
	int Temp = 0;
	Temp = A;
	A = B;
	B = Temp;
}

void FillArrayWith1toN(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = i + 1;
}

void ShuffleArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
	}
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

	int arr[100];
	int arrLength = ReadPositiveNumber("\nEnter number of elements ? ");

	FillArrayWith1toN(arr, arrLength);
	cout << "\nArray elements before shuffle : \n";
	PrintArray(arr, arrLength);

	ShuffleArray(arr, arrLength);
	cout << "\nArray elements after shuffle : \n";
	PrintArray(arr, arrLength);

	return 0;
}