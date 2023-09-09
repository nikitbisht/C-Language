/*
	Admin side username:- admin
	Admin side password:- pass
*/
//	student side 1st you need to sign up then you login for next time
/*
	if you run this code please run this on dev-c++
	in obnatu it doesn't run and gives many issue on runtime
*/
// PLACEMENT MANAGEMENT SYSTEM
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main();
void sign();
void std();
void profile();
void new_student_placement();
void new_compnies_visited();
void compnies_offer();
void student_applied();
void student_detail();
void about_campus();
void admin();
typedef struct student{
	char name[20];
	long long int num;
	long long int university_roll;
	int student_id;
	char email[30];
	char pass[30];
}student;
typedef struct applied{
	student y;
	char course[20];
	char branch[20];
	char batch[20];
	float cgpa;
	char resume[5000];
}applied;
typedef struct vacancies{
	char name[20];
	applied a;
}vacancies;
typedef struct compnies{
	char name[20];
	char course[20];
	char branch[20];
	float cgpa;
}compnies;
typedef struct visited{
	char name[20];
	int std;
}visited;
typedef struct placement{
	char cmp_name[30];
	char name[20];
	char course[20];
	char branch[20];
	float salary;
	char batch[20];
}placement;
void student_placement(){
	placement s;
	int flag;
	FILE*fp=fopen("placement.txt","rb");
	while(fread(&s,sizeof(placement),1,fp)){
		flag=1;
		printf("\nCompany Name:- %s",s.cmp_name);
		printf("\nName:- %s",s.name);
		printf("\nCourse:- %s",s.course);
		printf("\nBranch:- %s",s.branch);
		printf("\nSalary:- %.2f",s.salary);
		printf("\nBatch:- %s",s.batch);
		printf("\n**********************************");
	}
	if(flag!=1)
		printf("\nSorry! Data doesn't Updated");
	fclose(fp);
	std();
	exit(0);
}
void compnies_visited(){
	visited c;
	FILE*fp=fopen("visited.txt","rb");
	if(fp==NULL)
		printf("\nData Not Updated");
	while(fread(&c,sizeof(visited),1,fp)){
		printf("\n Name of Companies:- %s",c.name);
		printf("\n Student placed:- %d",c.std);
		printf("\n***************************");
	}
	fclose(fp);
	std();
return;
}
void offer(){
	char s1[20];
	char s2[30];
	int n,f,flag=2;
	student a;
	compnies x;		//COMAPNIES CRIEATE AREA
	applied s;		//DETAIL WITH RESUME
	vacancies c;	//DATAIL WITH COMPANy NAME
	FILE*fp=fopen("compnies.txt","rb");
	if(fp==NULL){
		printf("No Companies available");
		std();
	}
	up:
		while(fread(&x,sizeof(compnies),1,fp)){
			printf("\nName:- %s",x.name);
			printf("\nCourse:- %s",x.course);
			printf("\nBranch:- %s",x.branch);
			printf("\nC.G.P.A:- %.2f",x.cgpa);
			printf("\n***************************");
		}
	printf("\nEnter Company Name:- ");
	getchar();
	scanf("%[^\n]s",s1);
	rewind(fp);
	while(fread(&x,sizeof(compnies),1,fp)){
		if(strcmp(s1,x.name)==0){
			f=1;
			break;
		}
	}
	if(f==0){
		rewind(fp);
		printf("Please write correct company name");
		goto up;	
	}
	printf("Enter your student id:- ");
	scanf("%d",&n);
	printf("Password:- ");
	getchar();
	scanf("%[^\n]s",s2);
	FILE*f1=fopen("student.txt","rb+");
	if(f1==NULL){
		printf("Error in opening file");
		std();
	}
	while(fread(&a,sizeof(student),1,f1)){
		if(n==a.student_id){
			flag=0;
			if(strcmp(s2,a.pass)==0){
				flag=1;
				break;
			}	
		}
	}
	fclose(f1);
	FILE*fp2=fopen("offer.txt","rb+");		//DATIL WITH RESUME
	if(fp2==NULL){
		printf("\nComplete profile");
		profile();
	}
	while(fread(&s,sizeof(applied),1,fp2)){
		f=0;
		if(n==s.y.student_id){
		     f=0;
		     if(strcmp(s2,s.y.pass)==0){
			f=1;
			break;
			}
		}
	}
	fclose(fp2);
	if(f==1){
			f=5;
			FILE*f=fopen("applied.txt","rb+");
			if(fp==NULL){
				printf("\nError in opening file:");
				exit(0);
			}
			while(fread(&c,sizeof(vacancies),1,f)){
				if(n==c.a.y.student_id){
					if(strcmp(s2,c.name)==0){
						fclose(f);
						printf("\nYou already Applied for this company");
						std();
						exit(0);
					}
				}
			}
		fclose(f);
	}
	if(flag==1&&f==5){
		if((strcmp(x.course,s.course)==0)&&(strcmp(x.branch,s.branch)==0)&&s.cgpa>=x.cgpa){
		FILE*fp1=fopen("applied.txt","ab");
		strcpy(c.name,s1);
		strcpy(c.a.y.name,s.y.name);
		c.a.y.num=s.y.num;
		c.a.y.university_roll=s.y.university_roll;
		c.a.y.student_id=s.y.student_id;
		strcpy(c.a.y.email,s.y.email);
		strcpy(c.a.course,s.course);
		strcpy(c.a.branch,s.branch);
		strcpy(c.a.batch,s.batch);
		c.a.cgpa=s.cgpa;
		strcpy(c.a.resume,s.resume);
		fwrite(&c,sizeof(vacancies),1,fp1);
		printf("\nYOUR PROFILE DATA IS AUTOMATICALLY SUBMITTED\n");
		printf("\nSuccessfully Applied");
		fclose(fp1);
		}
		else{
			printf("\nSorry! criteria does not match");
			printf("\nTry for another companies");
			fclose(fp);
			std();
		}
	}
	else if(flag==0||flag==2)
		printf("\n Wrong Username & Password");
	else if(f==0)
		printf("Please complete your profile");
	fclose(fp);
	std();
}
void profile(){
	char s1[30];
	int n,flag=2,id;
	applied x,p;		//with bio
	student a;			// data
	u:
	printf("\n\n\t******************************************************************************************\n");
	printf("\t*               [Note]: IF YOU FIRST TIME LOGIN THEN COMPLETE YOUR PROFILE               *\n");
	printf("\t******************************************************************************************\n");
	printf("\n\n|1| Show Profile\t|2| complete Profile\t|3| Main Meanu\t|0| Exit\n");
	scanf("%d",&n);
	if(n==1){
		flag=2;
		printf("Enter your student id:- ");
		scanf("%d",&id);
		printf("PassWord:- ");
		getchar();
		scanf("%[^\n]s",s1);
		FILE*fp1=fopen("student.txt","rb");
		while(fread(&a,sizeof(student),1,fp1)){
			if(id==a.student_id){
				flag=0;
				if(strcmp(s1,a.pass)==0){
					flag=1;
					break;
				}
			}
		}
	fclose(fp1);
	if(flag==1){
		FILE*fp=fopen("offer.txt","rb");
			if(fp==NULL){
				printf("\nPlease first complete your Profile:\n");
				goto u;
			}
			while(fread(&p,sizeof(applied),1,fp)){
				if(id==p.y.student_id&&strcmp(s1,p.y.pass)==0){
					flag=1;
					printf("\nName:- %s",p.y.name);
					printf("\nContact Number:- %lld",p.y.num);
					printf("\nUniversity roll_number:- %lld",p.y.university_roll);
					printf("\nStudent id:- %d",p.y.student_id);
					printf("\nContact email:- %s",p.y.email);
					printf("\nCourse:- %s",p.course);
					printf("\nBranch:- %s",p.branch);
					printf("\nBatch:- %s",p.batch);
					printf("\nCgpa:- %.2f",p.cgpa);
					printf("\nBio:- \n%s",p.resume);
					printf("\n\n");
					break;
				}
				else
					flag=3;
			}
			fclose(fp);
			}
			else if(flag==2||flag==0)
				printf("\nWrong UserName and Password");
			if(flag==3)
				printf("\nFirst Please Completer Your Profile");
			goto u;
		}
	else if(n==2){
		flag=2;
		printf("Enter your student id:- ");
		scanf("%d",&id);
		printf("PassWord:- ");
		getchar();
		scanf("%[^\n]s",s1);
		FILE*fp1=fopen("student.txt","rb+");
		if(fp1==NULL)
		     goto eo;
		while(fread(&a,sizeof(student),1,fp1)){
			if(id==a.student_id){
				flag=0;
				if(strcmp(s1,a.pass)==0){
					flag=1;
					break;
				}
			}	
		}
		eo:
		fclose(fp1);
		if(flag==1){
			flag=5;
			FILE*fp=fopen("offer.txt","rb+");
			if(fp==NULL)
			     goto end;
			while(fread(&p,sizeof(applied),1,fp)){
				if(id==p.y.student_id){
					if(strcmp(s1,p.y.pass)==0){
						fclose(fp);
						printf("\nYou already Completed your Profile:");
						goto u;
					}
				}
			}
			fclose(fp);
		}
		end:
		if(flag==5){
		  
			FILE*fp=fopen("offer.txt","ab");
			printf("\nEnter your valid detail:");
			printf("\n if you apply for the company your data will automatically submit");
			strcpy(p.y.name,a.name);
			p.y.num=a.num;
			p.y.university_roll=a.university_roll;
			p.y.student_id=a.student_id;
			strcpy(p.y.email,a.email);
			strcpy(p.y.pass,a.pass);
			printf("\nCourse:- ");
			getchar();
			scanf("%[^\n]s",p.course);
			printf("Branch:- ");
			getchar();
			scanf("%[^\n]s",p.branch);
			printf("Batch:- ");
			getchar();
			scanf("%[^\n]s",p.batch);
			printf("Cgpa:- ");
			scanf("%f",&p.cgpa);
			printf("Bio:- ");
			getchar();
			scanf("%[^\n]s",p.resume);
			fwrite(&p,sizeof(applied),1,fp);
			fclose(fp);
		}
		else if(flag==2||flag==0)
			printf("\nWrong UserName and Password");
		goto u;
	}
	else if(n==3)
		std();
	else if(n==0)
		exit(0);
	else{
		printf("Incorrect input");
		goto u;
	}
	std();
}
void campus(){
	int flag=0;
	char s1[5000];
	FILE*fp=fopen("campus.txt","r");
	while(fgets(s1,5000,fp)!=NULL){
		flag=1;
		printf("%s",s1);
	}
	fclose(fp);
	if(flag!=1)
		printf("\nData not uploaded");
std();
}
void std(){
	int n;
	up:
	printf("\n\t\t\t\t\t\t**************");
	printf("\n\t\t\t\t\t\t*STUDENT AREA*");
	printf("\n\t\t\t\t\t\t**************");
	printf("\n|1| Students Placement");
	printf("\n|2| Companies Visited");
	printf("\n|3| Companies offer");
	printf("\n|4| Profile");
	printf("\n|5| About Campus");
	printf("\n|6| Log_out");
	printf("\n|0| Exit\n");
	scanf("%d",&n);
	switch(n){
		case 1:
			student_placement();
			break;
		case 2:
			compnies_visited();
			break;
		case 3:
			offer();
			break;
		case 4:
			profile();
			break;
		case 5:
			campus();
			break;
		case 6:
			main();
			break;
		case 0:
			exit(0);
		default:
			op:
			puts("\tInvalid Choise");
			printf("\t[1] Try again\t[0] Exit\n\t");
			scanf("%d",&n);
			if(n==1) goto up;
			else if(n==0) exit(0);
			else goto op;
			break;	
	}
	exit(0);
}
void login(){
	student x;
	char s2[30];
	int flag=2,n,s;
	FILE*fp1=fopen("student.txt","rb+");
	again:
	printf("UserName/Student_id:- ");
	scanf("%d",&s);
	printf("Password:- ");
	getchar();
	scanf("%[^\n]s",s2);
		while(fread(&x,sizeof(student),1,fp1)){
			if(s==x.student_id){
				flag=0;	
				if(strcmp(x.pass,s2)==0){
				flag=1;
				break;
				}
			}
		}
		if(flag==2||flag==0)
			printf("Wrong UserName and Password\n");
		else if(flag==1)
			std();
		up:
			printf("\n|1| Try again\t|2| Home\t|0| Exit\n");
			scanf("%d",&n);
			if(n==1){
			rewind(fp1);
			goto again;	
			} 
			else if(n==2) main();
			else if(n==0) exit(0);
			else {
				printf("Invalid input"); 
				goto up;
			}
		exit(0);
}
void sign(){
	student x;
	FILE *fp=fopen("student.txt","ab");
	printf("Enter your Name:- ");
	getchar();
	scanf("%[^\n]s",x.name);
	printf("Number:- ");
	scanf("%lld",&x.num);
	printf("University roll number:- ");
	scanf("%lld",&x.university_roll);
	printf("student id:- ");
	scanf("%d",&x.student_id);
	printf("email:- ");
	getchar();
	scanf("%[^\n]s",x.email);
	getchar();
	printf("Password:- ");
	scanf("%[^\n]s",x.pass);
	fwrite(&x,sizeof(student),1,fp);
	fclose(fp);
	std();
	exit(0);
}
//upper section is all about student portal
int main(){
	int n;
	char s1[20],s2[20];
	upper:
	puts("Enter your potel:- ");
	puts("|1| Student");
	puts("|2| Admin");
	puts("|3| Exit");
	scanf("%d",&n);	
	if(n==1){
		up:
	puts("\nStudent portal");
	puts("|1| Login");
	puts("|2| Sign IN");
	puts("|3| Exit");
	scanf("%d",&n);
		if(n==1)
			login();
		else if(n==2)
			sign();
		else if (n==3)
			exit(0);
		else{
			printf("Invalid Input");
			goto up;
		}
	}
	else if(n==2){
		printf("\nUserName:- ");
		getchar();
		scanf("%[^\n]s",s1);
		printf("Password:- ");
		getchar();
		scanf("%[^\n]s",s2);
		if(strcmp(s1,"admin")==0&&strcmp(s2,"pass")==0)
			admin();
		else{
			printf("Wrong Username and Password\n\n");
			goto upper;
		}
	}
	else if (n==3)
		exit(0);
	else{
	printf("\nInvalid Input");
	goto upper;
	}
	return 0;
}
//lower sectio is all about admin portal
void admin(){
	int n;
	up:
	printf("\n\t***Admin portal***");
	printf("\n|1| New Students Placement");
	printf("\n|2| New Companies Visited");
	printf("\n|3| Compnies offers");
	printf("\n|4| Student Applied");
	printf("\n|5| All Student datail");
	printf("\n|6| Campus");
	printf("\n|7| Log_out");
	printf("\n|0| Exit\n");
	scanf("%d",&n);
		switch(n){
		case 1:
			new_student_placement();
			break;
		case 2:
			new_compnies_visited();
			break;
		case 3:
			compnies_offer();
			break;
		case 4:
			student_applied();
			break;
		case 5:
			student_detail();
			break;
		case 6:
			about_campus();
			break;	
		case 7:
			main();
			break;
		case 0:
			exit(0);
		default:
			op:
			puts("\tInvalid Choise");
			printf("\t[1] Try again\t[0] Exit\n\t");
			scanf("%d",&n);
			if(n==1) goto up;
			else if(n==0) exit(0);
			else goto op;
			break;
		}
		return;
}
void new_student_placement(){
	int n;
	placement s;
	FILE*fp=fopen("placement.txt","ab+");
		add:
		getchar();
		printf("Company Name:- ");
		scanf("%[^\n]s",s.cmp_name);
		getchar();
		printf("Name:- ");
		scanf("%[^\n]s",s.name);
		getchar();
		printf("Course:- ");
		scanf("%[^\n]s",s.course);
		getchar();
		printf("Branch:- ");
		scanf("%[^\n]s",s.branch);
		printf("Salary:- ");
		scanf("%f",&s.salary);
		getchar();
		printf("Batch:- ");
		scanf("%[^\n]s",s.batch);
		fwrite(&s,sizeof(placement),1,fp);
		printf("\n");
		printf("Successfully student add");
		again:
		printf("\n|1| Add More Student\t|2| Main Menu\t|3| See Student |0|Exit\n");
		scanf("%d",&n);
		if(n==1)
			goto add;
		else if(n==2){
			fclose(fp);
			admin();
			}
		else if(n==3){
			rewind(fp);
//			fp=fopen("placement.txt","rb");
//			fseek(fp,-sizeof(placement),SEEK_CUR);
			while(fread(&s,sizeof(placement),1,fp)){
				printf("\nCompany Name:- %s",s.cmp_name);
				printf("\nName:- %s",s.name);
				printf("\nCourse:- %s",s.course);
				printf("\nBranch:- %s",s.branch);
				printf("\nSalary:- %0.2f",s.salary);
				printf("\nBatch:- %s",s.batch);
				printf("\n**********************************");
			}
		}
		else if(n==0){
			fclose(fp);
			exit(0);
		}
		else {
			printf("\nwrong input:");
			goto again;
		}
	fclose(fp);
	admin();
	exit(0);	
}
void new_compnies_visited(){
	int n;
	visited c;
	FILE*fp=fopen("visited.txt","ab");
		add:
		printf("Company Name:- ");
		getchar();
		scanf("%[^\n]s",c.name);
		printf("Student placed:- ");
		scanf("%d",&c.std);
	fwrite(&c,sizeof(visited),1,fp);
	printf("\n\t*** Data saved successfully ***");
	again:
	printf("\n|1| Add new company\t|2| Main meanu\t|0| Exit\n");
		scanf("%d",&n);
		if(n==1)
			goto add;
		else if(n==2){
			fclose(fp);
			admin();
		}
		else if(n==3){
			fclose(fp);
			exit(0);
		}
		else{
			printf("\nIncorret input");
			goto again;
		}
	admin();
	exit(0);
}
void compnies_offer(){
	int n;
	char s1[20];		//COMPANIES CRITERIA AREA
	compnies b;
	hw:
	printf("\n|1| Add Company\t|2| Remove Company\t|3| See Company\t|4| Main Menu\t|0| Exit\n");
	scanf("%d",&n);
	if(n==1){
		FILE*fp=fopen("compnies.txt","ab");
		add:
			printf("\nName:- ");
			getchar();
			scanf("%[^\n]s",b.name);
			printf("Course:- ");
			getchar();
			scanf("%[^\n]s",b.course);
			getchar();
			printf("Branch:- ");
			scanf("%[^\n]s",b.branch);
			printf("C.G.P.A:- ");
			scanf("%f",&b.cgpa);
		fwrite(&b,sizeof(compnies),1,fp);
		printf("\n\t*** Add company successfully ***");
		again:
		printf("\n|1| Add new company\t|2| Main meanu\t|3| Back\t|0|Exit\n");
		scanf("%d",&n);
		if(n==1)
			goto add;
		else if(n==2){
			fclose(fp);
			admin();
		}
		else if(n==3){
			fclose(fp);
			goto hw;
		}
		else if(n==4){
			fclose(fp);
			exit(0);
		}
		else{
			printf("\nIncorret input");
			goto again;
		}
	}
	else if(n==2){
		int flag;
		upper:
		flag=2;
		printf("\nEnter Company you want to remove: \n");
		getchar();
		scanf("%[^\n]s",s1);
		FILE*fp1=fopen("temp.txt","wb");
		FILE*fp=fopen("compnies.txt","rb");
		while(fread(&b,sizeof(compnies),1,fp)){
			if(strcmp(b.name,s1)==0){
				flag=1;
				continue;
			}
			else{
				fwrite(&b,sizeof(compnies),1,fp1);
			}
		}
		fclose(fp);
		fclose(fp1);
		if(flag!=1){
			printf("\nCompany not found");
			goto hw;
		}
		printf("\nCompany deleted Successfully");
		remove("compnies.txt");
		rename("temp.txt","compnies.txt");
		up:
		printf("\n|1| Remove Company\t|2| Main menu\t|3|Back\t|0| exit\n");
		scanf("%d",&n);
		if(n==1)
			goto upper;
		else if(n==2)
			admin();
		else if(n==3)
			goto hw;
		else if(n==0)
			exit(0);
		else{
			printf("\ninvalid input");
			goto up;
		}
	}
	else if(n==3){
		int flag=0;
		FILE*fp=fopen("compnies.txt","rb");
		while(fread(&b,sizeof(compnies),1,fp)){
			flag=1;
			printf("\nName:- %s",b.name);
			printf("\nCourse:- %s",b.course);
			printf("\nBranch:- %s",b.branch);
			printf("\nC.G.P.A:- %.2f",b.cgpa);
			printf("\n***************************");
		}
		if(flag==0)
			printf("\nNo company found");
		fclose(fp);
		goto hw;
	}
	else if(n==4)
		admin();
	else if(n==0)
		exit(0);
	else {
		printf("\nInvalid Input");
		goto hw;
	}
//		fclose(fp);
//	admin();
//	exit(0);
}
void student_applied(){
	char s1[20];
	int n,flag=0;
	vacancies c;	//DATAIL WITH COMPANY NAME
	FILE*fp=fopen("applied.txt","rb");
		while(fread(&c,sizeof(vacancies),1,fp)){
			printf("\nCompnie Name:- %s",c.name);
			printf("\nStudent Name:- %s",c.a.y.name);
			printf("\nNumber:- %lld",c.a.y.num);
			printf("\nUniversity roll no:- %lld",c.a.y.university_roll);
			printf("\nStudent Id:- %d",c.a.y.student_id);
			printf("\nE-mail:- %s",c.a.y.email);
			printf("\nCourse:- %s",c.a.course);
			printf("\nBranch:- %s",c.a.branch);
			printf("\nBatch:- %s",c.a.batch);
			printf("\nC.G.P.A:- %0.2f",c.a.cgpa);
			printf("\nBio:- \n%s\n",c.a.resume);
			printf("****************************");
		}
		again:
		rewind(fp);
		printf("\n|1| Search Student\t|2| Main Meanu\t|3| Exit\n");
		scanf("%d",&n);
		if(n==1){
			getchar();
			printf("Enter the name of student you want to search:-");
			scanf("%[^\n]s",s1);
				while(fread(&c,sizeof(vacancies),1,fp)){
					if(strcmp(s1,c.a.y.name)==0){
						flag=1;
						break;
					}
				}
				if(flag==1){
					printf("\nCompnie Name:- %s",c.name);
					printf("\nStudent Name:- %s",c.a.y.name);
					printf("\nNumber:- %lld",c.a.y.num);
					printf("\nUniversity roll no:- %lld",c.a.y.university_roll);
					printf("\nStudent Id:- %d",c.a.y.student_id);
					printf("\nE-mail:- %s",c.a.y.email);
					printf("\nCourse:- %s",c.a.course);
					printf("\nBranch:- %s",c.a.branch);
					printf("\nBatch:- %s",c.a.batch);
					printf("\nC.G.P.A:- %0.2f",c.a.cgpa);
					printf("\nBio:- \n%s\n",c.a.resume);
					printf("****************************");
				}
				else
					printf("Record Not Found");
		}
		else if(n=2){
			fclose(fp);
			admin();
		}
		else if(n==3){
			fclose(fp);
			exit(0);
		}
		else{
			printf("Invalid Input");
			goto again;
		}
		goto again;
		fclose(fp);
	}
void student_detail(){
	applied p;
	student x;
	int n,flag;
	char s1[20];
	up:
	printf("\n|1| Student sign up detail");
	printf("\n|2| Student profile detail");
	printf("\n|3| Main Meanu");
	printf("\n|0| Exit\n");
	scanf("%d",&n);
	FILE*fp,*fp1;
	if(n==1){
		FILE *fp=fopen("student.txt","rb");
			while(fread(&x,sizeof(student),1,fp)){
				printf("\nName:- %s",x.name);
				printf("\nNumber:- %lld",x.num);
				printf("\nUniversity roll number:- %lld",x.university_roll);
				printf("\nstudent id:- %d",x.student_id);
				printf("\nemail:- %s",x.email);
				
				printf("\n");	
			}
			fclose(fp);
			again:
			printf("\n|1| Search Student\t|2| Main Meanu\t|3| Back\t|0| Exit\n");
			scanf("%d",&n);
			if(n==1){
				flag=0;
				fp=fopen("student.txt","rb");
				if(fp==NULL)
					exit(0);
				printf("Enter the student Name:- ");
				getchar();
				scanf("%[^\n]s",s1);
				while(fread(&x,sizeof(student),1,fp)){
					if(strcmp(s1,x.name)==0){
						flag=1;
						break;
					}
				}
				if(flag==1){
					printf("Name:- %s",x.name);
					printf("\nNumber:- %lld",x.num);
					printf("\nUniversity roll number:- %lld",x.university_roll);
					printf("\nstudent id:- %d",x.student_id);
					printf("\nemail:- %s\n",x.email);
				fclose(fp);
				}
				else{
					fclose(fp);
					printf("Search not Found");
				goto again;
				}
			}
			else if(n==2)
				admin();
			else if(n==3)
				goto up;
			else if(n==0)
				exit(0);
			else
				printf("\nWrong input");
		goto again;
		admin();
		}
	else if(n==2){
		flag=0;
		fp1=fopen("offer.txt","rb");
		while(fread(&p,sizeof(applied),1,fp1)){
			printf("\nName:- %s",p.y.name);
			printf("\nContact Number:- %lld",p.y.num);
			printf("\nUniversity roll_number:- %lld",p.y.university_roll);
			printf("\nStudent id:- %lld",p.y.student_id);
			printf("\nContact email:- %s",p.y.email);
			printf("\nCourse:- %s",p.course);
			printf("\nBranch:- %s",p.branch);
			printf("\nBatch:- %s",p.batch);
			printf("\nCgpa:- %f",p.cgpa);
			printf("\nBio:- \n%s",p.resume);
			printf("\n");
		}
		fclose(fp1);
		aga:
		printf("\n|1| Search Student\t|2| Main Meanu\t|3| Back\t|0| Exit\n");
		scanf("%d",&n);
		if(n==1){
			flag=0;
			printf("Enter the Student Name:- ");
			getchar();
			scanf("%[^\n]s",s1);
			fp1=fopen("offer.txt","rb");
			if(fp1==NULL)
				exit(0);
			while(fread(&p,sizeof(applied),1,fp1)){
				if(strcmp(s1,p.y.name)==0){
					flag=1;
					break;
				}
			}
			if(flag==1){
				printf("\nName:- %s",p.y.name);
				printf("\nContact Number:- %lld",p.y.num);
				printf("\nUniversity roll_number:- %lld",p.y.university_roll);
				printf("\nStudent id:- %lld",p.y.university_roll);
				printf("\nContact email:- %s",p.y.email);
				printf("\nCourse:- %s",p.course);
				printf("\nBranch:- %s",p.branch);
				printf("\nBatch:- %s",p.batch);
				printf("\nCgpa:- %f",p.cgpa);
				printf("\nBio:- \n%s",p.resume);
				printf("\n");
				fclose(fp1);	
			}
			else{
				fclose(fp1);
				printf("\nNo Record found");
			}
		goto aga;
	}
	else if(n==2)
		admin();
	else if(n==0)
		exit(0);
	else if(n==3)
		goto up;
	else {
		printf("incorect intput");
		goto aga;
	}
}
	else if(n==3)
		admin();
	else if(n==0)
		exit(0);
	else{
		printf("Invalid Input");
	goto up;
	}
	fclose(fp);
	fclose(fp1);
}
void about_campus(){
	int n;
	char s1[5000];
	up:
	printf("\n|1| Append \t|2| New Write\t|3| Check \t|4| Main Menu\n");
	scanf("%d",&n);
	if(n==1){	
		FILE*fp=fopen("campus.txt","a");
		printf("Write about compus:- \n");
		getchar();
		scanf("%[^\n]s",s1);
		fputs(s1,fp);
		fclose(fp);
	}
	else if(n==2){
		FILE*fp=fopen("campus.txt","w");
		printf("Write about compus:- \n");
		getchar();
		scanf("%[^\n]s",s1);
		fputs(s1,fp);
		fclose(fp);	
	}
	else if(n==3){
			FILE*fp=fopen("campus.txt","r");
	while(fgets(s1,5000,fp)!=NULL){
			printf("%s",s1);
		}
		fclose(fp);
	}
	else if(n==4)
		admin();
	goto up;
}





















































//code by nikit singh bisht
