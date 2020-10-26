#include<iostream>
using namespace std;
class GFG 
{ 
      
/* function to multiply two numbers x and y*/
public : int multiply(int x, int y) 
{ 
    /* 0 multiplied with anything gives 0 */
    if(y == 0) 
    return 0; 
  
    /* Add x one by one */
    if(y > 0 ) 
    return (x + multiply(x, y-1)); 
  
    /* the case where y is negative */
    if(y < 0 ) 
    return -multiply(x, -y); 
} 
}; 

int main(){
    int w,h,a,b,m,c;
    cin>>w>>h>>a>>b>>m>>c;
    int flg=0;
    long tiles;
    int temp1,temp2;
    int inch;
    temp1=w/a;
    temp2=h/b;
    cout<<temp1<<" "<<temp2<<"\n";
    tiles=temp1*temp2;
    cout<<tiles;
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