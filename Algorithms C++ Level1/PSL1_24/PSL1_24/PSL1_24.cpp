#include <iostream>
using namespace std;

int ReadAge()
{
	int Age;
	cout << "Enter Your Age ? \n";
	cin >> Age;
	cout << "\n" << endl;
	return Age;
}

bool ValidateNumberInRange(int Number, int From, int To)
{
	return (Number >= From && Number <= To);
}

void PrintResult(int Age)
{
	if (ValidateNumberInRange(Age, 18, 45))
		cout << "\n is a valid Age :) " << endl;
	else
		cout << "\n is invalid Age :( " << endl;
}

int main()
{
	PrintResult(ReadAge());
	return 0;
}