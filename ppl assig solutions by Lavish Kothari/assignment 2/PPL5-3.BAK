#include<stdio.h>
#include<conio.h>
long factorial(int);
int main()
{
	int num;
	clrscr();
	printf("Enter the number : ");
	scanf("%d",&num);
	printf("%ld",factorial(num));
	getch();
	return 0;
}

long factorial(int n)
{
	long fact;
	if(n==0)
		return 1;

	fact=factorial(n-1)*n;
	return fact;
}
