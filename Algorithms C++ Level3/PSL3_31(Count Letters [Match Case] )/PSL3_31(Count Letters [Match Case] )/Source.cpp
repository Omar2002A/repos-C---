#include <iostream>
#include <string>

using namespace std;

string ReadString() {
	string str;
	cout << "\nEnter Your Text : \n";
	getline(cin, str);
	return str;
}

char ReadChar() {
	char character;
	cout << "\nEnter Your Character : \n";
	cin >> character;
	return character;
}

short CountLetter(string str, char cha, bool MatchCase = true) {
	short Counter = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (MatchCase)
		{
			if (str[i] == cha)
				Counter++;
		}
		else
		{
			if (toupper(str[i]) == toupper(cha))
				Counter++;
		}
	}
	return Counter;
}

char InvertLettr(char cha)
{
	return (isupper(cha) ? tolower(cha) : toupper(cha));
}

int main() {
	string str = ReadString();
	char C = ReadChar();
	cout << "\n\nLetter \'" << C << "\' Count = " << CountLetter(str, C);
	cout << "\n\nLetter \'" << C << "\' Or \'" << InvertLettr(C) << "\' Count = " << CountLetter(str, C, false);

	system("pause>0");
}