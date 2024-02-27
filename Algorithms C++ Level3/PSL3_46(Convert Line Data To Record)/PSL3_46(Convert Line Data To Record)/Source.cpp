#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double BalanceAccount;
};

vector<string> SplitString(string str, string Delimirter)
{
	vector<string> vString;
	short Pos = 0;
	string word;
	while ((Pos = str.find(Delimirter)) != string::npos)
	{
		word = str.substr(0, Pos);
		if (word != "")
			vString.push_back(word);

		str.erase(0, Pos + Delimirter.length());
	}
	if (str != "")
		vString.push_back(str); // last word

	return vString;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.PhoneNumber = vClientData[3];
	Client.BalanceAccount = stod(vClientData[4]); // convert string to double

	return Client;
}

void PrintClientRecord(sClient Client)
{
	cout << "\n\nThe Client Record is : \n";
	cout << "\nAccount Number : " << Client.AccountNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nName : " << Client.Name;
	cout << "\nPhone Number : " << Client.PhoneNumber;
	cout << "\nBalance Account : " << Client.BalanceAccount;
}

int main()
{
	string stLine = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";     
	cout << "\nLine Record is : \n";     
	cout << stLine; 
	sClient Client = ConvertLinetoRecord(stLine);     
	PrintClientRecord(Client);     
	
	system("pause>0");
}