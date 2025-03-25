#include <iostream>
using namespace std;

class clsPerson {
private:
	int _ID;
	string _FirstName, _LastName, _Email, _PhoneNumber;
public:
	clsPerson(int ID, string FirstName, string LastName, string Email, string PhoneNumber) {
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_PhoneNumber = PhoneNumber;
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

	void setEmail(string Email) {
		_Email = Email;
	}

	string Email() {
		return _Email;
	}

	void setPhoneNumber(string PhoneNumber) {
		_PhoneNumber = PhoneNumber;
	}

	string PhoneNumber() {
		return _PhoneNumber;
	}

	string Name() {
		return _FirstName + " " + _LastName;
	}

	void Print() {
		cout << "\nInfo : ";
		cout << "\n***********************";
		cout << "\nID           : " << _ID;
		cout << "\nFirst Name   : " << _FirstName;
		cout << "\nLast Name    : " << _LastName;
		cout << "\nFull Name    : " << Name();
		cout << "\nEmail        : " << _Email;
		cout << "\nPhone Number : " << _PhoneNumber;
		cout << "\n***********************" << endl;
	}

	void SendEmail(string Subject, string Body) {
		cout << "\nThe following message sent successfuly to email : " << _Email;
		cout << "\nSubject : " << Subject;
		cout << "\nBody    : " << Body << endl;
	}

	void SendSMS(string TextMessage) {
		cout << "\nThe following message sent successfuly to phone number : " << _PhoneNumber;
		cout << "\n" << TextMessage << endl;
	}
};

class clsEmployee :public clsPerson {
private:
	string _Title, _Department;
	float _Salary;

public:
	clsEmployee(int ID, string FirstName, string LastName, string Email, string PhoneNumber, string Title, string Department, float Salary) :clsPerson(ID, FirstName, LastName, Email, PhoneNumber) {
		_Title = Title;
		_Department = Department;
		_Salary = Salary;
	}

	void setTitle(string Title) {
		_Title = Title;
	}
	string Title() {
		return _Title;
	}

	void setDepartment(string Department) {
		_Department = Department;
	}
	string Department() {
		return _Department;
	}

	void setSalary(float Salary) {
		_Salary = Salary;
	}
	float Salary() {
		return _Salary;
	}

	void Print() {
		cout << "\nInfo : ";
		cout << "\n***********************";
		cout << "\nID           : " << ID();
		cout << "\nFirst Name   : " << FirstName();
		cout << "\nLast Name    : " << LastName();
		cout << "\nFull Name    : " << Name();
		cout << "\nEmail        : " << Email();
		cout << "\nPhone Number : " << PhoneNumber();
		cout << "\nTitle        : " << _Title;
		cout << "\nDepartment   : " << _Department;
		cout << "\nSalary       : " << _Salary;
		cout << "\n***********************" << endl;
	}
};

class clsDeveloper :public clsEmployee {
private:
	string _MainProgrammingLanguage;
public:
	clsDeveloper(int ID, string FirstName, string LastName, string Email, string PhoneNumber, string Title, string Department, float Salary, string MainProgrammingLanguage) :clsEmployee(ID, FirstName, LastName, Email, PhoneNumber, Title, Department, Salary) {
		_MainProgrammingLanguage = MainProgrammingLanguage;
	}

	void setMainProgrammingLanguage(string MainProgrammingLanguage) {
		_MainProgrammingLanguage = MainProgrammingLanguage;
	}
	string MainProgrammingLanguage() {
		return _MainProgrammingLanguage;
	}

	void Print() {
		cout << "\nInfo : ";
		cout << "\n***********************";
		cout << "\nID                        : " << ID();
		cout << "\nFirst Name                : " << FirstName();
		cout << "\nLast Name                 : " << LastName();
		cout << "\nFull Name                 : " << Name();
		cout << "\nEmail                     : " << Email();
		cout << "\nPhone Number              : " << PhoneNumber();
		cout << "\nTitle                     : " << Title();
		cout << "\nDepartment                : " << Department();
		cout << "\nSalary                    : " << Salary();
		cout << "\nMain Programming Language : " << _MainProgrammingLanguage;
		cout << "\n***********************" << endl;
	}
};

int main() {
	
	clsDeveloper Dev(1, "Omar", "Mushref", "O@O.com", "077777", "Hello", "Web", 1200, "C++");
	Dev.Print();
	Dev.SendEmail("Hi", "How are you ? ");
	Dev.SendSMS("How are you ? ");

	system("pause>0");
	return 0;
}