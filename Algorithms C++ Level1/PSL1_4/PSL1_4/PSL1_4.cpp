#include <iostream>
using namespace std;

struct stInfo
{
	int Age;
	bool HasDrivingLicense;
	bool HasRecommendation;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "Enter Your Age ? \n";
	cin >> Info.Age;

	cout << "Do You Have Drivind License ? \n";
	cin >> Info.HasDrivingLicense;

	cout << "Do You Have Recommendation ? \n";
	cin >> Info.HasRecommendation;

	return Info;

}

bool IsAccepted(stInfo Info)
{
	/*if (Info.Age >= 21 && (Info.HasDrivingLicense == 1))
	{
		return true;
	}
	else
	{
		return false;
	}*/

	return ((Info.Age >= 21 && (Info.HasDrivingLicense == 1)) || Info.HasRecommendation == 1);

}

void PrintResult(stInfo Info)
{
	if (IsAccepted(Info))
	{
		cout << "\n Hired :) \n";
	}
	else
	{
		cout << "\n Rejected :( \n";
	}
}

int main()
{
	PrintResult(ReadInfo());
	return 0;
}