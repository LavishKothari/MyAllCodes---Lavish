#include<stdio.h>
#include<conio.h>

int main()
{
	long num,i;
	clrscr();
	printf("ENTER A NUMBER : ");
	scanf("%ld",&num);

	for(i=1;i<=num;i++)
	{
		if(num%i==0)
		{
			printf("%ld\t",i);
		}
	}
	getch();
	return 1;
}

