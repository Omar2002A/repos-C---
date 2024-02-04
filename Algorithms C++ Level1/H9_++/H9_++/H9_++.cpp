#include <iostream>
using namespace std;

enum enColor { Black, White, Red, Green };
enum enGendor { Male, Female };
enum enMaritalStatus { Single, Married };

struct stAddress
{
	string Country;
	string City;
};

struct stContactInfo
{
	string Phone;
	string Mail;
	stAddress Address;
};

struct stPerson
{
	string FirstName;
	string LastName;
	stContactInfo ContactInfo;

	enMaritalStatus MaritalStatus;
	enColor Color;
	enGendor Gendor;
};


int main()
{
	stPerson Person1;

	Person1.FirstName = "Omar";
	Person1.LastName = "Mushref";

	Person1.ContactInfo.Mail = "OmarMu@gmail.com";
	Person1.ContactInfo.Phone = "0798982249";
	Person1.ContactInfo.Address.Country = "Jordan";
	Person1.ContactInfo.Address.City = "Amman";

	Person1.Color = enColor::Black;
	Person1.Gendor = enGendor::Male;
	Person1.MaritalStatus = enMaritalStatus::Single;


}
