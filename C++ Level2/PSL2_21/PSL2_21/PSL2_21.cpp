#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

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

char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case SmallLetter:
		return char(RandomNumber(97, 122));
	case CapitalLetter:
		return char(RandomNumber(65, 90));
	case SpecialCharacter:
		return char(RandomNumber(33, 47));
	case Digit:
		return char(RandomNumber(48, 57));
	}
}

string GenerateWord(enCharType CharTyper,short Length)
{
	string Word = "";
	for (int i = 1; i <= Length; i++)
	{
		Word += GetRandomCharacter(CharTyper);
	}
	return Word;
}

string GenerateKey()
{
	string GenKey = "";
	for (int i = 1; i <= 4; i++)
	{
		GenKey += GenerateWord(enCharType::CapitalLetter, 4);
		if (i <= 3)
		{
			GenKey += "-";
		}
	}
	return GenKey;
}

void PrintGenerateKey(int Number)
{
	cout << endl;
	for (int i = 1; i <= Number; i++)
	{
		if (i < 10)
			cout << " Key [" << i << "]   : " << GenerateKey() << endl;
		else if (i >= 10 && i < 100)
			cout << " Key [" << i << "]  : " << GenerateKey() << endl;
		else
			cout << " Key [" << i << "] : " << GenerateKey() << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	PrintGenerateKey(ReadPositiveNumber("Please Enter The Number Of Generate Keys You Need ? "));
	return 0;
}