#include <iostream>
using namespace std;
int main()
{
	short int Number1;
	cout << "Enter The First Number : ";
	cin >> Number1;

	short Number2;
	cout << "Enter The Second Number : ";
	cin >> Number2;

	cout << Number1 << " = " << Number2 << " is " << (Number1 == Number2) << "\n";
	cout << Number1 << " != " << Number2 << " is " << (Number1 != Number2) << "\n";
	cout << Number1 << " > " << Number2 << " is " << (Number1 > Number2) << "\n";
	cout << Number1 << " < " << Number2 << " is " << (Number1 < Number2) << "\n";
	cout << Number1 << " >= " << Number2 << " is " << (Number1 >= Number2) << "\n";
	cout << Number1 << " <= " << Number2 << " is " << (Number1 <= Number2) << endl;
}