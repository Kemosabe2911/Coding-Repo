#include <iostream>

using namespace std;

int main() {
    int n,cb,cp,i;
    int b[100],p[100];
    int sumb=0,sump=0;
    cin>>n>>cb>>cp;
    for (i = 0; i < n; i++)
    {
        /* code */
        cin>>b[i]>>p[i];
        sumb+=b[i];
        sump+=p[i];
    }
    cout<<sumb<<sump;
    
    return 0;
}