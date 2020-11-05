#include<stdio.h>
#include<string.h>
struct DEFTAB
{
char opcode[10];
char operand[50];
}dt[50];
struct NAMTAB
{
char name[10];
int start;
int end;
}nt[5];
struct ARGTAB
{
char arg[10];
}at[5];
struct PARAMTAB
{
char param[10];
char val[4];
}pt[5];
int n,p,m,g;
int check_param(char x[50])
{
int i;
for(i=0;i<p;i++)
if(strcmp(pt[i].param,x)==0)
return i;
return -1;
}
int check_macro(char x[20])
{
int i;
for(i=0;i<m;i++)
if(strcmp(nt[i].name,x)==0)
return i;
return -1;
}
void store()
{
FILE *f,*fp;
int k,i,j;
char a[20],b[20],c[40],temp[20],lab[20];
n=0;p=0;m=0;g=0;
f=fopen("input.txt","r");
fp=fopen("exp.txt","w");
while(!feof(f))
{
fscanf(f,"%s\t%s\t%s\n",a,b,c);
if(strcmp(b,"MACRO")==0)
{
strcpy(nt[m].name,a);
nt[m].start=0;
k=1;
j=0;
i=0;
while(c[i]!='\0')
{
if(c[i]!=',')
{
temp[j]=c[i];
j++;
}
else
{
temp[j]='\0';
j=0;
strcpy(pt[p].param,temp);
pt[p].val[0]='?';
pt[p].val[1]=p+49;
pt[p].val[2]='\0';
p++;
}
i++;
}
temp[j]='\0';
strcpy(pt[p].param,temp);
pt[p].val[0]='?';
pt[p].val[1]=p+49;
pt[p].val[2]='\0';
p++;
strcpy(dt[n].opcode,b);
strcpy(dt[n].operand,c);
n++;
}
else if(k==1)
{
i=check_param(c);
strcpy(dt[n].opcode,b);
if(i==-1)
strcpy(dt[n].operand,c);
else
strcpy(dt[n].operand,pt[i].val);
n++;
if(strcmp(b,"MEND")==0)
{
k=0;
nt[m].end=n-1;
m++;
}
}
else if((check_macro(b))!=-1)
{
i=0;
g=0;
j=0;
while(c[i]!='\0')
{
if(c[i]!=',')
{
temp[j]=c[i];
j++;
}
else
{
temp[j]='\0';
j=0;
strcpy(at[g].arg,temp);
g++;
}
i++;
}
temp[j]='\0';
strcpy(at[g].arg,temp);
g++;
strcpy(a,"NULL");
for(i=1;i<n-1;i++)
{
if(dt[i].operand[0]=='?')
{
j=dt[i].operand[1]-49;
strcpy(temp,at[j].arg);
}
else
strcpy(temp,dt[i].operand);
fprintf(fp,"%s\t%s\t%s\n",a,dt[i].opcode,temp);
}
}
else
 fprintf(fp,"%s\t%s\t%s\n",a,b,c);
}
fclose(f);
fclose(fp);
}
main()
{
int i;
store();
printf("\nDEFTAB:\n");
for(i=0;i<n;i++)
printf("%s\t%s\n",dt[i].opcode,dt[i].operand);
printf("\nNAMETAB:\nNAME\tSTART\tEND\n");
for(i=0;i<m;i++)
printf("%s\t%d\t%d\n",nt[i].name,nt[i].start,nt[i].end);
printf("\nARGTAB \nPosition\tArgument\n");
for(i=0;i<g;i++)
printf("%d\t\t%s\n",i+1,at[i].arg);
}
