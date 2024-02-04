#include <iostream>
#include <string>
using namespace std;

string ReadText()
{
	string text;
	cout << "Enter Text : ";
	getline(cin, text);
	return text;
}

string EncryptText(string Text, short EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = char((int)Text[i] + EncryptionKey);
	}
	return Text;
}

string DecryptText(string Text, short EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = char((int)Text[i] - EncryptionKey);
	}
	return Text;
}

int main()
{
	const short EncryptionKey = 2;
	
	string Text = ReadText();
	string TextAfterEncryption = EncryptText(Text, EncryptionKey);
	string TextAfterDecryption = DecryptText(TextAfterEncryption, EncryptionKey);

	cout << "\n The Orginal Text : " << Text << 
		"\n The Encryption Text : " << TextAfterEncryption << 
		"\n The Decryption Text : " << TextAfterDecryption << endl;
	
	return 0;
}