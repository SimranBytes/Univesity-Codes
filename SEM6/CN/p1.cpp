//Lab sheet1 (graph in form of adjacency matrix)
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number of nodes/vertices:"<<endl;
    cin>>n;
    int mt[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                mt[i][j]=0;
            }
            else{
                mt[i][j]=1000;
            }
        }
    }
    
    int v;
    cout<<"Enter the number of edges: "<<endl;
    cin>>v;
    if (v>=n*(n-1)){
        cout<<"The max edges can be "<<n*(n-1)<<endl; 
    }
    else{
        for(int i=0; i<v;i++){
            int x,y,w;
            cout<<"Enter the edges"<<endl;
            cin>>x>>y;
            if(x==y){
                cout<<"Same edge cannot be added:"<<endl;
                break;
            }
            else{
                cout<<"Enter weight:"<<endl;
                cin>>w;
                mt[x-1][y-1]=w;
                mt[y-1][x-1]=w;
            }
        }
    }
    
    for(int i =0; i<n ; i++){
        for(int j=0; j<n; j++){
            cout<<mt[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}