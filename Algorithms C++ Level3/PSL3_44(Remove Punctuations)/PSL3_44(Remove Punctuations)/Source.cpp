#include <iostream>
#include <string>

using namespace std;

string RemovePunctuationsFromString(string str)
{
	string S = "";
	for (short i = 0; i < str.length(); i++)
	{
		if (!ispunct(str[i]))
			S += str[i];
	}
	return S;
}

int main()
{
	string S1 = "Welcome to Jordan, Jordan is a nice country; it's amazing.";     
	cout << "Original String : \n" << S1;     
	cout << "\n\nPauncuations Removed : \n" << RemovePunctuationsFromString(S1);     
	
	system("pause>0");
}