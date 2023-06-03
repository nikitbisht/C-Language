/*
Write a c program to input a string a seprate Vovels,Consonent,Special_Character,Number and Number of Spaces?
INPUT:
Enter the string:-
hey gyes its work 121234 ;';./!@#$%^&*()+=ASDXCV
OUTPUT:
Consonent:- hygystswrkSDXCV
Vovel:- eeioA
Number:- 121234
Spaces:-5
Special:- ;';./!@#$%^&*()+=
Frequency
Consonent:- 15
Vovel:- 5
Number:- 6
Spaces:-5
Special:- 17
*/
#include<stdio.h>
int main(){
	int i,cons=0,num=0,spaces=0,spe=0,vovl=0;
	char s1[200],consonent[20],special[20],number[20],vovel[20];
	printf("Enter the string:- ");
	gets(s1);
	for(i=0;s1[i]!='\0';i++){
		if(s1[i]>='a'&&s1[i]<='z'||s1[i]>='A'&&s1[i]<='Z'){
			if(s1[i]=='a'||s1[i]=='e'||s1[i]=='i'||s1[i]=='o'||s1[i]=='u'||
			s1[i]=='A'||s1[i]=='E'||s1[i]=='I'||s1[i]=='O'||s1[i]=='U'){
				vovel[vovl]=s1[i];
				vovl++;	
			}
			else{
				consonent[cons]=s1[i];
				cons++;
			}
		}
		else if(s1[i]>='0'&&s1[i]<='9'){
			number[num]=s1[i];
			num++;
		}
		else if(s1[i]==' '){
			spaces++;
		}
		else{
			special[spe]=s1[i];
			spe++;
		}
	}
	vovel[vovl]='\0';
	consonent[cons]='\0';
	number[num]='\0';
	special[spe]='\0';
	printf("Consonent:- %s\nVovel:- %s\nNumber:- %s\nSpaces:-%d\nSpecial:- %s",consonent,vovel,number,spaces,special);
	printf("\nFrequency");
	printf("\nConsonent:- %d\nVovel:- %d\nNumber:- %d\nSpaces:-%d\nSpecial:- %d",cons,vovl,num,spaces,spe);
	return 0;
	}
