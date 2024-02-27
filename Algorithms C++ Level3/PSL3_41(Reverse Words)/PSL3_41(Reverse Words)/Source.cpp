#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
	cout << "\nEnter a string: ";
	string str;
	getline(cin, str);
	return str;
}

vector<string> SplitString(string str, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string word;
	while ((pos = str.find(Delim)) != string::npos)
	{
		word = str.substr(0, pos);
		if (word != "")
			vString.push_back(word);
		str.erase(0, pos + Delim.length());
	}
	if (str != "")
		vString.push_back(str); // Add the last word

	return vString;
}

string ReverseWords(string str)
{
	vector<string> vString;
	string str2="";

	vString = SplitString(str, " ");
	
	vector<string>::iterator iter = vString.end();
	while (iter != vString.begin())
	{
		iter--;
		str2 += *iter + " ";
	}
	str2=str2.substr(0, str2.length() - 1); // Remove the last space
	return str2;
}

int main()
{
	string str = ReadString();
	cout << "\n\nReversed string : " << ReverseWords(str) << endl;
	system("pause>0");
}