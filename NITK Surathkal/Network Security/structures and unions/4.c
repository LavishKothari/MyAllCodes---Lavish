/*
	Accept the name, reg_no, marks in 6 subjects of N students. Find total and average
	of each student. Sort this array of structures
		i. Based on name.
		ii. Based on reg_no.
		iii. Accept a reg_no and search for this student using binary search
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define SUB 6
struct Student
{
	char name[100],reg_number[20];
	double marks[SUB],avg,total;
};
int cmpname(const void*a,const void*b)
{
	struct Student*x=(struct Student*)a;
	struct Student*y=(struct Student*)b;
	return strcmp(x->name,y->name);
}
int cmpreg(const void*a,const void*b)
{
	struct Student*x=(struct Student*)a;
	struct Student*y=(struct Student*)b;
	return strcmp(x->reg_number,y->reg_number);
}
void displayStudents(struct Student*students,int n)
{
	int i,j;
	printf("\n/********************************************************/\n");
	for(i=0;i<n;i++)
	{
		printf("Information of Student %d\n",i+1);
		printf("Name : %s\n",students[i].name);
		printf("Information of Student %d\n",i+1);
		printf("Registration Number : %s\n",students[i].reg_number);
		printf("Marks of %d Subjects : ",SUB);
		for(j=0;j<SUB;j++)
			printf("%g ",students[i].marks[j]);
		printf("\n");
		printf("Average = %g\n",students[i].avg);
		printf("Total = %g\n",students[i].total);
		printf("\n");
	}
	printf("\n/********************************************************/\n");
	
}
void calculateTotal(struct Student*students,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		students[i].total=0;
		for(j=0;j<SUB;j++)
			students[i].total+=students[i].marks[j];
	}
}
void calculateAvg(struct Student*students,int n)
{
	int i,j;
	double t;
	for(i=0;i<n;i++)
	{
		t=0;
		for(j=0;j<SUB;j++)
			t+=students[i].marks[j];
		students[i].avg=t/SUB;
	}
}
int binary_search(struct Student*students,int a,int b,char *r)
{
	int mid,x;
	if(b<a)
		return -1;
	mid=(a+b)/2;
	x=strcmp(r,students[mid].reg_number);
	if(x==0)
		return mid;
	if(x<0)
		binary_search(students,a,mid-1,r);
	else binary_search(students,mid+1,b,r);
}
int main()
{
	char r[20];
	int n,i,j,search_result;
	struct Student*students;
	printf("Enter the number of students : ");
	scanf("%d",&n);
	students=(struct Student*)malloc(sizeof(struct Student)*n);
	for(i=0;i<n;i++)
	{
		printf("Enter the details of student %d : \n",i+1);
		printf("Name : ");
		scanf(" %[^\n]s",students[i].name);
		printf("Registration Number : ");
		scanf(" %s",students[i].reg_number);
		printf("Enter the marks of %d subjects : ",SUB);
		for(j=0;j<SUB;j++)
			scanf("%lf",&students[i].marks[j]);
	}
	calculateTotal(students,n);
	calculateAvg(students,n);
	
	printf("Information Entered : \n");
	displayStudents(students,n);
	
	printf("Now sorting students according to their name:\n");
	qsort(students,n,sizeof(struct Student),cmpname);
	displayStudents(students,n);
	
	printf("Now sorting students according to their registration numbers:\n");
	qsort(students,n,sizeof(struct Student),cmpreg);
	displayStudents(students,n);
	
	printf("Enter the registration number of student which you want to search : \n");
	scanf(" %s",r);
	
	search_result=binary_search(students,0,n-1,r);
	if(search_result==-1)
		printf("No student found with this registration number...\n");
	else printf("the name of this student is : %s\n",students[search_result].name);
	return 0;
}
