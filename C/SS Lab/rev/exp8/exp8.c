#include<stdlib.h>
#include<string.h>
#include<stdio.h>
void main(){
    char str;
    printf("---------------PASS1 ASSEMBLER-----------------\n");
    FILE *f1,*f2,*f3,*f4;
    int lc,sa,l,op1,o,len;
    char m1[20],la[20],op[20],otp[20];
    f1= fopen("input.txt","r");
    f3= fopen("symtab.txt","w");
    fscanf(f1,"%s %s %d", la, m1, &op1);
    printf("OUTPUT\n");
    if(strcmp(m1,"START")==0){
        sa=op1;
        lc=sa;
        printf("\t%s\t%s\t%d",la,m1,op1);
    }
    else
    {
        lc=0;
    }
    fscanf(f1,"%s %s",la,m1);
    while (!feof(f1))
    {
        fscanf(f1,"%s",op);
        printf("\n%d\t%s\t%s\t%s",lc,la,m1,op);
        if(strcmp(la,"-")!=0){
            fprintf(f3,"%d\t%s\n",lc,la);
        }
        f2=fopen("optab.txt","r");
        fscanf(f2,"%s %d",otp,&o);
        while (!feof(f2))
        {
            if(strcmp(m1,otp)==0){
                lc=lc+3;
                break;
            }
            fscanf(f2,"%s %d",otp,&o);
        }
        fclose(f2);
        if(strcmp(m1,"WORD")==0){
            lc=lc+3;
        }
        else if(strcmp(m1,"RESW")==0){
            op1=atoi(op);
            lc=lc+(3*op1);
        }
        else if (strcmp(m1,"RESB")==0)
        {
            op1=atoi(op);
            lc=lc+op1;
        }
        else if(strcmp(m1,"BYTE")==0){
            if(op[0]=='X'){
                lc=lc+1;
            }
            else
            {
                len=strlen(op)-2;
                lc=lc+len;
            }
        }
        fscanf(f1,"%s %s",la,m1);
    }
    if(strcmp(m1,"END")==0){
        fclose(f3);
        printf("\n");
        printf("\n\n symtab.txt \n\n");
        f4= fopen("symtab.txt","r");
        str = fgetc(f4);
        while (!feof(f4))
        {
            printf("%c",str);
            str = fgetc(f4);
        }
        printf("\n");
        fclose(f4);
        printf("Lenght: %d\n",lc-sa-3);      
    }
    fclose(f1);
    
}