#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> SplitString(string str, string delimiter)
{
	vector<string> result;
	int pos = 0;
	while ((pos = str.find(delimiter)) != string::npos)
	{
		result.push_back(str.substr(0, pos));
		str.erase(0, pos + delimiter.length());
	}
	if (str != "")
		result.push_back(str); // last word
	return result;
}

string JoinString(vector<string> str, string delimiter)
{
	string result = "";
	for (int i = 0; i < str.size(); i++)
	{
		result += str[i];
		if (i != str.size() - 1)
			result += delimiter;
	}
	return result;
}

string LowerAllString(string str)
{
	for (short i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}

string ReplaceWord(string str, string word, string replaceword, bool MatchCase = true)
{
	vector<string> vString = SplitString(str, " ");
	for (string& S : vString)
	{
		if (MatchCase)
		{
			if (S == word)
				S = replaceword;
		}
		else
		{
			if (LowerAllString(S) == LowerAllString(word))
				S = replaceword;
		}
	}
	return JoinString(vString, " ");
}

int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "jordan";
	string ReplaceTo = "USA";   
	cout << "\nOriginal String:\n" << S1;    
	cout << "\n\nReplace with match case: ";     
	cout << "\n" << ReplaceWord(S1, StringToReplace, ReplaceTo);
	cout << "\n\nReplace with dont match case: ";     
	cout << "\n" << ReplaceWord(S1, StringToReplace, ReplaceTo, false);

	system("pause>0");
}