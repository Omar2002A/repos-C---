#include<iostream>
using namespace std;

class clsEmployee {
private:
	int _ID;
	string _FirstName, _LastName, _Title, _Email, _Phone, _Department;
	double _Salary;

public:
	clsEmployee(int ID, string FirstName, string LastName, string Title, string Email, string Phone, double Salary, string Department) {
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Title = Title;
		_Email = Email;
		_Phone = Phone;
		_Salary = Salary;
		_Department = Department;
	}

	int ID() {
		return _ID;
	}

	void setFirstName(string FirstName) {
		_FirstName = FirstName;
	}
	string FirstName() {
		return _FirstName;
	}

	void setLastName(string LastName) {
		_LastName = LastName;
	}
	string LastName() {
		return _LastName;
	}

	string FullName() {
		return _FirstName + " " + _LastName;
	}

	void setTitle(string Title) {
		_Title = Title;
	}
	string Title() {
		return _Title;
	}

	void setEmail(string Email) {
		_Email = Email;
	}
	string Email() {
		return _Email;
	}

	void setPhone(string Phone) {
		_Phone = Phone;
	}
	string Phone() {
		return _Phone;
	}

	void setSalary(double Salary) {
		_Salary = Salary;
	}
	double Salary() {
		return _Salary;
	}

	void setDepartment(string Department) {
		_Department = Department;
	}
	string Department() {
		return _Department;
	}

	void SendEmail(string Subject, string Body) {
		cout << "\n\nThe message sent successfuly :) to this email : " << _Email;
		cout << "\nSubject : " << Subject;
		cout << "\nBody    : " << Body << endl;
	}

	void SendSMS(string SMS) {
		cout << "\nThe message sent successfuly to this phone number : " << _Phone;
		cout << "\nSMS : " << SMS << endl;
	}

	void Print() {
		cout << "\n**************************";
		cout << "\nID         : " << _ID;
		cout << "\nFirst Name : " << _FirstName;
		cout << "\nLast Name  : " << _LastName;
		cout << "\nFull Name  : " << FullName();
		cout << "\nTitle      : " << _Title;
		cout << "\nEmail      : " << _Email;
		cout << "\nPhone      : " << _Phone;
		cout << "\nSalary     :" << _Salary;
		cout << "\nDepartment : " << _Department;
		cout << "\n**************************";
	}
};

int main() {
	clsEmployee Employee(1, "Omar", "Mushref", "Dev", "Mu@gmail.com", "0799974979", 970.5, "Web");
	Employee.Print();
	Employee.SendEmail("Hi", "How are you ? ");
	Employee.SendSMS("Hiii ! ");

	system("pause>0");
	return 0;
}