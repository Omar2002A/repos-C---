#include <iostream>
#include <string>

using namespace std;

string ReadString() {
	string str;
	cout << "\nEnter Your Text : \n";
	getline(cin, str);
	return str;
}

string UpperAllLetters(string str) {
	for (short i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}

string LowerAllLetters(string str) {
	for (short i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}

int main() {
	string str = ReadString();

	cout << "\nString after Upper : \n";
	str = UpperAllLetters(str);
	cout << str << endl;

	cout << "\nString after Lower : \n";
	str = LowerAllLetters(str);
	cout << str << endl;

	system("pause>0");
}