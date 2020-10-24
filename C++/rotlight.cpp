#include<iostream>
using namespace std;

void rightrot(int a[], int n){
    int temp=a[n-1],i;
    for(i=0;i<n;i++){
        a[i+1]=a[i];
    }
    a[i]=temp;
}

int main(){
    int n,t;
    int arr[100][100];
    int vis[100];
    int i,j;
    cin>>n>>t;
    for(i=0;i<t;i++){
        arr[0][i]=0;
        vis[i]=0;
    }
    for(i=0;i<n;i++){
        cin>>j;
        arr[0][j]=1;
        vis[j]=1;
    }

    return 0;
}