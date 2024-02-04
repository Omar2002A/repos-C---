#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1;
	cout << "Enter String1 ? \n";
	getline(cin, str1);

	string str2;
	cout << "\nEnter String2 ? \n";
	cin >> str2;

	string str3;
	cout << "\nEnter String3 ? \n";
	cin >> str3;

	cout << "*******************\n";
	cout << "The Lenght Of String 1 = " << str1.length() << "\n";
	cout << "Characters Of 0 , 2 , 4 , 7 are : " << str1[0] << " , " << str1[2] << " , " << str1[4] << " , " << str1[7] << "\n";
	cout << "Concateneting String2 And String3 = " << str2 + str3 << "\n";
	cout << str2 << " * " << str3 << " = " << stoi(str2) * stoi(str3) << endl;
}