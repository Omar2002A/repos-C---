#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
const string ClientsFileName = "Clients.txt";

void ShowMainMenue();
void ShowTransactionsScreen();

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double AccountBalance;
	bool MarkForDelete = false;
};

vector<string> SplitString(string str, string Dilimiter = "#//#")
{
	vector<string> vClientData;
	short Pos = 0;
	string word;
	while ((Pos = str.find(Dilimiter)) != string::npos)
	{
		word = str.substr(0, Pos);
		if (word != "")
			vClientData.push_back(word);
		str.erase(0, Pos + Dilimiter.length());
	}
	if (str != "")
		vClientData.push_back(str);
	return vClientData;
}

string ConvertRecordToLineData(sClient Client, string Seperator = "#//#")
{
	string DataLine = "";
	DataLine += Client.AccountNumber + Seperator;
	DataLine += Client.PinCode + Seperator;
	DataLine += Client.Name + Seperator;
	DataLine += Client.PhoneNumber + Seperator;
	DataLine += to_string(Client.AccountBalance);
	return DataLine;
}

sClient ConvertLineToRecordData(string Line, string Seperator = "#//#")
{
	sClient Clients;
	vector<string> vDataClient = SplitString(Line, Seperator);
	Clients.AccountNumber = vDataClient[0];
	Clients.PinCode = vDataClient[1];
	Clients.Name = vDataClient[2];
	Clients.PhoneNumber = vDataClient[3];
	Clients.AccountBalance = stod(vDataClient[4]);
	return Clients;

}

bool ClientsExistsByAccountNumber(string AccountNumber, string FileName)
{
	vector<sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in); // Open File for Reading

	if (MyFile.is_open())
	{
		string Line;
		sClient Client;
		
		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecordData(Line);
			if (Client.AccountNumber == AccountNumber)
			{
				MyFile.close();
				return true;
			}
			vClients.push_back(Client);
		}

		MyFile.close();
	}
	return false;
}

sClient ReadNewClient()
{
	sClient Client;
	cout << "Enter Account Number ? ";

	getline(cin >> ws, Client.AccountNumber);

	while (ClientsExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
	{
		cout << "\nClient With (" << Client.AccountNumber << ") already exists, Enter another Account Number ? ";
		getline(cin >> ws, Client.AccountNumber);
	}

	cout << "Enter PinCode ? ";
	getline(cin, Client.PinCode);
	
	cout << "Enter Name ? ";
	getline(cin, Client.Name);
	
	cout << "Enter Phone Number ? ";
	getline(cin, Client.PhoneNumber);

	cout << "Enter Account Balance ? ";
	cin >> Client.AccountBalance;

	return Client;
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
			Client = ConvertLineToRecordData(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
}

void PrintClientRecordLine(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.PhoneNumber;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowAllClientsScreen()
{
	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	cout << "\n\t\t\t\t\tClients List (" << vClients.size() << ") Client(s).";
	cout << "\n________________________________________________________________________________________________\n";
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";    
	cout << "| " << left << setw(40) << "Client Name";   
	cout << "| " << left << setw(12) << "Phone";     
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n________________________________________________________________________________________________\n";
	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else 
		for (sClient C : vClients)
		{
			PrintClientRecordLine(C);
			cout << endl;
		}
	cout << "\n________________________________________________________________________________________________\n";
}

void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the information for Clients : \n";
	cout << "-----------------------------------";
	cout << "\nAccount Number  : " << Client.AccountNumber;
	cout << "\nPin Code        : " << Client.PinCode;
	cout << "\nName            : " << Client.Name;
	cout << "\nPhone Number    : " << Client.PhoneNumber;
	cout << "\nAccount Balance : " << Client.AccountBalance;
	cout << "\n-----------------------------------\n";
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

sClient ChangeClientRecord(string AccountNumber)
{
	sClient Client;
	
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

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClient)
{
	for (sClient& C : vClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

vector<sClient> SaveClientsDataToFile(string FileName, vector<sClient> vClient)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); // Open File for Writing
	if (MyFile.is_open())
	{
		for (sClient C : vClient)
		{
			if (C.MarkForDelete == false)
			{
				MyFile << ConvertRecordToLineData(C) << endl;
			}

		}

		MyFile.close();
	}
	return vClient;
}

void AddDataLineToFile(string FileName, string DataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open())
	{
		MyFile << DataLine << endl;
		MyFile.close();
	}
}

void AddNewClient()
{
	sClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLineData(Client));
}

void AddNewClients()
{
	char AddMoer = 'y';
	do
	{

		cout << "Adding New Client : \n\n";

		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients ? Y/N ? ";
		cin >> AddMoer;

	} while (AddMoer == 'y' || AddMoer == 'Y');
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
		cout << "\n\nAre you sure you want to delete this client ? y/n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveClientsDataToFile(ClientsFileName, vClients);
			vClients = LoadClientsDataFromFile(ClientsFileName);
			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	
	}
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
		
		cout << "\n\nAre you sure you want update this client ? y/n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			for (sClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}
			SaveClientsDataToFile(ClientsFileName, vClients);

			cout << "\n\nClient Updated Successfully."; 
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!"; 
		return false;
	}
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";
	cout << "Enter Account Number ? ";
	cin >> AccountNumber;
	return AccountNumber;
}

void ShowDeleteClientScreen()
{
	cout << "\n-----------------------------------\n";     
	cout << "\tDelete Client Screen";    
	cout << "\n-----------------------------------\n";
	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);
}

void ShowUpdateClientScreen()
{
	cout << "\n-----------------------------------\n";    
	cout << "\tUpdate Client Info Screen";     
	cout << "\n-----------------------------------\n";
	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowAddNewClientsScreen()
{
	cout << "\n-----------------------------------\n";    
	cout << "\tAdd New Clients Screen";    
	cout << "\n-----------------------------------\n";     
	
	AddNewClients();
}

void ShowFindClientScreen()
{
	cout << "\n-----------------------------------\n";     
	cout << "\tFind Client Screen";    
	cout << "\n-----------------------------------\n";

	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	
	sClient Client;

	string AccountNumber = ReadClientAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
		PrintClientCard(Client);
	else
		cout << "\nClient with Account Number (" << AccountNumber << ") is not found!";
}

void ShowEndScreen()
{
	cout << "\n-----------------------------------\n";   
	cout << "\tProgram Ends :-)";     
	cout << "\n-----------------------------------\n";
}

enum enMainMenueOptions { eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5, eTransactions = 6, eExit = 7 };

void GoBackToMainMenue()
{
	cout << "\n\nPress any key to go back to Main Menue...";     
	system("pause>0");     
	ShowMainMenue();
}

enum enTransactionOptions { eDeposit = 1, eWithdraw = 2, eTotalBalance = 3, eBackToMainMenue = 4 };

short ReadTransactiosOption()
{
	short Choise = 0;
	cout << "Choose what do you want to do ? [1 to 4] ? ";
	cin >> Choise;
	return Choise;
}

void GoBackToTransactiosMenue()
{
	cout << "\n\nPress any key to go back to Transaction Menue...";     
	system("pause>0");     
	ShowTransactionsScreen();
}

bool DepositAmountToClientByAccountNumber(string AccountNumber, double Amount, vector<sClient> vClients)
{
	char Answer = 'n';

	cout << "\n\nAre you sure you want to deposit this amount to the client ? y/n ? ";
	cin >> Answer;

	if (Answer == 'Y' || Answer == 'y')
	{
		for (sClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.AccountBalance += Amount;
				SaveClientsDataToFile(ClientsFileName, vClients);
				cout << "\n\nAmount Deposited Successfully.\n";
				cout << "New Balance is : " << C.AccountBalance;

				return true;
			}
		}
		return false;
	}
}

bool WithdrawAmountToClientByAccountNumber(string AccountNumber, double Ammount, vector<sClient> vClients)
{
	char Answer = 'n';

	cout << "\n\nAre you sure you want to deposit this amount to the client ? y/n ? ";
	cin >> Answer;

	if (Answer == 'Y' || Answer == 'y')
	{
		for (sClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.AccountBalance -= Ammount;
				SaveClientsDataToFile(ClientsFileName, vClients);
				cout << "\n\nAmount Withdrawed Successfully.\n";
				cout << "New Balance is : " << C.AccountBalance;

				return true;
			}
		}
		return false;
	}
}

void ShowDepositScreen()
{


	cout << "\n-----------------------------------\n";
	cout << "\tDeposit Screen";
	cout << "\n-----------------------------------\n";

	sClient Client;
	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();

	while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is not found!";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientCard(Client);

	double DepositAmount = 0;
	cout << "Enter Deposit Amount ? ";
	cin >> DepositAmount;

	DepositAmountToClientByAccountNumber(AccountNumber, DepositAmount, vClients);
}

void ShowWithdrawScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\Withdraw Screen";
	cout << "\n-----------------------------------\n";

	sClient Client;
	vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	
	while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is not found!";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientCard(Client);

	double Amount = 0;
	cout << "Enter Withdraw Amount ? ";
	cin >> Amount;

	while (Amount > Client.AccountBalance)
	{
		cout << "Withdraw Amount is greater than the Account Balance, Enter a valid Amount ? ";
		cin >> Amount;
	}

	WithdrawAmountToClientByAccountNumber(AccountNumber, Amount, vClients);

}

void ShowTotalBalanceScreen()
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s)."; 
	
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;  
	
	cout << "| " << left << setw(15) << "Accout Number";    
	cout << "| " << left << setw(40) << "Client Name";    
	cout << "| " << left << setw(12) << "Balance";   
	
	cout << "\n_______________________________________________________";  
	cout << "_________________________________________\n" << endl; 
	
	double TotalBalances = 0; 
	
	if (vClients.size() == 0)         
		cout << "\t\t\t\tNo Clients Available In the System!";
	else 
		for(sClient Client : vClients)
		{ 
			PrintClientRecordLine(Client);
			TotalBalances += Client.AccountBalance;          
			cout << endl;
		}

	cout << "\n_______________________________________________________";    
	cout << "_________________________________________\n" << endl; 
	cout << "\t\t\t\t\t   Total Balances = " << TotalBalances;
}

void PerformTransactionOption(enTransactionOptions TransactionOption)
{
	switch (TransactionOption)
	{
	case eDeposit:
	{
		system("cls");
		ShowDepositScreen();
		GoBackToTransactiosMenue();
		break;
	}
	case eWithdraw:
	{
		system("cls");
		ShowWithdrawScreen();
		GoBackToTransactiosMenue();
		break;
	}
	case eTotalBalance:
	{
		system("cls");
		ShowTotalBalanceScreen();
		GoBackToTransactiosMenue();
		break;
	}
	case eBackToMainMenue: 
	{
		ShowMainMenue();
	}
	}
}

short ReadMainMenueOption()
{
	short Choice = 0;
	cout << "Choose what do you want to do ? [1 to 7] ? ";
	cin >> Choice;
	return Choice;
}

void ShowTransactionsScreen()
{

	system("cls");

	cout << "===============================================" << endl;
	cout << "\t\tTransaction Menu Screen\n";
	cout << "===============================================" << endl;
	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balance.\n";
	cout << "\t[4] Main Menue.\n";
	cout << "===============================================" << endl;
	PerformTransactionOption((enTransactionOptions)ReadTransactiosOption());
}

void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
	switch (MainMenueOption)
	{
	case eListClients:
	{
		system("cls");
		ShowAllClientsScreen();
		GoBackToMainMenue();
		break;
	}
		
	case eAddNewClient:
	{
		system("cls");
		ShowAddNewClientsScreen();
		GoBackToMainMenue();
		break;
	}
		
	case eDeleteClient:
	{
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenue();
		break;
	}
		
	case eUpdateClient:
	{
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenue();
		break;
	}
		
	case eFindClient:
	{
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenue();
		break;
	}

	case eTransactions:
	{
		system("cls");
		ShowTransactionsScreen();
		break;
	}

	case eExit:
	{
		system("cls");
		ShowEndScreen();
		break;
	}

	}
}

void ShowMainMenue()
{
	system("cls");
	cout << "===============================================" << endl;
	cout << "\t\tMain Menu Screen\n";
	cout << "===============================================" << endl;
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info\n";
	cout << "\t[5] Find Client\n";
	cout << "\t[6] Transactions\n";
	cout << "\t[7] Exit.\n";
	cout << "===============================================" << endl;

	PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

int main()
{
	ShowMainMenue();
	system("pause>0");
	return 0;
}