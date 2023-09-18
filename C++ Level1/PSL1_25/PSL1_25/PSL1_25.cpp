#include <iostream>
using namespace std;

int ReadAge()
{
	int Age;
	cout << "Enter Your Age ? \n";
	cin >> Age;
	cout << endl;
	return Age;
}

bool ValidateNumberInRange(int Number, int From, int To)
{
	if (Number >= From && Number <= To)
		return true;
	else
		return false;
}

int ReadUntilAgeBetween(int From, int To)
{
	int Age = 0;
	do
	{
		Age = ReadAge();

	} while (!ValidateNumberInRange(Age, 18, 45));
	return Age;
}

void PrintResult(int Age)
{
	cout << "\n Your Age : " << Age << endl;
}

int main()
{
	PrintResult(ReadUntilAgeBetween(18, 45));
	return 0;
}