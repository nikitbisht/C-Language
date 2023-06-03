/*
Qn:- Write a c program to check wheater a String is Anagram or not?
Anagram:- Every element of 1 string present in 2 string
*/
#include<stdio.h>
#include<string.h>
int main(){
	char s1[50],ch,s2[50];
	int i=0,j,flag=0;
	printf("Enter the String:- ");
	gets(s1);
	printf("Enter Another String- ");
	gets(s2);
	int l1=strlen(s1);
	int l2=strlen(s2);
	if(l1==l2){
		for(i=0;i<l1-1;i++){
			for(j=i+1;j<l1;j++){
			if(s1[i]>s1[j]){		//Arenge string 1 in increasing order
				ch=s1[i];
				s1[i]=s1[j];
				s1[j]=ch;
			}
			if(s2[i]>s2[j]){		//Arenge string 2 in increasing order
				ch=s2[i];
				s2[i]=s2[j];
				s2[j]=ch;
				}
			}
		}
	}
	else{
	  printf("Not Anagram");
	return 0;
	}
	puts(s1);
	puts(s2);
	//Now its eassy to compare both string	
	if(strcmp(s1,s2)==0)
		printf("Anagram");
	else
		printf("Not Anagram");	
	return 0;
}
/*
INPUT:
Enter the String:- slight
Enter Another String- lights
OUTPUT:
Both string in increasing order(abcde..)
ghilst
ghilst
Anagram
*/
