/*
	Store the item number, item name, unit price and quantity in stock of N items in a super
	market. Display the following list of items present in the stock.
		i. List of items with unit price greater than Rs.129/-
		ii. List of items with quantity in stock less than 5
*/

#include<stdio.h>
#include<stdlib.h>

struct Item
{
	int number,quantity;
	char name[100];
	double price;
};
void display1(struct Item*items,int n)
{
	printf("List of items with unit price greater than Rs.129/-\n");
	int i;
	for(i=0;i<n;i++)
		if(items[i].price>129.0)
			printf("%s\n",items[i].name);
	printf("\n");
}

void display2(struct Item*items,int n)
{
	printf("List of items with quantity in stock less than 5\n");
	int i;
	for(i=0;i<n;i++)
		if(items[i].quantity<5)
			printf("%s\n",items[i].name);
	printf("\n");	
}
int main()
{
	struct Item*items;
	int n,i;
	scanf("%d",&n);
	items=(struct Item*)malloc(sizeof(struct Item)*n);
	for(i=0;i<n;i++)
	{
		items[i].number=i+1;
		printf("Enter the details of Item %d : \n",i+1);
		printf("Name : ");
		scanf(" %[^\n]s",items[i].name);
		printf("Price : ");
		scanf(" %lf",&items[i].price);
		printf("Quantity : ");
		scanf(" %d",&items[i].quantity);
	}
	display1(items,n);
	display2(items,n);
	
	return 0;
}
