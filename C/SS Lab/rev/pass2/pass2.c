#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    int sa;
    char first[20],second[20],third[20],add[20],opfirst[20],opsecond[20],symfirst[20],symsecond[20],l[20];
    FILE *input,*optab,*symtab,*length,*object;
    input=fopen("input.txt","r");
    length=fopen("length.txt","r");
    object=fopen("object.txt","w+");
    fscanf(input,"%s%s%s%s",add,first,second,third);
    sa=atoi(third);
    if(strcmp(second,"START")==0){
        fscanf(length,"%s",l);
        fprintf(object,"H^%s^%s^%s\n",first,third,l);
    }
    fprintf(object,"T^00%s",third);
    fscanf(input,"%s%s%s%s",add,first,second,third);
    while(strcmp(second,"END")!=0){
        if(strcmp(first,"-")==0){
            optab=fopen("optab.txt","r");
            fscanf(optab,"%s%s",opfirst,opsecond);
            while(strcmp(opfirst,"END")!=0){
                fscanf(optab,"%s%s",opfirst,opsecond);
                if(strcmp(second,opfirst)==0){
                    fprintf(object,"^%s",opsecond);
                    break;
                }
            }
            symtab=fopen("symtab.txt","r");
            fscanf(symtab,"%s%s",symfirst,symsecond);
            while(1){
                if(strcmp(symsecond,third)==0){
                    fprintf(object,"%s",symfirst);
                    break;
                }
                fscanf(symtab,"%s%s",symfirst,symsecond);
            }
        }
        else{
            if(strcmp(second,"BYTE")==0){
                int len= strlen(third);
                fprintf(object,"^");
                for(int i=2; i<len;i++){
                    fprintf(object,"%d",third[i]);
                }
            }
            else if(strcmp(second,"WORD")==0){
                fprintf(object,"^0000%s",third);
            }
        }
        fscanf(input,"%s%s%s%s",add,first,second,third);
    }
    fprintf(object,"\nE^00%d\n",sa);
    fclose(input);
    fclose(optab);
    fclose(symtab);
    fclose(object);
    fclose(length);
}