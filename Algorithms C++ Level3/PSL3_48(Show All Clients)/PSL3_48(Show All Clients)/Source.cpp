#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

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

sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.PhoneNumber = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]); // Convert string to double

	return Client;
}

vector <sClient> LoadClientsDataFromFile(string FileName)
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
	return vClients;
}

void PrintClientRecord(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.PhoneNumber;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData(vector<sClient> vClients)
{
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n________________________________________________________________________________________________\n" << endl;
	cout << "| " << setw(15) << left << "Account Number";
	cout << "| " << setw(10) << left << "Pin Code";
	cout << "| " << setw(40) << left << "Client Name";
	cout << "| " << setw(12) << left << "Phone Number";
	cout << "| " << setw(12) << left << "Balance";
	cout << "\n________________________________________________________________________________________________\n" << endl;
	for (sClient Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}
	cout << "\n________________________________________________________________________________________________\n" << endl;
}

int main()
{
	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	PrintAllClientsData(vClients);
	system("pause>0");
}