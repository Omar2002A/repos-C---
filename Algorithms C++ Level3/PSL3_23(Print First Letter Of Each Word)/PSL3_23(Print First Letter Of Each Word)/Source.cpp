#include <iostream>
#include <string>

using namespace std;

string ReadString() {
	string str;
	cout << "\nPlease Enter Your Text ? \n";
	getline(cin, str);
	return str;
}

void PrintFirstLetterOfEachWord(string str) {
	bool IsFirstLetter = true;
	
	cout << "\nFirst letters of this string : \n";
	for (short i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && IsFirstLetter)
			cout << str[i] << endl;
		IsFirstLetter = (str[i] == ' ' ? true : false);
	}
	
}

int main() {
	PrintFirstLetterOfEachWord(ReadString());
	system("pause>0");
}