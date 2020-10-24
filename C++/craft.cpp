#include<iostream>

using namespace std;

int largest(int a[], int n){
    int large=0;
    for(int i=0; i<n; i++){
        if(a[i]>large){
            large=a[i];
            pos=i;
        }
    }
    return large;
}

int main(){
    int c,n,p,w;
    cin>>c>>n>>p>>w;
    int i,temp;
    int count=0;
    int a[100];
    i=0;
    while(i<n){
        if(w-p<0){
            a[i]=w;
        }
        else{
            a[i]=p;
            w=w-p;
        }
        i++;
    }
    /*for(i=0;i<n;i++){
        cout<<a[i]<<"\n";
    }*/
    if(w<c){
        cout<<"0";
    }
    

    return 0;
}