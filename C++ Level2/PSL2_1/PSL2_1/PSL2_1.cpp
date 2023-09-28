#include <iostream>
using namespace std;

void PrintTableHeaader()
{
	cout << "\n\t\t\t\tMultiplication Table\n\n\t";
	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t";
	}
	cout << "\n---------------------------------------------------------------------------------------\n";
}

string ColumSperator(int i)
{
	if (i < 10)
		return "   |";
	else
		return "  |";
}

void PrintMultiPlicationTable()
{
	PrintTableHeaader();
	for (int i = 1; i <= 10; i++)
	{
		cout << " " << i << ColumSperator(i) << "\t";
		for (int j = 1; j <= 10; j++)
		{
			cout << i * j << "\t";
		}
		cout << endl;
	}
}

int main()
{
	PrintMultiPlicationTable();
	return 0;
}