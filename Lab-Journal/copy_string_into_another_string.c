/*
Qn:- Develop a C program to copy a string to another without using the inbuilt strcpy function.
*/
#include<stdio.h>
int main(){
	char s1[200],s2[200];
	int i=0;
	printf("Enter the string:-\n");
	scanf("%[^\n]s",s1);
	while(s1[i]!='\0'){
		s2[i]=s1[i];
		i++;
	}
	s2[i]='\0';
	printf("Original String:- %s",s1);
	printf("\nCopied String:- %s",s2);
	return 0;	
} 
/*
INPUT:
Enter the string:- graphic era hill university
OUTPUT:
Original String:- graphic era hill university
Copied String:- graphic era hill university
*/
