#include <iostream>
#include <math.h>
#include <string>
using namespace std;

 
int main() {
    int temp, oct=0, i, t, flag =0;
    double n, octl;
    cin>>n;

    int num = n;

    if(num != n){
        num  = n * pow(8,8);
        flag =1;
    }
    cout<<"num: "<<num<<endl;
    while(num){
        i=num%8;
        cout<<"i: "<<i<<endl;
        oct=(oct*10)+i;
        cout<<"oct: "<<oct<<endl;
        num=num/8;
    }

    temp=oct;
    oct=0;

    while(temp){
        i=temp%10;
        oct=(oct*10)+i;
        temp=temp/10;
    }
    cout<<"oct: "<<oct<<endl;
    if(flag == 1){
        octl = oct/pow(10,8);
    }
    else octl = oct;

    cout<<"octal"<<octl<<endl;

    return 0;
}