#include<iostream>

using namespace std;

int main(){
    int m[100],n[100],k[100],i,j,small,pos=-1;
    int t,p;
    int sum[100];
    int a[100];
    cin>>t;
    for(p=0;p<t;p++){
        cin>>m[p]>>n[p]>>k[p];
        sum[p]=0;
    }
    for(p=0;p<t;p++){
        for(i=0;i<m[p];i++){
        cin>>a[i];
        }
        for(i=0;i<k[p];i++){
            small=999;
            for(j=0;j<m[p];j++){
                if(small>a[j]){
                    small=a[j];
                    pos=j;
                }
            }
            a[pos]=n[p]-a[pos];
        }
        for(i=0;i<m[p];i++){
            sum[p]+=a[i];
        }
    }
    for(p=0;p<t;p++){
        cout<<sum[p]<<"\n";
    }
    return 0;
}