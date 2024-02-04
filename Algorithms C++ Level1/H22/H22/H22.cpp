#include <iostream>
using namespace std;
int main()
{
	int num = 0;
	int sum = 0;
	for (int i = 1; i <= 5; i++)
	{
		cout << "Enter Number : ";
		cin >> num;

		if (num > 50)
		{
			cout << "Invalid\n";
			continue;
		}

		sum += num;

	}
	cout << "The Sum = " << sum;
}