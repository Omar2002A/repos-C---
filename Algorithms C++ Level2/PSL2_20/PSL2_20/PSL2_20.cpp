#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

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

void PrintRandom()
{
	cout << "\n" << GetRandomCharacter(enCharType::SmallLetter) << endl;
	cout << GetRandomCharacter(enCharType::CapitalLetter) << endl;
	cout << GetRandomCharacter(enCharType::SpecialCharacter) << endl;
	cout << GetRandomCharacter(enCharType::Digit) << endl;
}

int main()
{
	srand((unsigned)time(NULL));
	PrintRandom();
	return 0;
}