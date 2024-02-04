#include <iostream>
using namespace std;

enum enReversed { False = 0, True = 1 };

enReversed Reversed()
{
	bool Reverse;
	cout << "Do You Want Reverse ? \n";
	cin >> Reverse;


	if (Reverse)
		return enReversed::True;
	else
		return enReversed::False;
	
}

struct stInfo
{
	string FirstName;
	string LastName;
};

stInfo ReadInfo()
{
	stInfo Info;
	
	cout << "Enter Your First Name ? \n";
	cin >> Info.FirstName;

	cout << "Enter Your Last Name ? \n";
	cin >> Info.LastName;

	return Info;
}

string GetFullName(stInfo Info,bool Reversed)
{
	string FullName = "";

	if (Reversed)
		FullName = Info.LastName + " " + Info.FirstName;
	else
		FullName = Info.FirstName + " " + Info.LastName;
	return FullName;
}

void PrintFullName(string FullName)
{
	cout << "\n Your Name Is :" << FullName << endl;
}

int main()
{
	PrintFullName(GetFullName(ReadInfo(),Reversed()));
	return 0;
}