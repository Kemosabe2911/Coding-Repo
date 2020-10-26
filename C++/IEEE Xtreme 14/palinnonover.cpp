#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli is_palin[2010][2010];
 string s;
 int dp1[2010],dp2[2010];
lli  solve(int start,int end)
 {
 // cout<<start<<" "<<end<<endl;
    if(is_palin[start][end]!=-1) return is_palin[start][end];
    if(start>end) return -1;
    else
    {
     
        if(s[start]==s[end])
         {
          // cout<<" inside call "<<endl;
           
          is_palin[start][end]=solve(start+1,end-1);
           //cout<<
      }
      else 
      is_palin[start][end]=-1;
      return is_palin[start][end];
      
    }
 }
int main()
 {
   
  cin>>s;
  memset(is_palin,-1,sizeof is_palin);
  
   int len=s.length();
   for(int i=0;i<len;i++) is_palin[i][i]=1;
   for(int i=0;i<len-1;i++) if(s[i]==s[i+1]) is_palin[i][i+1]=1;
   
   solve(0,len-1);
   
    for(int i=0;i<len;i++)
    {
      for(int j=i;j<len;j++)
       {
        is_palin[i][j]=solve(i,j);
    }
   
    }
    
    lli ans=0;
     //  cal of no of string palindrom which terminate at index i as the last char 
      dp1[0]=1;
      
      for(int i=1;i<len;i++)
       {
  
         for(int j=0;j<=i;j++)
          {
            if(is_palin[j][i]==1) dp1[i]++;
    }
    
   
    }
    
     // contains no of palindrom string in index i to n 
    dp2[len-1]=1;
    
      for(int i=len-2;i>=0;i--)
       {
        dp2[i]=dp2[i+1];
         for(int j=len-1;j>=i;j--)
          {
            if(is_palin[i][j]==1) dp2[i]++;
    }

    }
    

 for(int i=0;i<len-1;i++)
  {
 
    ans+=dp1[i]*dp2[i+1];
  
  }
 cout<<ans<<endl;

 }