#include<iostream>

using namespace std;

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
     while((c>=a[l-1]) && (a[l-1]!=0)){
            temp=c-a[l-1];
            if (a[l-2]>=temp)
            {
                /* code */
                a[l-2]-=temp;
                a[l-1]=0;
                count++;
                l--;
            }
            /*
            for(i=0;i<size;i++){
                cout<<a[i];
            }
            cout<<"\n";
            l--;
            cout<<l<<"\n";*/
            if(l==0){
                break;
            }
            
        }   
    
    /*for(i=0;i<n;i++){
        cout<<a[i]<<"\n";
    }
        
        while((c>=a[l-1]) && (a[l-1]!=0)){
            temp=c-a[l-1];
            if (a[l-2]>=temp)
            {
                a[l-2]-=temp;
                a[l-1]=0;
                count++;
                l--;
            }
            for(i=0;i<size;i++){
                cout<<a[i];
            }
            cout<<"\n";
            l--;
            cout<<l<<"\n";
            if(l==0){
                break;
            }
            
        }*/
    cout<<count;
    
    

    return 0;
}