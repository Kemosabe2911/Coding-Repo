#include<iostream>
using namespace std;
int main(){
    int w,h,a,b,m,c;
    cin>>w>>h>>a>>b>>m>>c;
    int tiles=0,flg=0;
    int temp1,temp2;
    int inch;
    temp1=w/a;
    temp2=h/b;
    tiles=(w/a)*(h/b);
    //cout<<tiles;
    if(w%a > 0){
        tiles+=(h/b);
        flg=1;
    }
    if(h%b >0){
        tiles+=(w/a);
        if(flg==1){
            tiles++;
        }
    }
    //cout<<tiles;
    int price= (tiles/10)+1;
    price*=m;
    if(w%a > 0){
        inch=h;
    }
    if(h%b >0){
        inch+=w;
    }
    price+=(c*inch);
    cout<<price;
    return 0;
}