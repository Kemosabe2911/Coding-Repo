#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    int locc,flag=0;
    char first[20],second[20],third[20],opfirst[20],opsecond[20];
    FILE *input,*symtab,*optab,*inter;
    input=fopen("input.txt","r");
    symtab=fopen("symtab.txt","w+");
    inter=fopen("inter.txt","w+");
    fscanf(input,"%s%s%s",first,second,third);
    if(strcmp(second,"START")==0){
        locc=atoi(third);
    }
    else
        locc=0;
    fprintf(inter,"%s\t%s\t%s\t%s\n","-",first,second,third);
    fscanf(input,"%s%s%s",first,second,third);
    while (strcmp(second,"END")!=0)
    {
        fprintf(inter,"%d\t%s\t%s\t%s\n",locc,first,second,third);
        if(strcmp(first,"-")!=0){
            fprintf(symtab,"%d\t%s\n",locc,first);
        }
        optab=fopen("optab.txt","r");
        fscanf(optab,"%s%s",opfirst,opsecond);
        while (strcmp(opfirst,"END")!=0)
        {
            fscanf(optab,"%s%s",opfirst,opsecond);
            if(strcmp(second,opfirst)==0){
                flag=1;
                locc+=3;
                break;
            }
        }
        if(flag==0){
            if(strcmp(second,"BYTE")==0)
                locc+=strlen(third)-2;
            else if (strcmp(second,"RESB")==0)
                locc+=atoi(third);
            else if(strcmp(second,"WORD")==0)
                locc+=3;
            else if(strcmp(second,"RESW")==0)
                locc+=(3*(atoi(third)));
        }
        fscanf(input,"%s%s%s",first,second,third);
        flag=0;
    }
    fprintf(inter,"%d\t%s\t%s\t%s\n",locc,first,second,third);
    fclose(input);
    fclose(optab);
    fclose(inter);
    fclose(symtab);
}