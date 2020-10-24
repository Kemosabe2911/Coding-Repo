#include<iostream>

using namespace std;

int main(){
    int m,n,k,i,j,small,pos=-1;
    int a[100];
    cin>>m>>n>>k;
    for(i=0;i<m;i++){
        cin>>a[i];
    }
    for(i=0;i<k;i++){
        small=999;
        for(j=0;j<m;j++){
            if(small>a[j]){
                small=a[j];
                pos=j;
            }
        }
        a[pos]=n-a[pos];
    }
    int sum=0;
    for(i=0;i<m;i++){
        sum+=a[i];
    }
    cout<<sum;
    return 0;
}