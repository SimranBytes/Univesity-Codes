//converting the dot IPv4 addresses to Binary IPv4 addresses
#include <bits/stdc++.h>

using namespace std;

void printBinary(const string& ipv) {
    int start = 0, end = ipv.find('.');
    while(end != string::npos) {
        string octet = ipv.substr(start, end - start);
        cout << bitset<8>(stoi(octet)) << ".";
        start = end + 1;
        end = ipv.find('.', start);
    }
    string lastOctet = ipv.substr(start, end - start); 
    cout << bitset<8>(stoi(lastOctet)) << endl; 
}

int main()
{
    string ipv;
    cout << "Enter the IPv4 address: ";
    cin >> ipv;

    if (count(ipv.begin(), ipv.end(), '.') != 3) {
        cout << "Invalid IPv4 address format." << endl;
    } else {
        printBinary(ipv);
    }

    return 0;
}
