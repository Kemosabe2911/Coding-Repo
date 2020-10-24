#include<iostream>

using namespace std;

int main(){
    int c,n,p,w;
    cin>>c>>n>>p>>w;
    int i,temp;
    int a[100];
    i=0;
    while(i<n){
        if(w==0){
            cout<<"0";
            break;
        }
        else if(w-p<0){
            a[i]=w;
        }
        else{
            a[i]=p;
            w=w-p;
        }
        i++;
    }
    for(i=0;i<n;i++){
        cout<<a[i]<<"\n";
    }
    return 0;
}