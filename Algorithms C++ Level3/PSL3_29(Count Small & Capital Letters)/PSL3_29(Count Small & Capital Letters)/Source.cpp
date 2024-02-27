#include <iostream>
#include <string>

using namespace std;

string ReadString() {
	string str;
	cout << "\nEnter Your Text : \n";
	getline(cin, str);
	return str;
}

enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 2 };

short CountLetters(string str, enWhatToCount WhatToCount = enWhatToCount::All)
{
	short Count = 0;

	if (WhatToCount == All)
		return str.length();

	for (short i = 0; i < str.length(); i++)
	{
		if (WhatToCount == SmallLetters && islower(str[i]))
			Count++;

		if (WhatToCount == CapitalLetters && isupper(str[i]))
			Count++;
	}
	return Count;
}

short CountSmallLetters(string str) {
	short Count = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (islower(str[i]))
			Count++;
	}
	return Count;
}

short CountCapitalLetters(string str) {
	short Count = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (isupper(str[i]))
			Count++;
	}
	return Count;
}

int main() {
	string S1 = ReadString();    
	cout << "\nString Length = " << S1.length();    
	cout << "\nCapital Letters Count = " << CountCapitalLetters(S1);    
	cout << "\nSmall Letters Count = " << CountSmallLetters(S1);   
	cout << "\nAll Letters Count = " << CountCapitalLetters(S1) + CountSmallLetters(S1);
	cout << "\n\nMethod 2 : \n";     
	cout << "\nString Length = " << CountLetters(S1);    
	cout << "\nCapital Letters Count = " << CountLetters(S1, enWhatToCount::CapitalLetters);     
	cout << "\nSmall Letters Count = " << CountLetters(S1, enWhatToCount::SmallLetters);    
	cout << "\nAll Letters Count = " << CountLetters(S1, enWhatToCount::CapitalLetters) + CountLetters(S1, enWhatToCount::SmallLetters);
	
	system("pause>0");
}