#include <iostream>
#include <string>

using namespace std;

string ReadString() {
	string str;
	cout << "\nEnter Your Text : \n";
	getline(cin, str);
	return str;
}

string LowerFirstLetter(string str) {
	bool IsFirstLetter = true;
	for (short i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && IsFirstLetter)
			str[i] = tolower(str[i]);
		IsFirstLetter = (str[i] == ' ' ? true : false);
	}
	return str;
}

int main() {
	string S = ReadString();
	cout << "\nString After Conversion : \n";

	S = LowerFirstLetter(S);
	cout << S << endl;

	system("pause>0");
}