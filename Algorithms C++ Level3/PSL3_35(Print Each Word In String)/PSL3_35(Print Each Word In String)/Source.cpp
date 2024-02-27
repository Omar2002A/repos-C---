#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string str;
	cout<<"\nEnter a string: ";
	getline(cin, str);
	return str;
}

void PrintEachWordInString(string str)
{
	/*cout << "\nYour String Word : \n";
	for (short i = 0; i < str.length(); i++)
	{
		string word = "";
		while (str[i] != ' ' && i < str.length())
		{
			word += str[i];
			i++;
		}
		cout<<word<<endl;
	}*/

	string delimiter = " ";
	short pos = 0;
	string token;
	while ((pos = str.find(delimiter)) != string::npos) {
		token = str.substr(0, pos);
		if (token != "")
			cout << token << endl;
		str.erase(0, pos + delimiter.length());
	}
	cout << str << endl;

}

int main()
{
	PrintEachWordInString(ReadString());
	system("pause>0");
}