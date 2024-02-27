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

short CountLetter(string str, char cha) {
	short Counter = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (str[i] == cha)
			Counter++;
	}
	return Counter;
}

int main() {
	string str = ReadString();
	char C = ReadChar();
	cout << "\n\nLetter \'" << C << "\' Count = " << CountLetter(str, C);

	system("pause>0");
}