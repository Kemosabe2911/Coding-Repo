#include<iostream>
using namespace std;

int main(){
    int n,i,d;
    int a[100];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>d;
    int l[100],r[100],v[100];
    for(i=0;i<d;i++){
        cin>>l[i]>>r[i]>>v[i];
    }
    int sum=0;
    for(i=0;i<d;i++){
        sum+=v[i];
    }
    cout<<sum;
    return 0;
}