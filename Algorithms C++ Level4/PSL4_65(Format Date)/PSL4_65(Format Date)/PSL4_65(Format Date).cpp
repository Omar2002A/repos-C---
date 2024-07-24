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
			vString.push_back(sWord);

		S.erase(0, POS + Delim.length());
	}

	if (S != "")
		vString.push_back(S);

	return vString;
}

string ReplaceWordInString(string S, string StringToReplace, string sReplaceTo)
{
	short POS = S.find(StringToReplace);

	while (POS != std::string::npos)
	{
		S = S.replace(POS, StringToReplace.length(), sReplaceTo);
		POS = S.find(StringToReplace);
	}

	return S;
}

string DateToString(stDate Date)
{
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

stDate StringToDate(string S)
{
	stDate Date;
	vector<string> vDate;

	vDate = SplitString(S, "/");

	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;
}

string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
	string FormatedDateString = "";
	
	FormatedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
	FormatedDateString = ReplaceWordInString(FormatedDateString, "mm", to_string(Date.Month));
	FormatedDateString = ReplaceWordInString(FormatedDateString, "yyyy", to_string(Date.Year));

	return FormatedDateString;
}

string ReadStringDate(string Messege)
{
	string DateString;

	cout << Messege;
	getline(cin >> ws, DateString);
	return DateString;
}

int main()
{
	string DateString = ReadStringDate("\nEnter Date dd/mm/yyyy ? ");

	stDate Date = StringToDate(DateString);

	cout << "\n" << FormateDate(Date) << "\n";
	cout << "\n" << FormateDate(Date, "yyyy/mm/dd") << "\n";
	cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";

	system("pause>0");
	return 0;
}