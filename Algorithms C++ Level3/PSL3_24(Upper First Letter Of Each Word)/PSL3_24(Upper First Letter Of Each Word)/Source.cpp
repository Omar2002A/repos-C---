#include <iostream>
#include <string>

using namespace std;

string Readstring() {
	string S1;
	cout << "\nEnter Your Text ? \n";
	getline(cin, S1);
	return S1;
}

string UpperFirstLetterOfEachWord(string Str) {
	bool IsFirstLetter = true;
	for (short i = 0; i < Str.length(); i++)
	{
		if (Str[i] != ' ' && IsFirstLetter)
			Str[i] = toupper(Str[i]);
		IsFirstLetter = (Str[i] == ' ' || Str[i] == '-' ? true : false);
	}
	return Str;
}

int main() {
	string S = Readstring();
	cout << "\nString after conversion : \n";

	S = UpperFirstLetterOfEachWord(S);
	cout << S << endl;

	system("pause>0");
}