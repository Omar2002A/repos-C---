#include <iostream>
using namespace std;
int main()
{
	/*bool Result;
	Result = (12 >= 12);
	cout << "12 >= 12 ? " << Result << "\n";

	Result = (12 > 7);
	cout << "12 > 7 ? " << Result << "\n";

	Result = (8 < 6);
	cout << "8 < 6 ? " << Result << "\n";

	Result = (8 == 8);
	cout << "8 = 8 ? " << Result << "\n";

	Result = (12 <= 12);
	cout << "12 <= 12 ? " << Result << "\n";

	Result = (7 == 5);
	cout << "7 = 5 ? " << Result << "\n";

	Result = !(12 >= 12);
	cout << "Not(12 >= 12) ? " << Result << "\n";

	Result = !(12 < 7);
	cout << "Not(12 < 7) ? " << Result << "\n";

	Result = !(8 < 6);
	cout << "Not(6 < 8) ? " << Result << "\n";

	Result = !(8 == 8);
	cout << "Not(8 == 8) ? " << Result << "\n";

	Result = !(12 <= 12);
	cout << "Not(12 <= 12) ? " << Result << "\n";

	Result = !(7 == 5);
	cout << "Not(7 == 5) ? " << Result << endl;

	Result = (1 && 1);
	cout << "1 And 1 = " << Result << "\n";

	Result = (true && 0);
	cout << "True And 0 = " << Result << "\n";

	Result = (0 || 1);
	cout << "0 Or 1 = " << Result << "\n";

	Result = (0 || 0);
	cout << "0 Or 0 = " << Result << "\n";

	Result = !(0);
	cout << "Not 0 = " << Result << "\n";

	Result = !(1 || 0);
	cout << "Not(1 Or 0) = " << Result << "\n";

	Result = (7 == 7) && (7 > 5);
	cout << "(7 = 7) And (7 > 5) = " << Result << "\n";

	Result = (7 == 7) && (7 < 5);
	cout << "(7 = 7) And (7 < 5) = " << Result << "\n";

	Result = (7 == 7) || (7 < 5);
	cout << "(7 = 7) Or (7 < 5) = " << Result << "\n";

	Result = (7 < 7) || (7 > 5);
	cout << "(7 < 7) Or (7 > 5) = " << Result << "\n";

	Result = !(7 == 7) && (7 > 5);
	cout << "Not(7 = 7) And (7 > 5) = " << Result << "\n";

	Result = (7 == 7) && !(7 < 5);
	cout << "(7 = 7) And Not(7 < 5) = " << Result << endl;*/


	bool Result;
	Result = (5 > 6 && 7 == 7) || (1 || 0);
	cout << "(5 > 6 And 7 = 7) Or (1 Or 0) = " << Result << "\n";

	Result = !(5 > 6 && 7 == 7) || (1 || 0);
	cout << "Not(5 > 6 And 7 = 7) Or (1 Or 0) = " << Result << "\n";

	Result = (!(5 > 6 && 7 == 7)) || (!(1 || 0));
	cout << "Not(5 > 6 And 7 = 7) Or Not(1 Or 0) = " << Result << "\n";

	Result = (!(5 > 6 && 7 == 7)) && (!(1 || 0));
	cout << "Not(5 > 6 And 7 = 7) And Not(1 Or 0) = " << Result << "\n";

	Result = ((5 > 6 && 7 <= 8) || (8 > 1 && 4 <= 3)) && true;
	cout << "((5 > 6 And 7 <= 8) Or (8 > 1 And 4 <= 3)) And True = " << Result << "\n";

	Result = ((5 > 6 && !(7 <= 8)) && (8 > 1 || 4 <= 3)) || true;
	cout << "((5 > 6 And Not(7 <= 8)) And (8 > 1 Or 4 <= 3)) Or True = " << Result << "\n";

	return 0;
}