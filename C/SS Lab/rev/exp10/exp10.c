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