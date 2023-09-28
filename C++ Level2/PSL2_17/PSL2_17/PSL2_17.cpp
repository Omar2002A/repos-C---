#include <iostream>
using namespace std;

string ReadPassword()
{
	string Pass;
	cout << "Enter a-3Letter Password(All Capital) : ";
	cin >> Pass;
	return Pass;
}

bool GuessPassword(string OriginalPassword)
{
	int Counter = 0;
	string Word = "";
	for (int a = 65; a <= 90; a++)
	{
		for (int b = 65; b <= 90; b++)
		{
			for (int c = 65; c <= 90; c++)
			{
				Counter++;
				
				Word += char(a);
				Word += char(b);
				Word += char(c);

				cout << "Trial [" << Counter << "] : " << Word << endl;

				if (Word == OriginalPassword)
				{
					cout << " Password is " << Word << "\n Found after " << Counter << " Trial(s)" << endl;
					return true;
				}
				Word = "";
			}
		}
	}
	return false;
}

int main()
{
	GuessPassword(ReadPassword());
	return 0;
}