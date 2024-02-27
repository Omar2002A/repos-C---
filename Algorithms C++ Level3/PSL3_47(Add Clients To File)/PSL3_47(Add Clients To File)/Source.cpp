#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
const string ClientsFileName = "Clients.txt";

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double AccountBalance;
};

sClient ReadNewClient()
{
	sClient client;
	cout << "\nEnter Account Number : ";
	getline(cin >> ws, client.AccountNumber);
	cout << "\nEnter Pin Code : ";
	getline(cin, client.PinCode);
	cout << "\nEnter Name : ";
	getline(cin, client.Name);
	cout << "\nEnter Phone Number : ";
	getline(cin, client.PhoneNumber);
	cout << "\nEnter Account Balance : ";
	cin >> client.AccountBalance;

	return client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string stClientRecord = "";
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.PhoneNumber + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;
		MyFile.close();
	}
	else
	{
		cout << "\nError : File not found\n" << endl;
	}
}

void AddNewClient()
{
	sClient client = ReadNewClient();
	string stClientRecord = ConvertRecordToLine(client);
	AddDataLineToFile(ClientsFileName, stClientRecord);
}

void AddClients()
{
	char AddMore = 'Y';
	do
	{
		system("cls");
		cout << "\nAdding New Client : \n\n";
		AddNewClient();
		cout << "\nClient Added Successfully, Do you want to add more Clients ? Y/N ? ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

int main()
{
	AddClients();
	system("pause>0");
}