//Program to accept 5 people name, address and telephone number and to search for the information of a particular person.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Person
{
	char name[100],address[1000];
	long long int phone_number;
};
void printDetails(struct Person*persons,int n,char*nam)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(nam,persons[i].name)==0)
		{
			printf("Person found : \n");
			printf("Name\t%s\n",persons[i].name);
			printf("Address\t%s\n",persons[i].address);
			printf("Phone Number\t%lld\n",persons[i].phone_number);
			return;
		}
	}
	printf("Person with specified name not found\n");
}
int main()
{
	int n,i;
	char nam[100];
	struct Person*persons;
	printf("Enter the number of persons : ");
	scanf("%d",&n);
	persons=(struct Person*)malloc(sizeof(struct Person)*n);
	for(i=0;i<n;i++)
	{
		printf("Enter the details for person %d\n",i+1);
		printf("Name : ");
		scanf(" %[^\n]s",persons[i].name);
		printf("Address : ");
		scanf(" %[^\n]s",persons[i].address);
		printf("Phone Number : ");
		scanf(" %lld",&persons[i].phone_number);
	}
	
	printf("\nEnter the name of person to be searched : ");
	scanf(" %[^\n]s",nam);
	printDetails(persons,n,nam);
	return 0;
}
