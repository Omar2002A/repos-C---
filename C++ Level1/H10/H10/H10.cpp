#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1 = "43.22";
	double dstr = stod(str1);
	cout << str1 << " --> " << dstr << "\n";

	float fstr = stof(str1);
	cout << str1 << " --> " << fstr << "\n";

	int istr = stoi(str1);
	cout << str1 << " --> " << istr << "\n";

	int x = 20;
	string str = to_string(x);
	cout << x << " --> " << str << "\n";

	double Xx = 33.5;
	string Str = to_string(Xx);
	cout << Xx << " --> " << Str << "\n";

	float Num = 55.23;
	string strfornum = to_string(Num);
	cout << Num << " --> " << strfornum << "\n";

	int num;
	num = Num;
	cout << num << "\n";

	num = (int)Num;
	cout << num << "\n";
	num = int(Num);
	cout << num << endl;
}