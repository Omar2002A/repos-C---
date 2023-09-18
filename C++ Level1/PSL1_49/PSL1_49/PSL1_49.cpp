#include <iostream>
using namespace std;

string ReadPinCode()
{
	string PinCode;
	cout << "Enter PIN Code : ";
	cin >> PinCode;
	return PinCode;
}

bool LogIn()
{
	string PinCode;
	
	do
	{
		PinCode = ReadPinCode();
		if (PinCode == "1234")
		{
			return 1;
		}
		else
		{
			cout << "\nWrong PIN\n";
			system("color 4F");
		}


	} while (PinCode != "1234");
	return 0;
}

int main()
{
	if (LogIn())
	{
		system("color 2F");
		cout << "\nYour account balance is " << 7500 << endl;
	}
	return 0;
}