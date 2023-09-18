#include <iostream>
using namespace std;
int main()
{
	short Num1;
	cout << "Please Enter The 1's Number : ";
	cin >> Num1;

	short Num2;
	cout << "Please Enter The 2's Number : ";
	cin >> Num2;

	short Num3;
	cout << "Please Enter The 3's Number : ";
	cin >> Num3;

	short AVG = (Num1 + Num2 + Num3) / 3;
	cout << "The AVG Of 3 Marks Is : " << AVG << endl;
}