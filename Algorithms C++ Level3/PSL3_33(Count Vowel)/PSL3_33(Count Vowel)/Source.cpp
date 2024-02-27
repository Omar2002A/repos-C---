#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string str;
	cout << "\nEnter Your Text : \n";
	getline(cin, str);
	return str;
}

bool IsVowel(char C)
{
	C = tolower(C);
	return ((C == 'a') || (C == 'u') || (C == 'e') || (C == 'i') || (C == 'o'));
}

short CountVowel(string str)
{
	short Count = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (IsVowel(str[i]))
			Count++;
	}
	return Count;
}

int main()
{
	string str;
	str = ReadString();
	cout << "\nNumber Of Vowels Is : " << CountVowel(str) << endl;

	system("pause>0");
}