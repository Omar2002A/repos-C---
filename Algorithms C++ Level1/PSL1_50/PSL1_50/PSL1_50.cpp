#include <iostream>
using namespace std;

string ReadPinCode()
{
	string PIN;
	cout << "Enter Your PIN : ";
	cin >> PIN;
	return PIN;
}

bool LogIn()
{
	string PIN;
	int Counter = 3;
	do
	{
		Counter--;
		PIN = ReadPinCode();
		if (PIN == "1234")
		{
			return 1;
		}
		else
		{
			system("color 4F");
			cout << "\nWrong PIN, you have " << Counter << " more tries!";

		}

	} while (Counter > 0 && PIN != "1234");
	return 0;
}

int main()
{
	if (LogIn())
	{
		system("color 2F");
		cout << "\n Your account balance is " << 7500 << "\n";
	}
	else
	{
		cout << "\n\n Your Card Blocked Call The Bank For Help. :( " << endl;
	}
	return 0;
	
}