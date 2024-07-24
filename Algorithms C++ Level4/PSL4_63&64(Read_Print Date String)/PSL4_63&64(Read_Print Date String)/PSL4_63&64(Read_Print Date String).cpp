#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

vector<string> SplitString(string S, string Delim)
{
	vector<string> vString;

	short POS = 0;
	string sWord;

	while ((POS = S.find(Delim)) != std::string::npos)
	{
		sWord = S.substr(0, POS);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S.erase(0, POS + Delim.length());
	}

	if (S != "")
		vString.push_back(S);

	return vString;
}

string DatetoString(stDate Date)
{
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

stDate StringtoDate(string S)
{
	stDate Date;
	vector<string> vDate;

	vDate = SplitString(S, "/");
	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;
}

string ReadStringDate(string Messege)
{
	string S;

	cout << Messege;
	getline(cin >> ws, S);

	return S;
}

int main()
{
	string S = ReadStringDate("\nEnter date dd/mm/yyyy ? ");

	stDate Date = StringtoDate(S);

	cout << "\nDay   : " << Date.Day << endl;
	cout << "Month : " << Date.Month << endl;
	cout << "Year  : " << Date.Year << endl;

	cout << "\nYou Entered: " << DatetoString(Date) << "\n";

	system("pause>0");
	return 0;
}