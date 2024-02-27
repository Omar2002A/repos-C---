#include <iostream>
#include <string>

using namespace std;

string TrimLeft(string str)
{
	for (short i = 0; i < str.length(); i++)
	{
		if (str[i]!=' ')
			return str.substr(i, str.length() - i);
	}
	return "";
}

string TrimRight(string str)
{
	for (short i = str.length(); i > 0; i--)
	{
		if (str[i] != ' ')
			return str.substr(0, i + 1);
	}
	return "";
}

string Trim(string str)
{
	return TrimRight(TrimLeft(str));
}

int main()
{
	string str = "   Hello World   ";
	cout << "Trim Left : " << TrimLeft(str) << endl;
	cout << "Trim Right : " << TrimRight(str) << endl;
	cout << "Trim : " << Trim(str) << endl;
	system("pause>0");
}