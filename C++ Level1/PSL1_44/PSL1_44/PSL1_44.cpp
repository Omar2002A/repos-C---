#include <iostream>
using namespace std;

enum enDayOfWeek { Sat = 1, Sun = 2, Mon = 3, Tue = 4, Wen = 5, Thu = 6, Fri = 7 };

int ReadNumberInRange(string Messege, int From, int To)
{
	int Number = 0;
	do
	{
		cout << Messege << endl;
		cin >> Number;

	} while (Number < From || Number > To);
	return Number;
}

enDayOfWeek ReadDayOfWeek()
{
	return (enDayOfWeek)ReadNumberInRange("Enter Day Number Sat = 1, Sun = 2, Mon = 3, Tue = 4, Wen = 5, Thu = 6, Fri = 7", 1, 7);
}

string GetDayOfWeek(enDayOfWeek Day)
{
	switch (Day)
	{
	case Sat:
		return "Saturday";
		break;
	case Sun:
		return "Sunday";
		break;
	case Mon:
		return "Monday";
		break;
	case Tue:
		return "Tuesday";
		break;
	case Wen:
		return "Wensday";
		break;
	case Thu:
		return "Thusday";
		break;
	case Fri:
		return "Friday";
		break;
	default:
		return "Not A valid Day";
		break;
	}
}

int main()
{
	cout << GetDayOfWeek(ReadDayOfWeek()) << endl;
	return 0;
}