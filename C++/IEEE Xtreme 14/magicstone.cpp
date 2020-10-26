#include<iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int countPairs(int arr[], int n) 
{ 
    int ans = 0; 
  
    // for each index i and j 
    for (int i = 0; i < n; i++) 
        for (int j = i+1; j < n; j++) 
  
            // finding the index with same 
            // value but different index. 
            if (arr[i] == arr[j]) 
                ans++; 
    return ans; 
} 

int main(){
    int n,q,i,j,temp,temp2,p;
    int pos=-1,count=0;
    int val[100],a[100],k[100],ind[100];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>val[i];
        a[i]=val[i];
    }
    for(i=0;i<n;i++){
        ind[i]=i;
    }
    cin>>q;
    for(i=0;i<q;i++){
        cin>>k[i];
    }
    temp=n;
    for(i=0;i<q;i++){
        for(p=0;p<temp;p++){
            a[p]=val[p];
            //cout<<a[p];
        }
        temp2=countPairs(a,temp);
        if(temp2==0){
            cout<<"-1 \n";
            continue;
        }
        //cout<<temp2<<"\n";
        temp=temp-temp2;
        if(temp2>1){
            temp=temp+1;
        }
        //cout<<temp<<"\n";
        if(k[i]==temp){
            cout<<i+1<<"\n";
        }
        else
        {
            cout<<"-1\n";
        }
    }
}