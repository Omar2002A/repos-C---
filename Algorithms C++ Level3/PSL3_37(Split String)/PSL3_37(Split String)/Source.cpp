#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
	cout << "\nEnter a string : \n";
	string str;
	getline(cin, str);
	return str;
}

vector<string> SplitString(string str, string delimiter)
{
	vector<string> vString;
	short pos = 0;
	string word;

	while ((pos = str.find(delimiter)) != string::npos)
	{
		word = str.substr(0, pos);
		if (word != "")
			vString.push_back(word); // Add the word to the vector
		str.erase(0, pos + delimiter.length());
	}
	if (str != "")
		vString.push_back(str); // Add the last word to the vector
	return vString;
}

int main()
{
	vector<string> vString;

	vString = SplitString(ReadString(), " ");
	cout << "\nTokens = " << vString.size() << endl;

	for (string& str : vString)
		cout << str << endl;

	system("pause>0");
}