#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct sClient
{
	string AcountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double AccountBalance;
};

sClient ReadNewClient()
{
	sClient Client;

	cout << "\nEnter Acount Number ? ";
	getline(cin, Client.AcountNumber);
	cout << "\nEnter Pin Code ? ";
	getline(cin, Client.PinCode);
	cout << "\nEnter Name ? ";
	getline(cin, Client.Name);
	cout << "\nEnter Phone Numer ? ";
	getline(cin, Client.PhoneNumber);
	cout << "\nEnter Account Balance ? ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AcountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.PhoneNumber + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

int main()
{
	cout << "\nPlease Enter Client Information : \n\n";

	sClient Client = ReadNewClient();

	cout<< "\n\nClient Information for saving is : \n";
	cout << ConvertRecordToLine(Client);

	system("pause>0");
}