/*
Qn:-Develop a C program to find the no of occurrences of each character in a string.
*/
#include<stdio.h>
#include<string.h>
int main(){
	char s1[200];
	int i=0,j,count;
	printf("Enter the string:- ");
	gets(s1);
	int l=strlen(s1);
	for(i=0;i<l;i++){
		j=0;
		count=1;
		for(j=i+1;j<l;j++){
			if(s1[i]==s1[j]){
				count++;
				s1[j]='\0';
			}
		}
		if(s1[i]!='\0')
			printf("%c =>%d\n",s1[i],count);
	}
	return 0;
}
/*
INPUT:-
Enter the string:- coca cola
OUTPUT:-
c =>3
o =>2
a =>2
  =>1	//space
l =>1
*/
