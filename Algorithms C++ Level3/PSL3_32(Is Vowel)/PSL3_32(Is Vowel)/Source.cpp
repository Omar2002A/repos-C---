#include <iostream>
#include <string>

using namespace std;

char ReadChar() {
	char C;
	cout << "\nEnter Your Character ? \n";
	cin >> C;
	return C;
}

bool IsVowel(char C)
{
	C = tolower(C);
	return ((C == 'a') || (C == 'e') || (C == 'i') || (C == 'o') || (C == 'u'));
}

int main() {
	char C = ReadChar();
	if (IsVowel(C))
		cout << "\nYes Letter \'" << C << "\' Is Vowel :) \n";
	else
		cout << "\nNo Letter \'" << C << "\' Is Not Vowel :( \n";

	system("pause>0");
}