#include <iostream>
using namespace std;

void ReadNumbers(int& Number1, int& Number2)
{
	cout << "Enter The First Number ? \n";
	cin >> Number1;

	cout << "Enter The Second Number ? \n";
	cin >> Number2;
	cout << "************************\n" << endl;
}

void Swap(int& Number1 ,int& Number2)
{
	int temp;
	temp = Number1;
	Number1 = Number2;
	Number2 = temp;
	cout << "Swap:------------\n";
}

void PrintNumbers(int Number1, int Number2)
{
	cout << Number1 << "\n" << Number2 << endl;
}

int main()
{
	int Num1, Num2;
	ReadNumbers(Num1, Num2);
	PrintNumbers(Num1, Num2);
	Swap(Num1, Num2);
	PrintNumbers(Num1, Num2);
	return 0;
}