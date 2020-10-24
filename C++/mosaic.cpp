#include <iostream>

using namespace std;

int main() {
    int n,cb,cp,i;
    int b[100],p[100];
    int sumb=0,sump=0;
    int bc,pc;
    cin>>n>>cb>>cp;
    for (i = 0; i < n; i++)
    {
        /* code */
        cin>>b[i]>>p[i];
        sumb+=b[i];
        sump+=p[i];
    }
    //cout<<sumb<<sump;
    if(sumb%10==0){
        bc=sumb/10;
    }
    else
    {
        /* code */
        bc=sumb/10;
        bc++;
    }
    if(sump%10==0){
        pc=sump/10;
    }
    else
    {
        /* code */
        pc=sump/10;
        pc++;
    }
    //cout<<bc<<pc;
    int output= (bc*cb)+(pc*cp);
    cout<<output;
    return 0;
}