#include <iostream>
using namespace std;


struct ForContact
{
	string Phone;
	string Email;
	string Facebook;
};

//struct About
//{
//	char Gender;
//	bool Married;
//};



struct Salary
{
	float In_Month;
	float In_Year;
};

struct Address
{
	string Country;
	string City;

};

struct Employee
{
	string FullName;
	short Age;
	Address TheAddress;
	Salary TheSalary;
	/*About AboutEmp;*/
	ForContact Contact;
};

enum Gendor { Male, Fmale };
enum Status { Single, Married };
enum MyFavColor { Black = 1, White = 2, Red = 3 };

int main()
{
	Employee E1;

	Gendor YourGendor;
	Status YourStatus;
	MyFavColor YourFavColor;
	YourGendor = Gendor::Male;
	YourStatus = Status::Single;
	YourFavColor = MyFavColor::Black;
	

	E1.FullName = "Omar Mushref.";
	E1.Age = 21;
	E1.TheAddress.Country = "Jordan";
	E1.TheAddress.City = "Amman";
	E1.TheSalary.In_Month = 10000;
	E1.TheSalary.In_Year = 12 * E1.TheSalary.In_Month;
	/*E1.AboutEmp.Gender = 'M';
	E1.AboutEmp.Married = false;*/
	E1.Contact.Email = "OmarMus@gmail.com";
	E1.Contact.Facebook = "Omar Mushref";
	E1.Contact.Phone = "0798982249";

	cout << "*******************" << "\n";
	cout << "Name : " << E1.FullName << "\n";
	cout << "Age : " << E1.Age << "\n";
	cout << "Country : " << E1.TheAddress.Country << "\n";
	cout << "City : " << E1.TheAddress.City << "\n";
	cout << "For Contact : \nPhone : " << E1.Contact.Phone << "\nEmail : " << E1.Contact.Email << "\nFacebook : "<<E1.Contact.Facebook<<"\n";
	cout << "Salary In Month = " << E1.TheSalary.In_Month << "\n";
	cout << "Salay In Year = " << E1.TheSalary.In_Year << "\n";
	/*cout << "Gender : " << E1.AboutEmp.Gender << "\n";
	cout << "Married ? " << E1.AboutEmp.Married << endl;*/
	cout << "Gendor : " << YourGendor << "\n";
	cout << "Married ? " << YourStatus << "\n";
	cout<<"FavColor : "<<YourFavColor<<"\n";
	cout << "*******************" << endl;

	return 0;
}