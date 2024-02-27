#include <iostream>
#include <string>

using namespace std;

string ReadString() {
	string str;
	cout << "\nEnter Your Text : \n";
	getline(cin, str);
	return str;
}

char InvertLetterCase(char C) {
	return isupper(C) ? tolower(C) : toupper(C);
}

string InvertAllLetterCase(string str) {
	for (short i = 0; i < str.length(); i++)
	{
		str[i] = InvertLetterCase(str[i]);
	}
	return str;
}

int main() {
	string str = ReadString();
	cout << "\nText after inverting all letters case : \n";
	str = InvertAllLetterCase(str);
	cout << str << endl;

	system("pause>0");
}