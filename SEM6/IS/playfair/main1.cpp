//implementation of playfair cipher
#include <iostream>
#include <string>
using namespace std;
int flag=0, pl=1;
string genKey(string k){
    string unik;
    bool seen[26]={false};
    for(char ch:k){
        ch=toupper(ch);
        if(ch=='J'){
            ch='I';
        }
        if(!seen[ch-'A']){
            unik+=ch;
            seen[ch-'A']=true;
        }
    }
    char alp='A';
    while(alp<='Z'){
        if(alp!='J' && !seen[alp-'A']){
            unik+=alp;
            seen[alp-'A']=true;
        }
        alp++;
    }

    return unik;
}

string genPair(string text){
    string keep="";
    for(int i=0; i<text.length(); i++){
        if(text[i]==text[i+1]){
            flag=1;
            pl=i+1;
            keep+=text[i];
            keep+='X';
        }
        else{
            keep+=text[i];
        }
    }

    if((keep.length()%2) != 0 ){
        keep+='Z';
    }
    return keep;
}

string encrpt(string tb[5][5], string p){
    string ans,p1,p2;
    int x1,x2,y1,y2,n;
    n=p.length();
    cout<<"Length of pair string: "<<n<<endl;
    cout<<"The key table: "<<endl;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout<<tb[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Encode starts: "<<endl;
    for(int i=0; i<n; i=i+2)
    {
        p1=p[i];
        p2=p[i+1];
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                if(tb[j][k]==p1){
                    x1=j;
                    y1=k;
                }
                if(tb[j][k]==p2){
                    x2=j;
                    y2=k;
                }
            }
        }
        if(x1==x2){
            ans=tb[x1][(y1+1)%5];
            ans+=tb[x1][(y2+1)%5];
        }
        else if(y1==y2){
            ans+=tb[(x1+1)%5][y1];
            ans+=tb[(x2+1)%5][y2];
        }
        else{
            ans+=tb[x1][y2];
            ans+=tb[x2][y1];
        }
    }

    return ans;
}

string decrpt(string tb[5][5], string p){
    string ans,p1,p2;
    int x1,x2,y1,y2,n;
    n=p.length();
    cout<<"decode starts: "<<endl;
    for(int i=0; i<n; i=i+2)
    {
        p1=p[i];
        p2=p[i+1];
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                if(tb[j][k]==p1){
                    x1=j;
                    y1=k;
                }
                if(tb[j][k]==p2){
                    x2=j;
                    y2=k;
                }
            }
        }
        if(x1==x2){
            ans=tb[x1][(y1-1)%5];
            ans+=tb[x1][(y2-1)%5];
        }
        else if(y1==y2){
            ans+=tb[(x1-1)%5][y1];
            ans+=tb[(x2-1)%5][y2];
        }
        else{
            ans+=tb[x1][y2];
            ans+=tb[x2][y1];
        }
    }
    if(flag==1){
        p1=ans;
        p2=p1.substr(0,pl);
        ans=p2;
        p2=p1.substr(pl+1,p1.length());
        ans+=p2;
    }

    return ans;
}

int main(){
    string key, text;
    string enc, dec;
    string table[5][5];
    cout<<"Enter the key!"<<endl;
    cin>>key;
    cout<<"Enter the text:"<<endl;
    cin>>text;
    cout<<"Your key and pair are:"<<endl;
    string ukey=genKey(key);
    string pr=genPair(text);
    cout<<"key: "<<ukey<<" Pair: "<<pr<<endl;
    int t=0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            table[i][j]=ukey[t];
            t++;
        }
    }
    enc=encrpt(table, pr);
    dec=decrpt(table,enc);
    cout<<"Encrypted message: "<<enc<<endl;
    cout<<"Decrypted message: "<<dec<<endl;
    return 0;
}