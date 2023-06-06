/*
Q. Write a C program to create a file and copy its content to another file such that there is no space 
between any of the words in the copied file. Display the content of the newly copied file to the output screen.
*/
#include<stdio.h>
int main(){
  char s1[100],ch;
	FILE*fp=fopen("copy_without_space","w+");
	printf("Enter something:- ");
  gets(s1);
	fputs(s1,fp);
	rewind(fp);
	FILE *fp1=fopen("without_space.txt","w+");
	while((ch=fgetc(fp))!=EOF){
		if(ch==' ')
			continue;
		else
			putc(ch,fp1);
	}
	rewind(fp1);
while((fgets(s1,50,fp1))!=NULL){			
		printf("%s",s1);
	}
	fclose(fp1);
	fclose(fp);
return 0;
}

/*
1.INPUT:-
Enter something:- Graphic era hill university

OUTPUT:- 
Graphicerahilluniversity
*/
