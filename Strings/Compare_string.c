/*
Qn:- Write a C program to compare two string without using strcmp() function
*/
#include<stdio.h>
#include<string.h>
int main(){
	char str1[200],str2[200];
	puts("Enter your Password");
	gets(str1);
	puts("Confirm Password");
	gets(str2);
	int i=0,flag=0;
	int l1=strlen(str1);
	int l2=strlen(str2);
	if(l1==l2){
		while(str1[i]!='\0'){
		if(str1[i]!=str2[i]){
			flag=1;
			break;
		}
		i++;
		}
		if(flag==0){
		printf("Right Password\n");
		}
		else 
		printf("Wrong Password");
	}
	else
	printf("Password size is not same");
	return 0;
}
/*
INPUT:
Enter your Password
hellow world
Confirm Password
hellow world
OUTPUT:
Right Password
*/
