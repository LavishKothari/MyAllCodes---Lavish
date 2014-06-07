#include<stdio.h>
#include<conio.h>

int main()
{
	long num,i,a;
	clrscr();
	printf("ENTER THE NUMBER : ");
	scanf("%ld",&num);
	a=num;
	for(i=2;i<=a;i++)
	{
		if((num%i)==0)
		{
			printf("%ld\t",i);
			num/=i;
			i=1;
		}
	}
	getch();
	return 1;
}
