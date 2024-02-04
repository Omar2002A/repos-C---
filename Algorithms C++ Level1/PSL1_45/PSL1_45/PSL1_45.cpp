#include <iostream>
using namespace std;

enum enNumberOfMonth { January = 1, February = 2, March = 3, April = 4, May = 5, Jun = 6, July = 7, August = 8, September = 9, October = 10, November = 11, December = 12 };

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

enNumberOfMonth ReadMonthOfYear()
{
	return (enNumberOfMonth)ReadNumberInRange("Enter Number a Month \nJanuary = 1, February = 2, March = 3, April = 4,\n May = 5, Jun = 6, July = 7, August = 8,\n September = 9, October = 10, November = 11, December = 12? :", 1, 12);
}

string GetMonthOfYear(enNumberOfMonth Month)
{
	switch (Month)
	{
	case January:
		return "January";
	case February:
		return "February";
	case March:
		return "March";
	case April:
		return "April";
	case May:
		return "May";
	case Jun:
		return "Jun";
	case July:
		return "July";
	case August:
		return "August";
	case September:
		return "September";
	case October:
		return "October";
	case November:
		return "November";
	case December:
		return "December";
	default:
		return "Not Valid Month";
	}
}

void PrintResult(string Month)
{
	cout << "The Month Is : " << Month << endl;
}

int main()
{
	PrintResult(GetMonthOfYear(ReadMonthOfYear()));
	return 0;
}

//#include <iostream>
//using namespace std;
//
//enum enNumberOfMonth { January = 1, February = 2, March = 3, April = 4, May = 5, Jun = 6, July = 7, August = 8, September = 9, October = 10, November = 11, December = 12 };
//
//void ShowMonthMenue()
//{
//	cout << "************************\n";
//	cout << "	Month Menue	\n";
//	cout << "************************\n\n";
//	cout << "1--> January\n";
//	cout << "2--> February\n";
//	cout << "3--> March\n";
//	cout << "4--> April\n";
//	cout << "5--> May\n";
//	cout << "6--> June\n";
//	cout << "7--> July\n";
//	cout << "8--> August\n";
//	cout << "9--> September\n";
//	cout << "10--> October\n";
//	cout << "11--> November\n";
//	cout << "12--> December\n";
//	cout << "Please Enter The Number Of a Month ? ";
//}
//
//enNumberOfMonth ReadNumberOfMonth()
//{
//	short Number;
//	enNumberOfMonth NumberMonth;
//
//	cin >> Number;
//	cout << "THX\n\n";
//	return enNumberOfMonth(Number);
//}
//
//string GetMonthNumber(enNumberOfMonth NMonth)
//{
//	switch (NMonth)
//	{
//	case January:
//		return "January";
//		break;
//	case February:
//		return "February";
//		break;
//	case March:
//		return "March";
//		break;
//	case April:
//		return "April";
//		break;
//	case May:
//		return "May";
//		break;
//	case Jun:
//		return "Jun";
//		break;
//	case July:
//		return "July";
//		break;
//	case August:
//		return "August";
//		break;
//	case September:
//		return "September";
//		break;
//	case October:
//		return "October";
//		break;
//	case November:
//		return "November";
//		break;
//	case December:
//		return "December";
//		break;
//	default:
//		return "Invalid Input!";
//		break;
//	}
//}
//
//void PrintMonth()
//{
//	cout << "The Month Is : " << GetMonthNumber(ReadNumberOfMonth()) << endl;
//}
//
//int main()
//{
//
//	ShowMonthMenue();
//	PrintMonth();
//
//	/*short NumOfMonth;
//	cout << "Enter Number of Month : ";
//	cin >> NumOfMonth;
//
//	switch (NumOfMonth)
//	{
//	case 1:
//		cout << "January";
//		break;
//
//	case 2:
//		cout << "February";
//		break;
//
//	case 3:
//		cout << "March";
//		break;
//
//	case 4:
//		cout << "April";
//		break;
//		
//	case 5:
//		cout << "May";
//		break;
//		
//	case 6:
//		cout << "June";
//		break;
//		
//	case 7:
//		cout << "July";
//		break;
//		
//	case 8:
//		cout << "August";
//		break;
//		
//	case 9:
//		cout << "September";
//		break;
//		
//	case 10:
//		cout << "October";
//		break;
//		
//	case 11:
//		cout << "November";
//		break;
//		
//	case 12:
//		cout << "December";
//		break;
//
//	default:
//		cout << "Invalid Month";
//		break;
//	}*/
//
//	/*if (NumOfMonth == 1)
//	{
//		cout << "January";
//	}
//	else if (NumOfMonth == 2)
//	{
//		cout << "February";
//	}
//	else if (NumOfMonth == 3)
//	{
//		cout << "March";
//	}
//	else if (NumOfMonth == 4)
//	{
//		cout << "April";
//	}
//	else if (NumOfMonth == 5)
//	{
//		cout << "May";
//	}
//	else if (NumOfMonth == 6)
//	{
//		cout << "June";
//	}
//	else if (NumOfMonth == 7)
//	{
//		cout << "July";
//	}
//	else if (NumOfMonth == 8)
//	{
//		cout << "August";
//	}
//	else if (NumOfMonth == 9)
//	{
//		cout << "September";
//	}
//	else if (NumOfMonth == 10)
//	{
//		cout << "October";
//	}
//	else if (NumOfMonth == 11)
//	{
//		cout << "November";
//	}
//	else if (NumOfMonth == 12)
//	{
//		cout << "December";
//	}
//	else
//	{
//		cout << "Wrong Month.";
//	}*/
//}