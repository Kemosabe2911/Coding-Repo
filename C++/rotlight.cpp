#include<iostream>
using namespace std;

void rightrot(int a[], int n){
    int temp1=a[n-1],i;
    for(i=0;i<n;i++){
        a[i+1]=a[i];
    }
    a[0]=temp1;

}

int main(){
    int n,t,p,flg=0;
    int i,j;
    int temp;
    int arr[100];
    int init[100];
    int a[100];
    int vis[100];
    cin>>n>>t;
    for(i=0;i<t;i++){
        init[i]=0;
        vis[i]=0;
    }
    for(i=0;i<n;i++){
        cin>>j;
        init[j]=1;
        vis[j]=1;
    }
    for(i=0;i<t;i++){
            arr[i]=init[i];
            //rightrot(arr[k],t);
    }
    int k=0;
    while(1){
        rightrot(arr,t);
        for(p=0;p<t;p++){
            if(init[p]==arr[p]){
                flg=0;
            }
            else
            {
                /* code */
                flg=1;
                k++;
                break;
            }
            
        }
        if(flg==0){
            break;
        }
    }
    cout<<k;
    return 0;
}