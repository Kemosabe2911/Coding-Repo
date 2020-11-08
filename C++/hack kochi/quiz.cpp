#include<iostream>
using namespace std;

int main(){
    int n,m;
    int a[100][100];
    int i,j;
    cin>> n>> m;
    for(i=0 ; i<n ; i++ ){
        for(j=0 ; j<m ; j++ ){
            cin>>a[i][j];
        }
    }
    int cs=0, ct=0;
    int cst=0 ;
    for(i=0; i<n-1 ;i++){
        for(j=0 ; j<n; j++){
            if((a[i][j] == a[i+1][j]) && (a[i][j] ==1)){
                cst++;
            }
        }
        if(cst> cs){cs = cst;
        ct=0;
        cst=0;
        }
        if( cst ==cs){
            ct++;
        }
    }
    cout<<cs << '\n' << ct;
    return 0;
}