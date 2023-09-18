#include <iostream>
#include <string>
using namespace std;

float ReadNumber(string Messege)
{
	float N = 0;
	cout << Messege << endl;
	cin >> N;
	return N;
}

float SumNumbers()
{
	int Sum = 0, Number = 0, Counter = 1;

	while (Number != -99)
	{
		/*if (Number == -99)
		{
			break;
		}*/
		Number = ReadNumber("Enter Number " + to_string(Counter));
		Sum += Number;
		Counter++;
	}
	return Sum + 99;
}

void PrintResult(float Summ)
{
	cout << "\n The Result = " << Summ << endl;
}

int main()
{
	PrintResult(SumNumbers());
	return 0;
}