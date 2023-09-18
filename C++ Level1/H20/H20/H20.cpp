#include <iostream>
using namespace std;
int main()
{
	//AA to ZZ

	/*for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			cout << char(i) << char(j) << endl;
		}
	}*/

	//"**********" to "*"

	/*for (int i = 10; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}*/

	//"12345678910" to "1"

	/*for (int i = 10; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << " ";
		}
		cout << endl;
	}*/

	//"1" to "12345678910"

	/*for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << " ";
		}
		cout << endl;
	}*/

	//"A" to "A B C D E F"

	/*for (int i = 65; i <= 70; i++)
	{
		for (int j = 65; j <= i; j++)
		{
			cout << char(j) << " ";
		}
		cout << "\n";
	}*/

	for (int i = 1; i <= 10; i++)
	{
		for (int j = i; j <= 10; j++)
		{
			cout << j << " ";
		}
		cout << endl;
	}

}