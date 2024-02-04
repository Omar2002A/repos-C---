#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharType { SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
	return (rand() % (To - From + 1) + From);
}

char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case SamallLetter:
		return char(RandomNumber(97, 122));
	case CapitalLetter:
		return char(RandomNumber(65, 90));
	case SpecialCharacter:
		return char(RandomNumber(33, 47));
	case Digit:
		return char(RandomNumber(48, 57));
	}
}

string GenerateWord(enCharType CharType, short Length)
{
	string Word = "";
	for (int i = 1; i <= Length; i++)
	{
		Word += GetRandomCharacter(CharType);
	}
	return Word;
}

string GenerateKey()
{
	string Key = "";
	for (int i = 1; i <= 4; i++)
	{
		Key += GenerateWord(enCharType::CapitalLetter, 4);
		if (i <= 3)
			Key += "-";
	}
	return Key;
}

void FillArrayWithKeys(string arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = GenerateKey();
}

void PrintStringArray(string arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << "Array[" << i << "] : " << arr[i] << endl;
	}
}

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

int main()
{
	srand((unsigned)time(NULL));

	string arr[100];
	int arrLength = 0;
	arrLength = ReadPositiveNumber("How many keys do you want to generate ? ");
	
	FillArrayWithKeys(arr, arrLength);
	cout << "\nArray Elements : \n\n";
	PrintStringArray(arr, arrLength);

	return 0;
}