#include <stdio.h>
#include <string.h>


void main() {
	
	char first[20],second[20],third[20];
	char arg1[20],arg2[20],temp[20],check1[20],check2[20],def1[20],def2[20];
	FILE *input,*namtab,*argtab,*deftab,*output;
	input = fopen("input.txt","r");
	namtab = fopen("namtab.txt","w");
	argtab = fopen("argtab.txt","w");
	deftab = fopen("deftab.txt","w");
	output = fopen("output.txt","w");
	
	
	
	fscanf(input,"%s %s %s",first,second,third);
	
	
	
	while(strcmp(second,"END")!=0) {
		
		
		if(strcmp(second,"MACRO")==0) {
			
			fprintf(namtab,"%s\n",first);
			strcpy(temp,third);
			int i=0;
			while(temp[i]!=',') {
				
				arg1[i]=temp[i];
				i++;
				}
			int j=0;
			arg1[i]='\0';
			i++;
			while(temp[i]) {
				
				arg2[j]=temp[i];
				j++;
				i++;
				}
			arg2[j]='\0';
			fprintf(deftab,"%s\t%s\n",first,third);
			//fscanf(input,"%s %s %s",first,second,third);
			while(strcmp(second,"MEND")!=0) {	
				
				fscanf(input,"%s %s %s",first,second,third);
				if(strcmp(third,arg1)==0)
					
					fprintf(deftab,"%s\t%s\n",second,"?1");
				else if(strcmp(third,arg2)==0)
				
					fprintf(deftab,"%s\t%s\n",second,"?2");
				else
					fprintf(deftab,"%s\t%s\n",second,third);
				}
			//fprintf(argtab,"%s\n","MEND");
					
				
				
			}
		else if(strcmp(second,"START")==0) {
			
			
			fprintf(output,"%s\t%s\t%s\n",first,second,third);
			//printf("%s\n%s\n%s\n",first,second,third);
			fclose(deftab);
			fclose(namtab);
			
			}
		
		else {	
		namtab = fopen("namtab.txt","r");
		temp[0]='\0';
		while(!feof(namtab)) {
			
			
			fscanf(namtab,"%s",temp);
			if(strcmp(temp,second)==0) {
				
				int i=0,j=0;
				while(third[i]!=',') {
					
					check1[i]=third[i];
					i++;
					}
				check1[i]='\0';
				fprintf(argtab,"%s\n",check1);
				i++;
				while(third[i]!='\0') {
					
					check2[j]=third[i];
					//printf("%s\n",check2);
					i++;
					j++;
					}
				check2[j]='\0';
				fprintf(argtab,"%s\n",check2);
				fclose(argtab);
				fprintf(output,"%s\t%s\t%s\n",".",second,third);
				
				
				deftab = fopen("deftab.txt","r");
				
				fscanf(deftab,"%s %s",def1,def2);
				
				
				if(strcmp(def1,temp)==0) {
					
					while(strcmp(def1,"MEND")!=0) {
						
						fscanf(deftab,"%s %s",def1,def2);
						
						if(strcmp(def1,"MEND")==0) 
							break;
						
						fprintf(output,"%s\t%s\t%s\n","-",def1,def2);
						
						}
					}				
				
				
				
				
				break;
				//printf("%s\n",check1);
			}
		
		}
		}
		
		
		
		
		//fprintf(output,"%s\t%s\t%s\n",first,second,third);
		
			
			
		fscanf(input,"%s %s %s",first,second,third);	
			
			
			
			
		
		
		//break;	
		}
	
	fprintf(output,"%s\t%s\t%s\n","N1","RESW","1");
	fprintf(output,"%s\t%s\t%s\n","N2","RESW","1");
	fprintf(output,"%s\t%s\t%s\n","-","END","-");
	
	//printf("%s\n%s\n",arg1,arg2);
	
	
	
	fclose(input);
	fclose(namtab);
	//fclose(argtab);
	fclose(deftab);
	fclose(output);
	
	}
