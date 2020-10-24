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



    return 0;
}