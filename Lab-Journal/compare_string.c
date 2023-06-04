/*
Qn:- Develop a C program to compare two string using function & return 1 if the strings are equal otherwise
return 0, without using strcmp function.
*/
#include<stdio.h>
#include<string.h>
int compare(char str1[],char str2[]){
	int i=0;
	int l1=strlen(str1);	//find the length of string_1
	int l2=strlen(str2);	//find the length of string_2
	if(l1==l2){
		while(str1[i]!='\0'){
			if(str1[i]!=str2[i])	//if any character of string not match then return 0
				return 0;
			i++;
		}
	}
	else
		return 0;
return 1;
}
int main(){
	char str1[200],str2[200];
	puts("Enter string1:- ");
	gets(str1);
	puts("Enter string2:- ");
	gets(str2);
	int flag=compare(str1,str2);
	if(flag==1)
		printf("The strings are SAME");		
	else 
		printf("The strings are not Same");
	return 0;
}
/*
1. INPUT:-
Enter string1:- hello world
Enter string2:- hello world
OUTPUT:-
The strings are SAME
2. INPUT:-
Enter string1:- tony stark
Enter string2:- tony strak
OUTPUT:-
The strings are not Same
*/
