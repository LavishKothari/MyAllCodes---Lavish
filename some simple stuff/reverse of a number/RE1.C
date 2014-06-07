#include<stdio.h>
#include<conio.h>

int main()
{
	long num,rev=0;
	clrscr();

	printf("ENTER A NUMBER : ");
	scanf("%ld",&num);

	while(num)
	{
		rev=(rev*10)+num%10;
		num/=10;
	}
	printf("REERSE = %ld",rev);

	getch();
	return 1;
}
