#include<stdio.h>
#include<conio.h>

void decimal_to_binary(unsigned int);

int main()
{
	int n;

	clrscr();

	printf("ENTER THE NUMBER FOR WHICH YOU WANT THE INTERNAL REPRESENTATION OF BIT PATTERN\n");
	scanf("%d",&n);

	decimal_to_binary((unsigned int)n);
	getch();
	return 0;
}

void decimal_to_binary(unsigned int n)
{
	int *arr;
	int counter;
	int i;
	counter=sizeof(int)*8;
	/*
	now counter represents the number of
	bits that are used to store an integer on
	your compiler
	*/
	arr=(int *)malloc(sizeof(int)*counter);

	for(i=counter-1;i>=0;i--)
	{
		if(n%2==0)
			arr[i]=0;
		else
			arr[i]=1;
		n/=2;
	}

	for(i=0;i<counter;i++)
		printf("%d",arr[i]);

}