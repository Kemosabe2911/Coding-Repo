#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 10

void swap(char *x, char *y){
    char t=*x; *x=*y; *y=t;
}
void reverse(char str[], int length){
    int start=0;
    int end= length-1;
    while(start<end){
        swap((str+start),(str+end));
        start++;
        end--;
    }
}
char* itoa(int num, char* str, int base){
    int i=0;
    int isNegative=0;
    if (num==0){
        str[i++]='0';
        str[i]='\0';
        return str;
    }
    if(num<0 && base==10){
        isNegative=1;
        num=-num;
    }
    while (num!=0)
    {
        int rem= num%base;
        str[i++]= (rem>9)? (rem-10)+'a' : rem+'0';
        num=num/base;
    }
    if(isNegative){
        str[i++]='-';
    }
    str[i]='\0';
    reverse(str,i);
    return str;
}
void string2hexString(char* input, char* output){
    int loop;
    int i;
    i=0;
    loop=2;
    while (loop<strlen(input)-1)
    {
        sprintf((char*)(output+i),"%02X",input[loop]);
        loop+=1;
        i+=2;
    }
    output[i++]='\0';
}
struct input{
    char label[10],operand[10],opcode[10],mnemonic[5];
    int loc,locctr;
};
struct input table[MAX];
struct symtab{
    char sym[10];
    int f,val,ref;
};
struct symtab symtab1[MAX];
void main(){
    int f1,i=1,j=1,locctr,flag,x,starting;
    char add[10],code[10],mnemcode[5];
    FILE *fp1,*fp2,*fp3;
    printf("Implementation of A Single Pass Assembler");
    printf("\n----------------------------------------\n\n");
    fp1=fopen("input.txt","r");
    fp2=fopen("optab.txt","r");
    fscanf(fp1, "%s%s%s",table[i].label,table[i].opcode,table[i].operand);
    if(strcmp(table[i].opcode,"START")==0){
        strcpy(table[i].mnemonic,"00");
        table[i].loc=atoi(table[i].operand);
        locctr=atoi(table[i].operand);
        i++;
        fscanf(fp1,"%s%s%s",table[i].label,table[i].opcode,table[i].operand);
    }
    else{
        locctr=0;
    }
    starting=locctr;
    while(!feof(fp1)){
        if(strcmp(table[i].label,"**")!=0){
            for(x=1;x<j;x++){
                f1=0;
                if((strcmp(symtab1[x].sym,table[i].label)==0) && symtab1[x].f==1){
                    symtab1[x].val=locctr;
                    symtab1[x].f=0;
                    table[symtab1[x].ref].loc=locctr;
                    f1=1;
                    break;
                }
            }
            if(f1==0){
            strcpy(symtab1[j].sym,table[i].label);
            symtab1[j].val=locctr;
            symtab1[j].f=0;
            j++;
            }
        }
        fscanf(fp2,"%s%s",code,mnemcode);
        table[i].locctr=locctr;
        while (!feof(fp2))
        {
            if(strcmp(table[i].opcode,code)==0){
                strcpy(table[i].mnemonic,mnemcode);
                locctr+=3;
                for(x=1;x<=j;x++){
                    flag=0;
                    if(strcmp(table[i].operand,symtab1[x].sym)==0){
                        flag=1;
                        if(symtab1[x].f==0){
                            table[i].loc=symtab1[x].val;
                        }
                        break;
                    }
                }
                if(flag!=1){
                    strcpy(symtab1[j].sym,table[i].operand);
                    symtab1[j].f=1;
                    symtab1[j].ref=i;
                    j++;
                }
            }
            fscanf(fp2,"%s%s",code,mnemcode);
        }
    }
    rewind(fp2);
    if(strcmp(table[i].opcode,"WORD")==0){
        locctr+=3;
        strcpy(table[i].mnemonic,"00000");
        table[i].loc=atoi(table[i].operand);
    }
    else if(strcmp(table[i].opcode,"RESW")==0){
        locctr+=(3*(atoi(table[i].operand)));
    }
    else if(strcmp(table[i].opcode,"RESB")==0){
        locctr+=(atoi(table[i].operand));
    }
    else if(strcmp(table[i].opcode,"BYTE")==0)
}