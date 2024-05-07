#include <iostream>
#include <string>
using namespace std;

class SimpleDES {
public:
    string Encrypt(const string& plaintext) {
        string ciphertext = "";
        for (int i = plaintext.length() - 1; i >= 0; i--) {
            ciphertext += isupper(plaintext[i]) ? tolower(plaintext[i]) : toupper(plaintext[i]);
        }
        return ciphertext;
    }

    // Function to "decrypt" a string
    string Decrypt(const string& ciphertext) {
        return Encrypt(ciphertext); 
    }
};

int main() {
    SimpleDES des;
    string text;

    cout << "Enter plaintext: ";
    getline(cin, text);

    string encrypted = des.Encrypt(text);
    cout << "Encrypted text: " << encrypted << endl;

    string decrypted = des.Decrypt(encrypted);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
