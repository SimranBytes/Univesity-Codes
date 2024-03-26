//Implementation of Dijkstra Shortest Path Algorithm
#include <iostream>
#include <string>
using namespace std;

int minDis(int d[], bool u[], int n){
    int min=INT_MAX, min_index;
    for(int i=0; i<n; i++){
        if(u[i]==false && d[i]<=min){
            min=d[i],min_index=i;
        }
    }
    return min_index;
}

void print(int d[], int n){
    cout<<"Vertex \t\t Distance from Source"<<endl;
    for(int i=0; i<n; i++){
        cout<<i<<"\t\t\t"<<d[i]<<endl;
    }
}

void dijkstra(int m[][n], int s, int n){
    int dst[n];
    bool uvn[n];
    for(int i=0; i<n; i++){
        dst[i]=INT_MAX;
        uvn[i]=false;
    }
    dst[s]=0;
    for(int i=0; i<n-1; i++)
    {
        int u=minDis(dst,uvn, n);
        uvn[u]=true;
        for(int j=0; j<n; j++){
            if(!uvn[j] && m[u][j] && dst[u]!=INT_MAX && dst[u]+m[u][j]<dst[j]){
                dst[j]=dst[u]+m[u][j];
            }
        }
    }
    print(dst, n);
}

int main(){
    int n,src;
    cout<<"Enter the number of nodes/vertices:"<<endl;
    cin>>n;
    int mt[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                mt[i][j]=0;
            }
            else{
                mt[i][j]=99;
            }
        }
    }
    int v;
    cout<<"Enter the number of Edges: (should be less than: "<<n*(n-1)<<")"<<endl;
    cin>>v;
    if(v>n*(n-1)){
        cout<<"Invalid Input!";
    }
    else{
        for(int i=0; i<v; i++){
            int x,y,w;
            cout<<"Enter your edges set "<<i<<endl;
            cin>>x>>y;
            if(x==y){
                cout<<"Same edge cannot be added:"<<endl;
                break;
            }
            cout<<"Enter the weight:"<<endl;
            cin>>w;
            mt[x-1][y-1]=w;
            mt[y-1][x-1]=w;
        }
    }
    cout<<"Your graph formed is: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<mt[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"Enter your source node: "<<endl;
    cin>>src;
    dijkstra(mt,src,n);
    return 0;
}
