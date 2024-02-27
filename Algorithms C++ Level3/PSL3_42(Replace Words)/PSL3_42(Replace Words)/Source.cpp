#include <iostream>
#include <string>

using namespace std;

string ReplaceWordInStringUsingBuiltInFunction(string str, string StringToReolace, string ReplaceTo)
{
	short pos = str.find(StringToReolace);

	while (pos != string::npos)
	{
		str = str.replace(pos, StringToReolace.length(), ReplaceTo);
		pos = str.find(StringToReolace); // Find next occurrence
	}
	return str;
}

int main()
{
	string str = "Hello World, Hello C++, Hello C++";
	string StringToReolace = "Hello";
	string ReplaceTo = "Hi";

	cout << "Original String : " << str << endl;
	cout << "String after replace : ";
	cout << ReplaceWordInStringUsingBuiltInFunction(str, StringToReolace, ReplaceTo) << endl;

	system("pause>0");
}