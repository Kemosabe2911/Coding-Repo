#include<iostream>
using namespace std;
int main(){
    int a[100],b[100],c[100],d[100];
    int t,n,x,y,v;
    int sa,sb,sc,sd;
    int ap=0,bp=0,cp=0,dp=0;
    int i,j;
    cin>>t;
    for ( i = 0; i < t; i++)
    {
        /* code */
        int flg=0;
        cin>>n;
        for(j=0;j<n;j++){
            cin>>x>>y>>v;
            if(x>0 && y>0){
                a[ap++]=v;
            }
            else if ( x>0 && y < 0)
            {
                /* code */
                b[bp++]=v;
            }
            else if ( x<0 && y < 0)
            {
                /* code */
                c[cp++]=v;
            }
            else
            {
                d[dp++]=v;
            }
            
        }
        sa=a[0];
        sb=b[0];
        sc=c[0];
        sd=d[0];
        if(sa==sb){
            if(sb==sc){
                if(sc==sd){
                    cout<<"NO \n";
                }
                else
                {
                    cout<<"YES \n";
                }
            }
            else
            {
                cout<<"YES \n";
            }
        }
        else if(sa==sc)
        {
            cout<<"NO \n";
        }
        

    }
    


    return 0;
}