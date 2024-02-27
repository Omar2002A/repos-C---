#include <iostream>
#include <string>

using namespace std;

char ReadChar()
{
	char Ch;
	cout << "\nPlease Enter a Charcter ? \n";
	cin >> Ch;
	return Ch;
}

char InvertLetterCase(char C) {
	return (isupper(C) ? tolower(C) : toupper(C));
}

int main() {
	char C = ReadChar();
	cout << "\nChar after inverting case : \n";
	C = InvertLetterCase(C);
	cout << C << endl;

	system("pause>0");
}