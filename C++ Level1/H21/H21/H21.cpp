#include <iostream>
using namespace std;
int main()
{
	int arri[10] = { 1,2,3,4,20,6,7,8,9,10 };
	int SearchFor = 20;

	for (int i = 0; i <= 10; i++)
	{
		cout << "We Are at iteration " << i + 1 << endl;

		if (SearchFor == arri[i])
		{
			cout << endl << SearchFor << " Found at a Position " << i << endl;
			break;
		}
	}

	/*int Save = 0;

	for (int i = 0; i < 10; i++)
	{
		Save += 1;
		if (arri[i] == 20)
		{
			break;
		}
		
	}
	cout << "The Position Of 20 --> arri[" << Save << "]" << endl;*/
}