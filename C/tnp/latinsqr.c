#include <stdio.h>

int main(void) {
	// your code goes here
    int t,n,i,j,x,k,r,c,flg=0;
    int a[20][20],b[20][3];
    scanf("%d",&t);
    for(r=0;r<t;r++){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        b[r][0]=0;
        b[r][1]=0;
        b[r][2]=0;
        for(i=0;i<n;i++){
            b[r][0]=b[r][0]+a[i][i];
        }
        for(i=0;i<n;i++){
            flg=0;
            for(j=0;j<n;j++){
                for(x=0;x<n;x++){
                    if(x==j)
                        continue;
                    else
                    {
                        if(a[i][j]==a[i][x]){
                            flg=1;
                            b[r][1]++;
                            break;
                        }
                    }
                }
                if(flg==1)
                    break;
            }
        }
        for(i=0;i<n;i++){
            flg=0;
            for(j=0;j<n;j++){
                for(x=0;x<n;x++){
                    if(x==j)
                        continue;
                    else
                    {
                        if(a[j][i]==a[x][i]){
                            flg=1;
                            b[r][2]++;
                            break;
                        }
                    }
                }
                if(flg==1)
                    break;
            }
        }
    }
    for(i=0;i<t;i++){
            printf("Case %d: %d %d %d \n",i+1,b[i][0],b[i][1],b[i][2]);
        }
	return 0;
}
