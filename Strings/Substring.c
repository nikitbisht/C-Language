/*
Qn:- Write a C program to find the substring in the main String without using inbuild function strstr()?
*/
#include<stdio.h>
#include<string.h>
int main(){
	char s1[50],s2[20];
	int i=0,flag,j;
	puts("Enter the main string:- ");
	gets(s1);
	puts("Enter the search string:- ");
	gets(s2);
	int l1=strlen(s1);
	int l2=strlen(s2);
	for(i=0;i<=l1-l2;i++){
		for(j=i;j<l2+i;j++){
			flag=0;
			if(s1[j]!=s2[j-i]){
				flag=1;
				break;
			}
		}
		if(flag==0)
		  break;
	}
	if(flag==0)
		printf("sub sting is present\n");
	else
		printf("Sub sting not\n");
	return 0;
}
/*
INPUT:
Enter the main string:- i completing my first year
Enter the search string:- first
OUTPUT:
sub sting is present
*/
