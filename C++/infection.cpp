#include<iostream>
using namespace std;

int main(){
    int n,m;
    int inr[100][100],adj[100][100];
    int q,s[100][100];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(j=0;j<n;j++){
            adj[i][j]=0;
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<2;j++){
            cin>>inr[i][j];
        }
    }
    
    return 0;
}