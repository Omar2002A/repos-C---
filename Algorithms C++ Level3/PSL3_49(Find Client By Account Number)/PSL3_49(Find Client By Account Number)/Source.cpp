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

vector<string> SplitString(string str, string delimiter)
{
	vector<string> vString;
	short Pos = 0;
	string word;
	while ((Pos = str.find(delimiter)) != string::npos)
	{
		word = str.substr(0, Pos);
		if (word != "")
			vString.push_back(word);
		str.erase(0, Pos + delimiter.length());
	}
	if (str != "")
		vString.push_back(str);

	return vString;
}

sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.PhoneNumber = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);

	return Client;
}

vector<sClient> LoadClientsDataFromFile(string FileName)
{
	vector<sClient> vClients;
	
	fstream MyFile;
	MyFile.open(FileName, ios::in); // Open file for reading
	if (MyFile.is_open())
	{
		string Line;
		sClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	else
	{
		cout << "Error : Unable to open file " << FileName << endl;
	}
	return vClients;
}

void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the details of the client : \n\n";
	cout << "Account Number : " << Client.AccountNumber << endl;
	cout << "Pin Code : " << Client.PinCode << endl;
	cout << "Name : " << Client.Name << endl;
	cout << "Phone Number : " << Client.PhoneNumber << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, sClient& Client)
{
	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	for (sClient C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

string ReadClientAccountNumber()
{
	string AccountNumber;
	cout << "\nEnter the account number of the client : ";
	cin >> AccountNumber;
	return AccountNumber;
}

int main()
{
	sClient Client;
	string AccountNumber = ReadClientAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, Client))
		PrintClientCard(Client);
	else
		cout << "\nClient With Account Number (" << AccountNumber << ") Is Not Found!";

	system("pause>0");
}