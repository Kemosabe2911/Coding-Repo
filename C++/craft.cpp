#include<iostream>

using namespace std;

int largest(int a[], int n){
    int large=0,pos;
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
    int l;
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
        l=i;
    }
    int size=l;
    /*for(i=0;i<n;i++){
        cout<<a[i]<<"\n";
    }*/
    while (1)
    {
        /* code */
        if(c>a[l-1]){
            if(a[l-2]>(c-a[l-1])){
                a[l-2]=a[l-2]-(c-a[l-1]);
                a[l-1]=0;
                count++;
            }
            l--;
        }
        else
        {
            break;
        }
        
        /*for(i=0;i<size;i++){
            if(a[i]==0){
                a[i]=-1;
            }
        }*/
    }
    cout<<count;
    
    

    return 0;
}