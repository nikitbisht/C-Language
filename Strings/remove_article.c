/*
Qn:- Write a C program to remove a article(a,an,the) from a string,without using strstr inbuild function,
and display the updated string to the console?
INPUT:
Enter the string
An apple a day keeps the doctor away
OUTPUT:
apple day keeps doctor away
*/
#include<stdio.h>
#include<string.h>
int main(){
	char str[200],str1[200];
	puts("Enter the string");
	gets(str);
	int i=0,j=0;
	int l=strlen(str);
	while(i<=l){
		if((str[i]=='A'||str[i]=='a')&&str[i+1]=='n'&&(str[i+2]==' '||str[i+2]=='\0')){
			i=i+3;
			continue;		
		}
		else if((str[i]=='A'||str[i]=='a')&&(str[i+1]==' '||str[i+1]=='\0')){
			i=i+2;
			continue;
		}
		else if((str[i]=='T'||str[i]=='t')&&str[i+1]=='h'&&str[i+2]=='e'&&(str[i+3]==' '||str[i+3]=='\0')){
			i=i+4;
			continue;
		}
		else{
			str1[j]=str[i];
			i++;
			j++;
		}
	}
	str1[j]='\0';
	puts(str1);
	return 0;
}
