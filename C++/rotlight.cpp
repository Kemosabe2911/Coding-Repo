#include<iostream>
using namespace std;

void rightrot(int a[], int n){
    int temp,i,j;
    for(j=0;j<n;j++){

    }
    for(i=0;i<n;i++){
        a[i+1]=a[i];
    }
    a[i]=temp;
}

int main(){
    int n,t,p;
    int temp;
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
    int k=1;
    while(1){
        for(i=0;i<t;i++){
            arr[k][i]=arr[k-1][i];
            //rightrot(arr[k],t);
        }
        for(p=0;p<k;p++){
            temp=arr[k][t-1];
            for(i=0;i<n;i++){
                arr[k][i+1]=arr[k][i];
            }
            arr[k][0]=temp;
        }
        k++;
        if(k==t){
            break;
        }
    }
    for(i=0;i<t;i++){
        for(j=0;j<t;j++){
            cout<<arr[i][j];
        }
    cout<<"\n";
    }
    return 0;
}