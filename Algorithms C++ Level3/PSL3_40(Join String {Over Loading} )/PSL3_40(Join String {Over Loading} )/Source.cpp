#include <iostream>
#include <string>
#include <vector>

using namespace std;

string JoinString(vector<string> vString, string Delim)
{
	string str = "";
	for (string& S : vString)
		str = str + S + Delim;
	return str.substr(0, str.length() - Delim.length());
}

string JoinString(string arrString[], short Size, string Delim)
{
	string str= "";
	for (short i = 0; i < Size; i++)
		str = str + arrString[i] + Delim;
	return str.substr(0, str.length() - Delim.length());
}

int main()
{
	vector<string> vString = { "Hello", "World", "This", "is", "a", "test" };
	string arrString[] = { "Hello", "World", "This", "is", "a", "test" };
	string Delim = " ";

	cout << "\nVector after join : \n";
	cout << JoinString(vString, Delim) << endl;
	
	cout << "\nArray after join : \n";
	cout << JoinString(arrString, 6, Delim) << endl;

	system("pause>0");
}