#include <iostream>
using namespace std;

class clsCalculator {
private:
	float _Result = 0;
	float _LastNumber = 0;
	string _LastOperation = "clear";
	float _PreviousResult = 0;

	bool _IsZero(float Number) {
		return (Number == 0);
	}

public:

	void Add(float Number) {
		_LastNumber = Number;
		_PreviousResult = _Result;
		_LastOperation = "Adding";
		_Result += Number;
	}

	void Subtract(float Number) {
		_LastNumber = Number;
		_PreviousResult = _Result;
		_LastOperation = "Subtracting";
		_Result -= Number;
	}

	void Divide(float Number) {
		_LastNumber = Number;

		if (_IsZero(Number)) {
			Number = 1;
		}

		_PreviousResult = _Result;
		_LastOperation = "Dividing";
		_Result /= Number;
	}

	void Multiply(float Number) {
		_LastNumber = Number;
		_LastOperation = "Multiplying";
		_PreviousResult = _Result;
		_Result *= Number;
	}

	float GetFinalResult() {
		return _Result;
	}

	void Clear() {
		_LastNumber = 0;
		_PreviousResult = 0;
		_LastOperation = "Clear";
		_Result = 0;
	}

	void CancelLastOperation() {
		_LastNumber = 0;
		_LastOperation = "Cancelling Last Operation";
		_Result = _PreviousResult;
	}

	void PrintResult() {
		cout << "Result After" << _LastOperation << "  " << _LastNumber << " is : " << _Result << "\n";
	}
};

int main() {
	clsCalculator calculator1;

	calculator1.Clear();

	calculator1.Add(10);
	calculator1.PrintResult();

	calculator1.Add(100);
	calculator1.PrintResult();

	calculator1.Subtract(20);
	calculator1.PrintResult();

	calculator1.Divide(0);
	calculator1.PrintResult();

	calculator1.Divide(2);
	calculator1.PrintResult();

	calculator1.Multiply(3);
	calculator1.PrintResult();

	calculator1.CancelLastOperation();
	calculator1.PrintResult();

	calculator1.Clear();
	calculator1.PrintResult();

	system("pause>0");
	return 0;
}