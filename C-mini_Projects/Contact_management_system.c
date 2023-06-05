/*
Develop a c program to make a contact management projet which include the following operation?
1.Add contact
2.List contact
3.Edit contact
4.Search contact
5.Delete contact
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main();
typedef struct contact{
	char name[20];
	long long int num;
	char email[50];
	char address[100];
}contact;
//NEW CONTACT
void new_contact(){
	int n;
	printf("\tEnter the no of contact you wants to Add:- ");
	scanf("%d",&n);
up:
	FILE *f=fopen("new.txt","ab");
	contact p;
	for(int i=0;i<n;i++){
		printf("\t\tNAME:- ");
		fflush(stdin);
		scanf("%[^\n]",p.name);
		printf("\t\tNUMBER:- ");
		scanf("%lld",&p.num);
		fflush(stdin);
		printf("\t\tE-Mail:- ");
		scanf("%[^\n]s",p.email);
		fflush(stdin);
		printf("\t\tADRESS:- ");
		scanf("%[^\n]s",p.address);
		printf("\n");
		fwrite(&p,sizeof(contact),1,f);
		}
		fclose(f);
op:
	printf("\t[1]Add New Contact\t[2]Main Meanu\t[0]Exit\n\t");
		scanf("%d",&n);
	if(n==1) goto up;
	else if(n==2) main();
	else if(n==0) exit(0);
	else puts("\tInvalid Number Tryagain!"); goto op;
}
// SEE THE LIST OF CONTACT
void list_contact(){
	contact x;
	int m;
	FILE *fp=fopen("new.txt","rb");
	while(fread(&x,sizeof(struct contact),1,fp)){
		printf("\tName:- %s",x.name);
		printf("\n\tNumber:- %lld",x.num);
		printf("\n\tE-Mail:- %s",x.email);
		printf("\n\tAddress:- %s\n",x.address);
		printf("\n");
	}
		fclose(fp);	
	main();
}
//EDIT CONTACT
void edit_contact(){
int n,flag=0;
contact x;
up:
char s1[100],s2[20];
	FILE*fp=fopen("new.txt","ab+");
	FILE*fp1=fopen("edit.txt","wb");
	printf("\tEnter the name:- ");
	getchar();
	scanf("%[^\n]s",s1);
		while(fread(&x,sizeof(struct contact),1,fp)){
			if(strcmp(s1,x.name)==0){
				flag=1;
				printf("\tNew_Name:- ");
				fflush(stdin);
				scanf("%[^\n]",x.name);
				printf("\tNumber:- ");
				scanf("%lld",&x.num);
				fflush(stdin);
				printf("\tE-Mail:- ");
				scanf("%[^\n]s",x.email);
				fflush(stdin);
				printf("\tAdress:- ");
				scanf("%[^\n]s",x.address);
				printf("\n");
				fwrite(&x,sizeof(contact),1,fp1);
			}
			else
				fwrite(&x,sizeof(contact),1,fp1);
		}
		if(flag!=1){
			printf("No record found:");
			main();
		}
		fclose(fp);
		fclose(fp1);
		remove("new.txt");
		rename("edit.txt","new.txt");
op:
		printf("\t[1] Edit Contact\t[2]Main Meanu\t[0]Exit\n\t");
		scanf("%d",&n);
	if(n==1) goto up;
	else if(n==2) main();
	else if(n==0) exit(0);
	else puts("\tInvalid Number Tryagain!"); goto op;

}
//SEARCH CONTACT
void search_contact(){						
long long int m;
contact x;
char s1[100];
up:	
	int n,flag=0;
	FILE *fp=fopen("new.txt","rb");
	puts("\tEnter the method of Searching:- ");
	printf("\n\t[1]By Name\t[2]By Number\t[3]By E-Mail\t[4]By Address\n\t");
	scanf("%d",&n);
	if(n==1){										// Search By Name
		printf("\tEnter the Name:- ");
		fflush(stdin);
		scanf("%[^\n]s",s1);
		while(fread(&x,sizeof(struct contact),1,fp)){
			if(strcmp(s1,x.name)==0){
				flag=1;
				printf("\n\t----------Record found----------\n");
				upr:
				printf("\n\t[1]Contact info\t[2]Another Search\t[3]Main Meanu\t[0]Exit\n\t");
				scanf("%d",&n);
				if(n==1){
					printf("\n\tName:- %s",x.name);
					printf("\n\tNumber:- %lld",x.num);
					printf("\n\tE-Mail:- %s",x.email);
					printf("\n\tAddress:- %s\n",x.address);
				}
				else if(n==2) goto up;
				else if(n==3) main();
				else if(n==0) exit(0);
				else{
				puts("\tInvalid Number Tryagain!"); 
				goto upr;
				}
			}
		}
		if(flag!=1)
			printf("\n\t----------Not found any Record----------\n");
	}
	else if(n==2){								// Search By Number
	printf("\tEnter the Number:- ");
		scanf("%lld",&m);
		while(fread(&x,sizeof(struct contact),1,fp)){
			if(m==x.num){
				flag=1;
				printf("\n\t----------Number found----------\n");
				again:
				printf("\n\t[1]Contact info\t[2]Another Search\t[3]Main Meanu\t[0]Exit\n\t");
				scanf("%d",&n);
				if(n==1){
					printf("\n\tName:- %s",x.name);
					printf("\n\tNumber:- %lld",x.num);
					printf("\n\tE-Mail:- %s",x.email);
					printf("\n\tAddress:- %s\n",x.address);
				}
				else if(n==2) goto up;
				else if(n==3) main();
				else if(n==0) exit(0);
				else{
				puts("\tInvalid Number Tryagain!"); 
				goto again;
				}
			}
		}
		if(flag!=1)
			printf("\n\t----------Not found any Record----------\n");	
	}
	else if(n==3){								//Search By E-Mail	
		printf("\tEnter E-Mail:- ");
		fflush(stdin);
		scanf("%[^\n]s",s1);
		while(fread(&x,sizeof(struct contact),1,fp)){
			if(strcmp(s1,x.email)==0){
				flag=1;
				printf("\n\t----------Record found----------\n");
				dobara:
				printf("\n\t[1]Contact info\t[2]Another Search\t[3]Main Meanu\t[0]Exit\n\t");
				scanf("%d",&n);
				if(n==1){
					printf("\n\tName:- %s",x.name);
					printf("\n\tNumber:- %lld",x.num);
					printf("\n\tE-Mail:- %s",x.email);
					printf("\n\tAddress:- %s\n",x.address);
				}
				else if(n==2) goto up;
				else if(n==3) main();
				else if(n==0) exit(0);
				else{
				puts("\tInvalid Number Tryagain!"); 
				goto dobara;
				}
			}
		}
		if(flag!=1)
			printf("\n\t----------Not found any Record----------\n");	
	}
	else if(n==4){							//Search By Address
		printf("\tEnter the Address:- ");
		fflush(stdin);
		scanf("%[^\n]s",s1);
		while(fread(&x,sizeof(struct contact),1,fp)){
			if(strcmp(s1,x.address)==0){
				flag=1;
				printf("\n\t----------Record found----------\n");
				fir:
				printf("\n\t[1]Contact info\t[2]Another Search\t[3]Main Meanu\t[0]Exit\n\t");
				scanf("%d",&n);
				if(n==1){
					printf("\n\tName:- %s",x.name);
					printf("\n\tNumber:- %lld",x.num);
					printf("\n\tE-Mail:- %s",x.email);
					printf("\n\tAddress:- %s\n",x.address);
				}
				else if(n==2) goto up;
				else if(n==3) main();
				else if(n==0) exit(0);
				else{
				puts("\tInvalid Number Tryagain!"); 
				goto fir;
				}
			}
		}	
		if(flag!=1)
			printf("\n\t----------Not found any Record----------\n");
	}
	else 	printf("\n\tInvalid Input");
op:
	fclose(fp);
	printf("\n\t[1]Again Search\t[2]Main Meanu\t[0]Exit\n\t");
		scanf("%d",&n);
	if(n==1) goto up;
	else if(n==2) main();
	else if(n==0) exit(0);
	else puts("\tInvalid Number Tryagain!"); goto op;
	
}
//DELETE CONTACT
void delete_contact(){
contact x;
int n,flag=0;
char s1[20];
FILE*fp,*fp1;
up:
	printf("\tEnter the name of contact which wanna to delete:- ");
	getchar();
	scanf("%[^\n]s",s1);
	fp=fopen("new.txt","rb");
	fp1=fopen("temp.txt","wb");
	while(fread(&x,sizeof(contact),1,fp)){
		if(strcmp(s1,x.name)==0){
			flag=1;
			continue;
		}
		else
			fwrite(&x,sizeof(contact),1,fp1);
	}
	if(flag==1)
		printf("\n\tcontact deleted successfully");
	else
		printf("\n\tno any record found");
	fclose(fp);
	fclose(fp1);
	remove("new.txt");
	if(rename("temp.txt","new.txt")!=0)
		printf("error in renaming file");
op:
	printf("\n\t[1] Delete Contact\t[2]Main Meanu\t[0]Exit\n\t");
		scanf("%d",&n);
	if(n==1) goto up;
	else if(n==2) main();
	else if(n==0) exit(0);
	else puts("\tInvalid Number Tryagain!"); goto op;
}
//Main function
int main(){
	int n;
	up:
	puts("\t\tMain Meanu:-");
	puts("\t*-*-*-*-*-*-*-*-*-*-*-*-*");
	puts("\t[1] New Contact:");
	puts("\t[2] List All Contact:");
	puts("\t[3] Edit a Contact:");
	puts("\t[4] Search Contact:");
	puts("\t[5] delete a Contact:");
	puts("\t[0] Exit:");
	puts("\t*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	puts("\tEnter the choise:");
	printf("\t");scanf("%d",&n);

	switch(n) {
		case 1:
			new_contact();	
			break;
		case 2:
			list_contact();
			break;
		case 3:
			edit_contact();	
			break;
		case 4:
			search_contact();
			break;
		case 5:
			delete_contact();	
			break;
		case 0:
			exit(0);
			break;
		default:
			op:
			puts("\tInvalid Choise");
			printf("\t[1] Tryagain\t[0] Exit\n\t");
			scanf("%d",&n);
			if(n==1) goto up;
			else if(n==0) return 0;
			else goto op;
			break;
 	}
 return 0;
}
//Code by Nikit singh bisht
