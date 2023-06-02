/*
Qn:- Write a C program to Add string without using inbuild function strcat()
INPUT:
First string:- Nikit
Another sting:- Bisht
OUTPUT:
Nikit Bisht
*/
#include<stdio.h>
int main(){
	int i=0,j=0;
	char str1[200],str2[200];
	puts("First string:- ");
	gets(str1);
	puts("Another sting:- ");
	gets(str2);
	  while(str1[i]!='\0')
    		i++;
	str1[i]=' ';
	i=i+1;
	    while(str2[j]!='\0'){
	     	str1[i]=str2[j];
		      i++;
	      	j++;
	    }
	str1[i]='\0';
	printf("Concatenate String:- %s",str1);
	return 0;
}
