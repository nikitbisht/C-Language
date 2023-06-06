/*
Q. Write a C program to create a file “threeparas.txt” and write any three paragraphs of text to it, 
Display the content of the file and the count of frequency of consonants and vowels present in to the console.
*/
#include<stdio.h>
int main(){
	int count=0,cnt=0;
	FILE*fp=fopen("threeparas.txt","w+");
	printf("Enter something:- ");
	char s1[50],ch;
	gets(s1);
	fprintf(fp,"%s",s1);
		gets(s1);
	fprintf(fp,"%s",s1);
		gets(s1);
	fprintf(fp,"%s",s1);
	rewind(fp);
	while((ch=getc(fp))!=EOF){
		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
			count++;
		else if((ch>='a'||ch<='z')&(ch>='A'||ch<='Z'))
			cnt++;
	}
	fclose(fp);
	printf("\nfrequency of vowel:- %d",count);
	printf("\nfrequency of consonent:- %d",cnt);
	return 0;
}

/*
INPUT:-
Enter something:- stay low run fast
kill first die last
one shot one kill

OUTPUT:-
frequency of vowel:- 15
frequency of consonent:- 38
*/
