// Program to input and display book information.

#include<stdio.h>
#include<stdlib.h>
struct Book
{
	char title[100],author[100];
	double price;
};
void display(struct Book * books,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nDetails for book%d : \n",i+1);
		printf("Title\t%s\n",books[i].title);
		printf("Author\t%s\n",books[i].author);
		printf("Price\t%g\n",books[i].price);
	}
}
int main()
{
	struct Book*books;
	int i,n;
	printf("Enter the number of books that you want to Enter : ");
	scanf("%d",&n);
	books=(struct Book*)malloc(sizeof(struct Book)*n);
	for(i=0;i<n;i++)
	{
		printf("Enter the Details of Book %d : \n",i+1);
		printf("Title : ");
		scanf(" %[^\n]s",books[i].title);
		printf("Author : ");
		scanf(" %[^\n]s",books[i].author);
		printf("Price : ");
		scanf(" %lf",&books[i].price);
	}
	display(books,n);
	return 0;
}
