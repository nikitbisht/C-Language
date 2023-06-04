/*
Qn:- Develop a C program reverse a string using pointers.Display reverse string to the console.
*/
#include<stdio.h>
#include<string.h>
int main(){
	char s1[200],ch,*p1,*p2;
	printf("Enter the string:- ");
	scanf("%[^\n]",s1);
	p1=&s1[0];
	p2=&s1[strlen(s1)-1];
	while(p1<p2){
		ch=*p1;
		*p1=*p2;
		*p2=ch;
	*p1++;
	*p2--;
	}
	printf("Reverse string:- %s",s1);
	return 0;
}
/*
INPUT:-
Enter the string:- Uttarakhand dehradun
OUTPUT:-
Reverse string:- nudarhed dnahkarattU
*/
