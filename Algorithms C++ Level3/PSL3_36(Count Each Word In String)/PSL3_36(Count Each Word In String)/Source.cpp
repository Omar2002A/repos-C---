#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string str;
	cout << "\nEnter a string ? \n";
	getline(cin, str);
	return str;
}

short CountWordsInString(string str)
{
	short count = 0;
	short pos = 0;
	string delimiter = " ";
	string word;
	while ((pos = str.find(delimiter)) != string::npos)
	{
		word = str.substr(0, pos);
		if(word!="")
			count++; // Counting each word
		str.erase(0, pos + delimiter.length());
	}
	if (str != "")
		count++; // Counting last word
	return count;
}

int main()
{
	string str = ReadString();
	short count = CountWordsInString(str);
	cout << "Number of words in the string = " << count << endl;
	system("pause>0");
}