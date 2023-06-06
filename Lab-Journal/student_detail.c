
/*
Q. Develop a C program to read and display Name, Roll Number, Date of Birth and Date of Admission details of a student from 
the keyboard where thedate of birth and date of admission consist of further three members such as day,
month and year as a separate structure. Implement using a C structure.
*/

#include<stdio.h>
typedef struct date{
	int day;
	int month;
	int year;
}date;
typedef struct student{
	char name[20];
	int roll;
	date dob;
	date doa;
}student;
int main(){
	int n,i;
	printf("Enter the no of student:- ");
	scanf("%d",&n);
	student p[n];
	for(i=0;i<n;i++){
		printf("\nName of student:- ");
		getchar();
		scanf("%[^\n]s",p[i].name);
		printf("Roll No:- ");
		scanf("%d",&p[i].roll);
		printf("Enter date of birth:- \n");
		printf("\tDate:- ");
		scanf("%d",&p[i].dob.day);
		printf("\tMonths:- ");
		scanf("%d",&p[i].dob.month);
		printf("\tYear:- ");
		scanf("%d",&p[i].dob.year);
		printf("Enter date of Admission:- \n");
		printf("\tDate:- ");
		scanf("%d",&p[i].doa.day);
		printf("\tMonths:- ");
		scanf("%d",&p[i].doa.month);
		printf("\tYear:- ");
		scanf("%d",&p[i].doa.year);
	}
		for(i=0;i<n;i++){
		printf("\nName of student:- %s",p[i].name);
		printf("\nRoll No:- %d",p[i].roll);
		printf("\nEnter date of birth:- %d/%d/%d",p[i].dob.day,p[i].dob.month,p[i].dob.year);
		printf("\nEnter date of Admission:- %d/%d/%d",p[i].doa.day,p[i].doa.month,p[i].doa.year);
		printf("\n");
	}
	return 0;
}
/*
1. INPUT:-
Enter the no of student:- 2

Name of student:- Ms Dhoni
Roll No:- 851
Enter date of birth:-
  Date:- 10
  Months:- 01
  Year:- 2005
Enter date of Admission:-
  Date:- 19
  Months:- 09
  Year:- 2022

Name of student:- rohit sharma
Roll No:- 99
Enter date of birth:-
  Date:- 10
  Months:- 08
  Year:- 2004
Enter date of Admission:-
  Date:- 12
  Months:- 08
  Year:- 2024

OUTPUT:-

Name of student:- Ms Dhoni
Roll No:- 851
Enter date of birth:- 10/1/2005
Enter date of Admission:- 19/9/2022

Name of student:- rohit sharma
Roll No:- 99
Enter date of birth:- 10/8/2004
Enter date of Admission:- 12/8/2024
*/
