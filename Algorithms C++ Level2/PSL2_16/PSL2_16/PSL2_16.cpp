#include <iostream>
using namespace std;

void PrintLetterFromAAAtoZZZ()
{
	string Word = "";
	cout << "\n";
	for (int a = 65; a <= 90; a++)
	{
		for (int b = 65; b <= 90; b++)
		{
			for (int c = 65; c <= 90; c++)
			{
				cout << char(a) << char(b) << char(c) << endl;
				/*Word += char(a);
				Word += char(b);
				Word += char(c);
				cout << Word << endl;
				Word = "";*/
			}
		}
	}
}

int main()
{
	PrintLetterFromAAAtoZZZ();
	return 0;
}