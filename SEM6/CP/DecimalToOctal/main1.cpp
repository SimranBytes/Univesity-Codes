#include <iostream>
#include <string>

using namespace std;

string decimalToOctal(double decimal) {
    int integerPart = decimal;
    double fractionalPart = decimal - integerPart;

    string octalInteger = "";
    while (integerPart > 0) {
        int remainder = integerPart % 8;
        octalInteger = to_string(remainder) + octalInteger;
        integerPart /= 8;
    }

    string octalFractional = "";
    const int maxPrecision = 10;
    for (int i = 0; i < maxPrecision; ++i) {
        fractionalPart *= 8;
        int digit = fractionalPart;
        octalFractional += to_string(digit);
        fractionalPart -= digit;
    }

    return octalInteger + "." + octalFractional;
}

int main() {
    double decimal;
    cin >> decimal;

    string octal = decimalToOctal(decimal);
    cout <<octal<<endl;

    return 0;
}
