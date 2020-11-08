#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    int a[100];
    int p[10],q[10];
    cin>>n;
    int c=0,b=0;
    int i,j, diff ,small=99999;
    for (i=0 ; i < n; i++)
    {
        /* code */
        cin>>a[i];
    }
    for( i=0;i< n;i++){
        for( j=i; j<n;j++){
            if(i!=j){
                diff = a[i] - a[j];
                if(diff < 0){
                    diff= diff*(-1);
                }
                if(small > diff){
                    c=0;
                    b=0;
                    p[c] = a[i];
                    q[b] = a[j];
                    small=diff;
                }
                if(small == diff){
                    if(p[c] == a[i]){
                        if(q[b] == a[j]){
                            continue;
                        }
                    }
                    c++;
                    b++;
                    p[c]=a[i];
                    q[b]=a[j];
                }    
            }
        }
    }
    for(i=c;i>=0;i--){
        cout<< p[i] << " "<< q[i] << " ";
    }
    return 0;
}
