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

int main()
{
	vector<string> vString = { "Hello", "World", "This", "is", "a", "test" };
	string Delim = " ";
	cout << "\nJoined String : ";
	cout << JoinString(vString, Delim) << endl;
	system("pause>0");
}