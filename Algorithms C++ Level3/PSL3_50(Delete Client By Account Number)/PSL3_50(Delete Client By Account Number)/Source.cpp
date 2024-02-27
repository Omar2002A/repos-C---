#include <iostream>
#include <fstream>
#include <string>
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
	bool MarkedForDeletion = false;
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

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string stClientRecord = Client.AccountNumber + Seperator + Client.PinCode + Seperator + Client.Name + Seperator + Client.PhoneNumber + Seperator + to_string(Client.AccountBalance);
	return stClientRecord;
}

vector<sClient> LoadClientsDataFromFile(string FileName)
{
	vector<sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

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
	return vClients;
}

void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the details of the client : \n\n";
	cout << "Account Number  : " << Client.AccountNumber << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone Number    : " << Client.PhoneNumber << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client)
{
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
	cout << "\nPlease enter the account number of the client you want to delete : ";
	cin >> AccountNumber;
	return AccountNumber;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkedForDeletion = true;
			return true;
		}
	}
	return false;
}

vector<sClient> SaveClientsDataTofile(string FileName, vector<sClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); // ios::out (Over write the file if it does exist)
	
	string Line;
	if (MyFile.is_open())
	{
		for (sClient C : vClients)
		{
			if (!C.MarkedForDeletion)
			{
				Line = ConvertRecordToLine(C);
				MyFile << Line << endl;
			}
		}
		MyFile.close();
	}
	return vClients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
		cout << "\nAre you sure you want to delete this client? (y/n) : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients); // Mark the client for deletion
			SaveClientsDataTofile(ClientsFileName, vClients); // Save the changes to the file
			
			vClients = LoadClientsDataFromFile(ClientsFileName); // Reload the clients data from the file
			cout << "\n\nClient has been deleted successfully.\n";
			return true;
		}
	}
	else
	{
		cout << "\nClient with account number (" << AccountNumber << ") does not exist.\n";
		return false;
	}
}

int main()
{
	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);
	system("pause>0");
}