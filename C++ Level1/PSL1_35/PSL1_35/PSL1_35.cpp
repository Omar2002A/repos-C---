#include <iostream>
using namespace std;

struct stPiggyBankContent
{
	int Penny, Nickel, Dime, Quarter, Dollar;
};

stPiggyBankContent ReadPiggyBankContent()
{
	stPiggyBankContent Info;

	cout << "Enter Penny ? \n";
	cin >> Info.Penny;

	cout << "Enter Nickel ? \n";
	cin >> Info.Nickel;

	cout << "Enter Dime ? \n";
	cin >> Info.Dime;

	cout << "Enter Quarter ? \n";
	cin >> Info.Quarter;

	cout << "Enter Dollar ? \n";
	cin >> Info.Dollar;

	cout << "\n Thx\n" << endl;
	return Info;
}

float CalculateTotalPennies(stPiggyBankContent PiggyBankContent)
{
	return (PiggyBankContent.Penny + 5 * PiggyBankContent.Nickel + 10 * PiggyBankContent.Dime + 25 * PiggyBankContent.Quarter + 100 * PiggyBankContent.Dollar);
}

void PrintResult(float Penny)
{
	cout << "Total Penny = " << Penny << endl;
}

int main()
{
	PrintResult(CalculateTotalPennies(ReadPiggyBankContent()));
	return 0;
}