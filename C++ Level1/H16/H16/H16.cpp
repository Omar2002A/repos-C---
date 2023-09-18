#include <iostream>
using namespace std;

enum enScreenColor { Red = 1, Blue = 2, Green = 3, Yelow = 4 };

int main()
{
	cout << "********************\n";
	cout << "Chose the Number of your Color\n";
	cout << "(1) Red\n(2) Blue\n(3)Green\n(4)Yellow\n";
	cout << "********************\n";
	cout << "Your Choice ? ";

	short number;
	enScreenColor Color;
	cin >> number;
	Color = (enScreenColor)number;

	switch (Color)
	{
	case Red:
		system("color 4F");
		break;
	case Blue:
		system("color 1F");
		break;
	case Green:
		system("color 2F");
		break;
	case Yelow:
		system("color 6F");
		break;
	default:
		cout << "OPS!!\n\n";
		break;
	}

	/*if (Color == enScreenColor::Red)
	{
		system("color 4F");
	}
	else if (Color == enScreenColor::Blue)
	{
		system("color 1F");
	}
	else if (Color == enScreenColor::Green)
	{
		system("color 2F");
	}
	else if (Color == enScreenColor::Yelow)
	{
		system("color 6F");
	}
	else
	{
		system("color 3F");
	}*/
}