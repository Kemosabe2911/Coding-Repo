#include<iostream>
using namespace std;

int main(){
    int n,m;
    int inr[100][100],adj[100][100];
    int q,s[100][100];
    int a,b;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j]=0;
        }
    }
    int i,j;
    for(i=0;i<m;i++){
        cin>>inr[i][0]>>inr[i][1];
        a=inr[i][0];
        b=inr[i][1];
        adj[a-1][b-1]=1;
    }
    /*
    for(int i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<adj[i][j];
        }
        cout<<"\n";
    }   */ 
    cin>>q;
    for(i=0;i<q;i++){
        for(j=0;j<2;j++){
            cin>>s[i][j];
        }
    }

    return 0;
}