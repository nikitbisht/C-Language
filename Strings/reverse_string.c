/*
Qn:- Wrinte a C program to reverse a string without using inbuild function ?
Input:- 
Enter the String:- Nikit Singh Bisht
Output:-
Reverse String:- thsiB hgniS tikiN
*/

#include<stdio.h>
int main(){
	char s1[200],s2;
	int i=0;
	puts("Enter the String:- ");
	gets(s1);						// Also used scanf("%[^\n]s",s1);
	//Reach the s[i] to the end character of string
	while(s1[i]!='\0')
		i++;
	i=i-1;
	//here i is lenth of string
	int j=0;
	for(j=0;j<=i;j++){
		s2=s1[j];
		s1[j]=s1[i];
		s1[i]=s2;
		i--;
	}
	printf("Reverse String:- \n");
	puts(s1);
	return 0;
}
