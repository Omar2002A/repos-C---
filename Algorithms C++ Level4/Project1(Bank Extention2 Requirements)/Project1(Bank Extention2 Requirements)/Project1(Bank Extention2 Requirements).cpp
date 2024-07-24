#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>

using namespace std;

struct stUsers
{
	string UserName;
	string PassWord;
	int Permissions;
	bool MarkForDelete = false;
};

enum enTransactionsMenueOptions { enDeposit = 1, enWithdraw = 2, enShowTotalBalance = 3, enShowMainMenue };

enum enManageUsersMenueOptions { enListUsers = 1, enAddNewUser = 2, enDeleteUser = 3, enUpdateUser = 4, enFindUser = 5, enMainMenue = 6 };

enum enMainMenueOptions { enListClients = 1, enAddNewClient = 2, enDeleteClient = 3, enUpdateClient = 4, enFindClient = 5, enShowTransactionsMenue = 6, enManageUsers = 7, enLogOut = 8 };

enum enMainMenuePermissions { enAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16, pTranactions = 32, pMangeUsers = 64 };

const string ClientsFileName = "Clients.txt";
const string UsersFileName = "Users.txt";

stUsers CurrentUser;

void ShowMainMenue();
void ShowTransactionsMenue();
void ShowManageUsersMenue();
bool CheckAccessPermission(enMainMenuePermissions Permission);
void Login();

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalace;
	bool MarkForDelete = false;
};

vector<string> SplitString(string S, string Delim)
{
	vector<string> vString;

	size_t POS = 0;
	string sWord;

	while ((POS = S.find(Delim)) != std::string::npos)
	{
		sWord = S.substr(0, POS);
		if (sWord != "")
			vString.push_back(sWord);

		S.erase(0, POS + Delim.length());
	}
	if (S != "")
		vString.push_back(S);

	return vString;
}

stUsers ConvertUserLineToRecord(string Line, string Seperator = "#//#")
{
	stUsers User;
	vector<string> vUserData;

	vUserData = SplitString(Line, Seperator);

	User.UserName = vUserData[0];
	User.PassWord = vUserData[1];
	User.Permissions = stoi(vUserData[2]);

	return User;
}

stClient ConvertClientLineToToRecord(string Line, string Seperator = "#//#")
{
	stClient Client;
	vector<string> vClientDate;

	vClientDate = SplitString(Line, Seperator);

	Client.AccountNumber = vClientDate[0];
	Client.PinCode = vClientDate[1];
	Client.Name = vClientDate[2];
	Client.Phone = vClientDate[3];
	Client.AccountBalace = stod(vClientDate[4]);

	return Client;
}

stUsers ConvertUserLinetoRecord2(string Line, string Seperator = "#//#")
{
	stUsers User;
	vector<string> vUserData;

	vUserData = SplitString(Line, Seperator);

	User.UserName = vUserData[0];
	User.PassWord = vUserData[1];
	User.Permissions = stoi(vUserData[2]);

	return User;
}

string ConvertClientRecordToLine(stClient Client, string Seperator = "#//#")
{
	string sClientRecord = "";

	sClientRecord += Client.AccountNumber + Seperator;
	sClientRecord += Client.PinCode + Seperator;
	sClientRecord += Client.Name + Seperator;
	sClientRecord += Client.Phone + Seperator;
	sClientRecord += to_string(Client.AccountBalace);

	return sClientRecord;
}

string ConvertUserRecordToLine(stUsers User, string Seperator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += User.UserName + Seperator;
	stClientRecord += User.PassWord + Seperator;
	stClientRecord += to_string(User.Permissions);

	return stClientRecord;
}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{
	vector<stClient> vClients;

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		stClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertClientLineToToRecord(Line);
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

bool UserExistsByUsername(string UserName, string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		stUsers User;

		while (getline(MyFile, Line))
		{
			User = ConvertUserLineToRecord(Line);
			if (User.UserName == UserName)
			{
				MyFile.close();
				return true;
			}
		}
		MyFile.close();
	}
	return false;
}

stClient ReadNewClient()
{
	stClient Client;

	cout << "Enter Account Number ? ";

	getline(cin >> ws, Client.AccountNumber);

	while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
	{
		cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number ? ";
		getline(cin >> ws, Client.AccountNumber);
	}

	cout << "Enter PinCode ? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name ? ";
	getline(cin, Client.Name);

	cout << "Enter Phone ? ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance ? ";
	cin >> Client.AccountBalace;

	return Client;
}

int ReadPermissionsToSet()
{
	int Permissions = 0;
	char Answer = 'n';

	cout << "\nDo you want to give full access ? y/n ? ";
	cin >> Answer;

	if (Answer == 'Y' || Answer == 'y')
		return -1;

	cout << "\nDo you want to give access to : \n";

	cout << "\nShow Client List ? y/n ? ";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
		Permissions += enMainMenuePermissions::pListClients;

	cout << "\nAdd New Client ? y/n ? ";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
		Permissions += enMainMenuePermissions::pAddNewClient;

	cout << "\nDelete Client ? y/n ? ";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
		Permissions += enMainMenuePermissions::pDeleteClient;

	cout << "\nUpdate Client ? y/n ? ";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
		Permissions += enMainMenuePermissions::pUpdateClient;

	cout << "\nFind Client ? y/n ? ";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
		Permissions += enMainMenuePermissions::pFindClient;

	cout << "\nTransactions ? y/n ? ";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
		Permissions += enMainMenuePermissions::pTranactions;

	cout << "\nManage Users ? y/n ? ";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
		Permissions += enMainMenuePermissions::pMangeUsers;

	return Permissions;
}

stUsers ReadNewUser()
{
	stUsers User;

	cout << "Enter username ? ";
	getline(cin >> ws, User.UserName);

	while (UserExistsByUsername(User.UserName, UsersFileName))
	{
		cout << "\nUser with [" << User.UserName << "] already exists, Enter another username ? ";
		getline(cin >> ws, User.UserName);
	}

	cout << "Enter PassWord ? ";
	getline(cin, User.PassWord);

	User.Permissions = ReadPermissionsToSet();

	return User;
}

vector<stUsers> LoadUsersDataFromFile(string FileName)
{
	vector<stUsers> vUsers;

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		stUsers User;

		while (getline(MyFile, Line))
		{
			User = ConvertUserLineToRecord(Line);
			vUsers.push_back(User);
		}
		MyFile.close();
	}
	return vUsers;
}

vector<stClient> LoadCleintsDataFromFile(string FileName)
{
	vector<stClient> vClients;

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		stClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertClientLineToToRecord(Line);

			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
}

void PrintClientRecordLine(stClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalace;
}

void PrintUserRecordLine(stUsers User)
{
	cout << "| " << setw(15) << left << User.UserName;
	cout << "| " << setw(10) << left << User.PassWord;
	cout << "| " << setw(40) << left << User.Permissions;
}

void PrintClientRecordBalanceLine(stClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(40) << left << Client.Name;  
	cout << "| " << setw(12) << left << Client.AccountBalace;
}

void ShowAccessDeniedMessage()
{
	cout << "\n------------------------------------\n"; 
	cout << "Access Denied, \nYou dont Have Permission To Do this,\nPlease Conact Your Admin."; 
	cout << "\n------------------------------------\n";
}

void ShowAllClientsScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::pListClients))
	{
		ShowAccessDeniedMessage();
		return;
	}

	vector<stClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________"; 
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else
	{
		for (stClient Client : vClients)
		{
			PrintClientRecordLine(Client);
			cout << endl;
		}
	}
	cout << "\n_______________________________________________________";     
	cout << "_________________________________________\n" << endl;
}

void ShowAllUsersScreen()
{
	vector<stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);

	cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") User(s)."; 
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl; 
	cout << "| " << left << setw(15) << "User Name"; 
	cout << "| " << left << setw(10) << "Password"; 
	cout << "| " << left << setw(40) << "Permissions";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	if (vUsers.size() == 0)
		cout << "\t\t\t\tNo Users Available In the System!";
	else
	{
		for (stUsers User : vUsers)
		{
			PrintUserRecordLine(User);
			cout << endl;
		}
	}

	cout << "\n_______________________________________________________"; 
	cout << "_________________________________________\n" << endl;
}

void ShowTotalBalances()
{
	vector<stClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

	cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;   
	cout << "| " << left << setw(15) << "Accout Number"; 
	cout << "| " << left << setw(40) << "Client Name"; 
	cout << "| " << left << setw(12) << "Balance"; 
	cout << "\n_______________________________________________________"; 
	cout << "_________________________________________\n" << endl;

	double TotalBalance = 0;

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else
	{
		for (stClient Client : vClients)
		{
			PrintClientRecordBalanceLine(Client);
			TotalBalance += Client.AccountBalace;

			cout << endl;
		}
	}
	cout << "\n_______________________________________________________"; 
	cout << "_________________________________________\n" << endl; 
	cout << "\t\t\t\t\t   Total Balances = " << TotalBalance;
}

void PrintClientCard(stClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "-----------------------------------";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code     : " << Client.PinCode; 
	cout << "\nName         : " << Client.Name; 
	cout << "\nPhone        : " << Client.Phone; 
	cout << "\nAccount Balance: " << Client.AccountBalace;
	cout << "\n-----------------------------------\n";
}

void PrintUserCard(stUsers User)
{
	cout << "\nThe following are the user details:\n";
	cout << "-----------------------------------";
	cout << "\nUsername    : " << User.UserName;  
	cout << "\nPassword    : " << User.PassWord;
	cout << "\nPermissions : " << User.Permissions;
	cout << "\n-----------------------------------\n"; 
}

bool FindClientByAccountNumber(string AccountNumber, vector<stClient> vClients, stClient& Client)
{
	for (stClient C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

bool FindUserByUsername(string UserName, vector<stUsers>vUsers, stUsers& User)
{
	for (stUsers U : vUsers)
	{
		if (U.UserName == UserName)
		{
			User = U;
			return true;
		}
	}
	return false;
}

bool FindUserByUsernameAndPassword(string UserName, string PassWord, stUsers& User)
{
	vector<stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);

	for (stUsers U : vUsers)
	{
		if (U.UserName == UserName && U.PassWord == PassWord)
		{
			User = U;
			return true;
		}
	}
	return false;
}

stClient ChangeClientRecord(string AccountNumber)
{
	stClient Client;

	Client.AccountNumber = AccountNumber;

	cout << "\n\nEnter PinCode ? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name ? ";
	getline(cin, Client.Name);

	cout << "Enter Phone ? ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance ? ";
	cin >> Client.AccountBalace;

	return Client;
}

stUsers ChangeUserRecord(string UserName)
{
	stUsers User;

	User.UserName = UserName;

	cout << "Enter PassWord ? ";
	getline(cin >> ws, User.PassWord);

	User.Permissions = ReadPermissionsToSet();

	return User;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClient>& vClients)
{
	for (stClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

bool MarkUserForDeleteByUsername(string UserName, vector<stUsers>& vUsers)
{
	for (stUsers& U : vUsers)
	{
		if (U.UserName == UserName)
		{
			U.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

vector<stClient> SaveCleintsDataToFile(string FileName, vector<stClient>vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	string DataLine;

	if (MyFile.is_open())
	{
		for (stClient C : vClients)
		{
			if (C.MarkForDelete = false)
			{
				DataLine = ConvertClientRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vClients;
}

vector<stUsers> SaveUsersDataToFile(string FileName, vector<stUsers>vUsers)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	string DataLine;

	if (MyFile.is_open())
	{
		for (stUsers U : vUsers)
		{
			if (U.MarkForDelete = false)
			{
				DataLine = ConvertUserRecordToLine(U);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vUsers;
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
	stClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertClientRecordToLine(Client));
}

void AddNewUser()
{
	stUsers User;
	User = ReadNewUser();
	AddDataLineToFile(UsersFileName, ConvertUserRecordToLine(User));
}

void AddNewClients()
{
	char AddMore = 'Y';
	do
	{

		cout << "Adding New Client : \n\n";

		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients ? Y/N ? ";

		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

void AddNewUsers()
{
	char AddMore = 'Y';
	do
	{

		cout << "Adding New User : \n\n";

		AddNewUser();
		cout << "\nUser Added Successfully, do you want to add more Users ? Y/N ? ";

		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<stClient>& vClients)
{
	stClient Client;
	char Answer = 'N';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
		cout << "\n\nAre you sure you want delete this client ? y/n ? ";

		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveCleintsDataToFile(ClientsFileName, vClients);

			vClients = LoadCleintsDataFromFile(ClientsFileName);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
		else
		{
			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
			return false;
		}
	}
}

bool DeleteUserByUsername(string UserName, vector<stUsers>& vUsers)
{
	if (UserName == "Admin")
	{
		cout << "\n\nYou Cannot Delete This User.";
		return false;
	}

	stUsers User;
	char Answer = 'n';

	if (FindUserByUsername(UserName, vUsers, User))
	{
		PrintUserCard(User);
		cout << "\n\nAre you sure you want delete this User ? y/n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			MarkUserForDeleteByUsername(UserName, vUsers);
			SaveUsersDataToFile(UserName, vUsers);

			vUsers = LoadUsersDataFromFile(UsersFileName);

			cout << "\n\nUser Deleted Successfully.";
			return true;
		}
		else
		{
			cout << "\nUser with Username (" << UserName << ") is Not Found!";
			return false;
		}
	}
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient>& vClients)
{
	stClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
		cout << "\n\nAre you sure you want update this client ? y/n ? ";

		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			for (stClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}
			SaveCleintsDataToFile(ClientsFileName, vClients);
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

bool UpdateUserByUsername(string UserName, vector<stUsers>& vUsers)
{
	stUsers User;
	char Answer = 'n';

	if (FindUserByUsername(UserName, vUsers, User))
	{
		PrintUserCard(User);
		cout << "\n\nAre you sure you want update this User ? y/n ? ";

		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			for (stUsers U : vUsers)
			{
				if (U.UserName == UserName)
				{
					U = ChangeUserRecord(UserName);
					break;
				}
			}
			SaveUsersDataToFile(UsersFileName, vUsers);

			cout << "\n\nUser Updated Successfully."; 
			return true;
		}
	}
	else
	{
		cout << "\nUser with Account Number (" << UserName << ") is Not Found!";
		return false;
	}
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<stClient>& vClients)
{
	char Answer = 'n';

	cout << "\n\nAre you sure you want perfrom this transaction ? y/n ? ";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		for (stClient C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.AccountBalace += Amount;
				SaveCleintsDataToFile(ClientsFileName, vClients);

				cout << "\n\nDone Successfully. New balance is: " << C.AccountBalace;
				return true;
			}
		}
		return false;
	}
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";

	cout << "\nEnter AccountNumber ? ";
	cin >> AccountNumber;

	return AccountNumber;
}

string ReadUserName()
{
	string UserName = "";

	cout << "\nEnter Username ? ";
	cin >> UserName;

	return UserName;
}

void ShowListUsersScreen()
{
	ShowAllUsersScreen();
}

void ShowAddNewUserScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tAdd New User Screen";     
	cout << "\n-----------------------------------\n";

	AddNewUser();
}

void ShowDeleteUserScreen()
{
	cout << "\n-----------------------------------\n";    
	cout << "\tDelete Users Screen";  
	cout << "\n-----------------------------------\n";

	vector<stUsers>vUsers = LoadUsersDataFromFile(UsersFileName);

	string UserName = ReadUserName();
	DeleteUserByUsername(UserName, vUsers);
}

void ShowUpdateUserScreen()
{
	cout << "\n-----------------------------------\n";  
	cout << "\tUpdate Users Screen";  
	cout << "\n-----------------------------------\n";

	vector<stUsers>vUsers = LoadUsersDataFromFile(UsersFileName);

	string UserName = ReadUserName();

	UpdateUserByUsername(UserName, vUsers);
}

void ShowDeleteClientScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::pDeleteClient))
	{
		ShowAccessDeniedMessage();
		return;
	}

	cout << "\n-----------------------------------\n";   
	cout << "\tDelete Client Screen"; 
	cout << "\n-----------------------------------\n";

	vector<stClient>vClients = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);
}

void ShowUpdateClientScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::pUpdateClient))
	{
		ShowAccessDeniedMessage();
		return;
	}

	cout << "\n-----------------------------------\n"; 
	cout << "\tUpdate Client Info Screen";   
	cout << "\n-----------------------------------\n";

	vector<stClient>vClients = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowAddNewClientsScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::pAddNewClient))
	{
		ShowAccessDeniedMessage();
		return;
	}

	cout << "\n-----------------------------------\n"; 
	cout << "\tAdd New Clients Screen";  
	cout << "\n-----------------------------------\n";  

	AddNewClients();
}

void ShowFindClientScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::pListClients))
	{
		ShowAccessDeniedMessage();
		return;
	}

	cout << "\n-----------------------------------\n";
	cout << "\tFind Client Screen";    
	cout << "\n-----------------------------------\n";

	vector<stClient>vClients = LoadCleintsDataFromFile(ClientsFileName);
	stClient Client;
	string AccountNumber = ReadClientAccountNumber();
	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
	}
}

void ShowFindUserScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tFind User Screen";     
	cout << "\n-----------------------------------\n";

	vector<stUsers>vUsers = LoadUsersDataFromFile(UsersFileName);
	stUsers User;
	string UserName = ReadUserName();

	if (FindUserByUsername(UserName, vUsers, User))
	{
		PrintUserCard(User);
	}
	else
	{
		cout << "\nUser with Username [" << UserName << "] is not found!";
	}
}

void ShowEndScreen()
{
	cout << "\n-----------------------------------\n"; 
	cout << "\tProgram Ends :-)";   
	cout << "\n-----------------------------------\n";
}

void ShowDepositScreen()
{
	cout << "\n-----------------------------------\n";  
	cout << "\tDeposit Screen";    
	cout << "\n-----------------------------------\n";

	stClient Client;

	vector<stClient>vClients = LoadCleintsDataFromFile(ClientsFileName);

	string AccountNumber = ReadClientAccountNumber();

	while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientCard(Client);

	double Amount = 0;

	cout << "\nEnter deposit amount ? ";
	cin >> Amount;

	DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);
}

void ShowWithDrawScreen()
{
	cout << "\n-----------------------------------\n";    
	cout << "\tWithdraw Screen";    
	cout << "\n-----------------------------------\n";

	stClient Client;

	vector<stClient>vClients = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();

	while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "\nClient with [" << AccountNumber << "] does not exist.\n"; 
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientCard(Client);

	double Amount = 0;

	cout << "\nEnter withdraw amount ? ";
	cin >> Amount;

	while (Amount > Client.AccountBalace)
	{
		cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalace << endl; 
		cout << "Please enter another amount ? ";  
		cin >> Amount;
	}

	DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vClients);
}

void ShowTotalBalancesScreen()
{
	ShowTotalBalances();
}

bool CheckAccessPermission(enMainMenuePermissions Permission)
{
	if (CurrentUser.Permissions == enMainMenuePermissions::enAll)
		return true;

	if ((Permission & CurrentUser.Permissions) == Permission)
		return true;
	else
		return false;
}

void GoBackToMainMenue() 
{
	cout << "\n\nPress any key to go back to Main Menue...";
	system("pause>0");
	ShowMainMenue();
}

void GoBackToTransactionsMenue() 
{
	cout << "\n\nPress any key to go back to Transactions Menue..."; 
	system("pause>0");
	ShowTransactionsMenue();
}

void GoBackToManageUsersMenue() 
{
	cout << "\n\nPress any key to go back to Transactions Menue...";  
	system("pause>0"); 
	ShowManageUsersMenue(); 
}

short ReadTransactionsMenueOption()
{
	cout << "Choose what do you want to do? [1 to 4]? ";
	short Choice = 0; 
	cin >> Choice;
	return Choice;
}

void PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
{
	switch (TransactionMenueOption)
	{
	case enDeposit:

		system("cls");
		ShowDepositScreen();
		GoBackToMainMenue();
		break;

	case enWithdraw:

		system("cls");
		ShowWithDrawScreen();
		GoBackToMainMenue();
		break;

	case enShowTotalBalance:

		system("cls");
		ShowTotalBalancesScreen();
		GoBackToMainMenue();
		break;

	case enShowMainMenue:
		
		ShowMainMenue();
	}
}

void ShowTransactionsMenue()
{
	if (!CheckAccessPermission(enMainMenuePermissions::pTranactions))
	{
		ShowAccessDeniedMessage();
		GoBackToMainMenue();
		return;
	}

	system("cls");

	cout << "===========================================\n";
	cout << "\t\tTransactions Menue Screen\n";
	cout << "===========================================\n"; 
	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balances.\n";
	cout << "\t[4] Main Menue.\n";  
	cout << "===========================================\n";

	PerfromTranactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
}

short ReadMainMenueOption()
{
	short Choice = 0;

	cout << "Choose what do you want to do? [1 to 8]? ";     
	cin >> Choice;
	return Choice;
}

void PerfromManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
{
	switch (ManageUsersMenueOption)
	{
	case enListUsers:
		
		system("cls");         
		ShowListUsersScreen();
		GoBackToManageUsersMenue();
		break;

	case enAddNewUser:

		system("cls");
		ShowAddNewUserScreen();
		GoBackToManageUsersMenue();
		break;

	case enDeleteUser:

		system("cls");
		ShowDeleteUserScreen();
		GoBackToManageUsersMenue();
		break;

	case enUpdateUser:

		system("cls");
		ShowUpdateUserScreen();
		GoBackToManageUsersMenue();
		break;

	case enFindUser:

		system("cls");
		ShowFindUserScreen();
		GoBackToManageUsersMenue();
		break;

	case enMainMenue:
		
		ShowMainMenue();
	}
}

short ReadManageUsersMenueOption()
{
	cout << "Choose what do you want to do? [1 to 6]? "; 
	short Choice = 0;   
	cin >> Choice;
	return Choice;
}

void ShowManageUsersMenue()
{
	if (!CheckAccessPermission(enMainMenuePermissions::pMangeUsers))
	{
		ShowAccessDeniedMessage(); 
		GoBackToMainMenue();
		return;
	}
	
	system("cls"); 
	
	cout << "===========================================\n"; 
	cout << "\t\tManage Users Menue Screen\n";
	cout << "===========================================\n"; 
	cout << "\t[1] List Users.\n";
	cout << "\t[2] Add New User.\n";
	cout << "\t[3] Delete User.\n";  
	cout << "\t[4] Update User.\n"; 
	cout << "\t[5] Find User.\n"; 
	cout << "\t[6] Main Menue.\n";
	cout << "===========================================\n";

	PerfromManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());
}

void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
	switch (MainMenueOption)
	{
	case enMainMenueOptions::enListClients:
	{
		system("cls");
		ShowAllClientsScreen();
		GoBackToMainMenue();
		break;
	}

	case enMainMenueOptions::enAddNewClient:
		system("cls");
		ShowAddNewClientsScreen();
		GoBackToMainMenue();
		break;

	case enMainMenueOptions::enDeleteClient:
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenue();
		break;

	case enMainMenueOptions::enUpdateClient:
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenue();
		break;

	case enMainMenueOptions::enFindClient:
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenue();
		break;

	case enMainMenueOptions::enShowTransactionsMenue:
		system("cls");
		ShowTransactionsMenue();
		break;

	case enMainMenueOptions::enManageUsers:
		system("cls");
		ShowManageUsersMenue();
		break;

	case enMainMenueOptions::enLogOut:
		system("cls");
		// ShowEndScreen();
		Login();
		break;
	}
}

void ShowMainMenue() 
{
	system("cls");
	cout << "===========================================\n";  
	cout << "\t\tMain Menue Screen\n";
	cout << "===========================================\n";  
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";  
	cout << "\t[3] Delete Client.\n";  
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n"; 
	cout << "\t[6] Transactions.\n";
	cout << "\t[7] Manage Users.\n";
	cout << "\t[8] Logout.\n";
	cout << "===========================================\n";

	PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption()); 
}

bool LoadUserInfo(string UserName, string PassWord)
{
	if (FindUserByUsernameAndPassword(UserName, PassWord, CurrentUser))
		return true;
	else
		return false;
}

void Login()
{
	bool LoginFaild = false;

	string Username, Password; 
	
	do
	{
		system("cls");
		cout << "\n---------------------------------\n";
		cout << "\tLogin Screen";
		cout << "\n---------------------------------\n";
		
		if (LoginFaild) 
		{
			cout << "Invlaid Username/Password!\n";
		}
		
		cout << "Enter Username? "; 
		cin >> Username; 
		cout << "Enter Password? ";
		cin >> Password;
		LoginFaild = !LoadUserInfo(Username, Password);
	} while (LoginFaild);   
	
	ShowMainMenue();
}

int main()
{
	Login();

	system("pause>0");
	return 0;
}