//Implementation of Caesar Cipher
#include <iostream>
#include <string>
using namespace std;

string encrypt(string text, int key)
{
    string result = "";
    for (int i=0;i<text.length();i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i]+key-65)%26 +65);
        else if (islower(text[i]))
            result += char(int(text[i]+key-97)%26 +97);
    }
    return result;
}

string decrypt(string text, int key)
{
    string result = "";
    for (int i=0;i<text.length();i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i]-key-65+26)%26 +65);
        else if (islower(text[i]))
            result += char(int(text[i]-key-97+26)%26 +97);
    }
    return result;
}

int main()
{
    string text,enc,dec;
    int k;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the key: ";
    cin >> k;
    enc=encrypt(text, k);
    dec=decrypt(enc, k);
    cout << "Encrypted: " << enc << endl;
    cout << "Decrypted: " << dec << endl;
    return 0;
}