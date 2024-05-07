//finding the class of the IPv4 address
#include <bits/stdc++.h>
using namespace std;

string decimalToBinary(int n) {
    string binary = bitset<8>(n).to_string(); 
}

char speclass(string ip) {
    int firstOctet = stoi(ip.substr(0, ip.find('.')));
    string binary = decimalToBinary(firstOctet);

    if (binary.substr(0, 1) == "0") {
        return 'A';
    } else if (binary.substr(0, 2) == "10") {
        return 'B';
    } else if (binary.substr(0, 3) == "110") {
        return 'C';
    } else if (binary.substr(0, 4) == "1110") {
        return 'D';
    } else if (binary.substr(0, 4) == "1111") {
        return 'E';
    } else {
        cout << "Invalid IP Address" << endl;
        return '\0';
    }
}

void id(char cl, string ip)
{
    string net="", host="";
    if (cl=='A'){
        net=ip.substr(0,ip.find('.'));
        host=ip.substr(ip.find('.')+1);
    }
    if(cl=='B'){
        net=ip.substr(0,ip.find('.', ip.find('.')+1));
        host = ip.substr(ip.find('.', ip.find('.') + 1) + 1);
    } else if (cl == 'C') {
        net = ip.substr(0, ip.find('.', ip.find('.', ip.find('.') + 1) + 1));
        host = ip.substr(ip.find('.', ip.find('.', ip.find('.') + 1) + 1) + 1);
    }

    cout<<"Network id is: "<<net<<endl<<"Host id is: "<<host<<endl;
}

int main() {
    string ipv;
    char cls;
    cout << "Enter the IPv4 address: ";
    cin >> ipv;
    cls=speclass(ipv);
    if(cls != '\0')
    {
        cout<<"Class if the IPv4 Address is: "<<cls<<endl;
        switch (cls){
        case 'A':
            cout<<"Range is 1.0.0.0 to 127.0.0.0 and the first octat range from 1 to 127"<<endl;
            break;
        case 'B':
            cout<<"Range is 128.0.0.0 to 191.255.0.0 and the first octat range from 128 to 191"<<endl;
            break;
        case 'C':
            cout<<"Range is 192.0.0.0 to 223.255.255.0 and the first octat range from 192 to 223"<<endl;
            break;
        case 'D':
            cout<<"Range is 224.0.0.0 to 239.255.255.255 and the first octat range from 224 to 239"<<endl;
        case 'E':
            cout<<"Range is 240.0.0.0 to 255.255.255.255 and the first octat range from 240 to 255"<<endl;
            break;
        } 
    }
    id(cls,ipv);
    return 0;
}
