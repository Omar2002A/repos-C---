#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
const string ClientsFileName = "Clients.txt";

struct sClients
{
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double AccountBalance;
	bool MarkForUpdate = false;
};

vector<string> SplitString(string str, string Delimiter)
{
	vector<string> vString;
	short Pos = 0;
	string word;
	while ((Pos = str.find(Delimiter)) != string::npos)
	{
		word = str.substr(0, Pos);
		if (word != "")
			vString.push_back(word);
		str.erase(0, Pos + Delimiter.length());
	}
	if (str != "")
		vString.push_back(str); // Add the last word

	return vString;
}

sClients ConvetLineToRecord(string Line, string Seperator = "#//#")
{
	sClients Client;
	vector<string> vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.PhoneNumber = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);
	return Client;
}

string ConvertRecordToLine(sClients Client, string Seperator = "#//#")
{
	string stClientRecord = "";
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.PhoneNumber + Seperator;
	stClientRecord += to_string(Client.AccountBalance);
	return stClientRecord;
}

vector<sClients> LoadClientDataFromFile(string FileName)
{
	vector<sClients> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in); // Open file for reading
	if (MyFile.is_open())
	{
		string Line;
		sClients Client;
		while (getline(MyFile, Line))
		{
			Client = ConvetLineToRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
}

void PrintClientCard(sClients Client)
{
	cout << "\nThe following is the client's information : \n";
	cout << "Account Number  : " << Client.AccountNumber << endl;
	cout << "Pin Code        : " << Client.PinCode << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone Number    : " << Client.PhoneNumber << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClients> vClients, sClients& Client)
{
	for (sClients C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

sClients ChangeClientRecord(string AccountNumber)
{
	sClients Client;
	Client.AccountNumber = AccountNumber;

	cout << "\n\nEnter PinCode ? ";
	getline(cin >> ws, Client.PinCode);
	cout << "Enter Name ? ";
	getline(cin, Client.Name);
	cout << "Enter Phone Number ? ";
	getline(cin, Client.PhoneNumber);
	cout << "Enter Account Balance ? ";
	cin >> Client.AccountBalance;
	return Client;
}

vector<sClients> SaveClientsDataToFile(string FileName, vector<sClients> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); // Open file for writing

	string DataLine;
	if (MyFile.is_open())
	{
		for (sClients C : vClients)
		{
			if (C.MarkForUpdate == false)
			{
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vClients;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<sClients>& vClients)
{
	sClients Client;
	char Answer;
	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
		cout << "\n\nDo you want to update this client (Y/N) ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			for (sClients& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}
			SaveClientsDataToFile(ClientsFileName, vClients);
			cout<< "\n\nClient has been updated successfully !";
			return true;
		}
	}
	else
	{
		cout << "\nClient with account number (" << AccountNumber << ") is not found :(";
		return false;
	}
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";
	cout << "\nPlease Enter Account Number ? ";
	cin >> AccountNumber;
	return AccountNumber;
}

int main()
{
	string AccountNumber = ReadClientAccountNumber();
	vector<sClients> vClients = LoadClientDataFromFile(ClientsFileName);

	UpdateClientByAccountNumber(AccountNumber, vClients);
	system("pause>0");
}