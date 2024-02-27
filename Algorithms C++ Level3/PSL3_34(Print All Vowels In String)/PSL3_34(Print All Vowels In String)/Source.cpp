#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string str;
	cout << "\nEnter Your Text ? \n";
	getline(cin, str);
	return str;
}

bool IsVowels(char C)
{
	C = tolower(C);
	return ((C == 'a') || (C == 'o') || (C == 'i') || (C == 'e') || (C == 'u'));
}

void PrintAllVowels(string str)
{
	for (short i = 0; i < str.length(); i++)
	{
		if (IsVowels(str[i]))
			cout << str[i] << "    ";
	}
}

int main()
{
	string str = ReadString();
	PrintAllVowels(str);

	system("pause>0");
}