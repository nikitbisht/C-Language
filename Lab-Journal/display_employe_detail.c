/*
Qn. Develop a program in C to read a structure in the main program if an Employee that contain Name,
EmpCode, and Salary as the members. Write a function to display the detail of the employee.
*/
#include<stdio.h>
typedef struct date{
	int day;
	int month;
	int year;
}date;
typedef struct employee{
	char name[50];
	char EmpCode[20];
	date dob;
	float Salary;
}employe;
void employee(int n,employe s[]){
	int i;
	for(i=0;i<n;i++){
		printf("\nName:- %s",s[i].name);
		printf("\nEmpCode:- %s",s[i].EmpCode);
		printf("\nEnter date of birth:- %d/%d/%d",s[i].dob.day,s[i].dob.month,s[i].dob.year);
		printf("\nSalary:- %0.2f",s[i].Salary);
		printf("\n");
	}
	return ;
}
int main(){
	int n,i;
	printf("Enter the no of employee:- ");
	scanf("%d",&n);
	employe s[n];
	for(i=0;i<n;i++){

		printf("\nName:- ");
		getchar();
		scanf("%[^\n]s",s[i].name);
		printf("EmpCode:- ");
		scanf("%s",s[i].EmpCode);
		printf("Date of Birth:\n");
		printf("Date:- ");
		scanf("%d",&s[i].dob.day);
		printf("Month:- ");
		scanf("%d",&s[i].dob.month);
		printf("Year:- ");
		scanf("%d",&s[i].dob.year);
		printf("Salary:- ");
		scanf("%f",&s[i].Salary);
	}
	employee(n,s);
	return 0;
}

/*
INPUT:-
Enter the no of employee:- 1

Name:- nobita
EmpCode:- ceo121
Date of Birth:
Date:- 15
Month:- 01
Year:- 2001
Salary:- 59999.984

OUTPUT:- 
Name:- nobita
EmpCode:- ceo121
Enter date of birth:- 15/1/2001
Salary:- 59999.98
*/
