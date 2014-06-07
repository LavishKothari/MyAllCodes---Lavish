#include<stdio.h>
#include<conio.h>

int main()
{
	long n=100,a=0,b=0;
	int i;
	
	for(i=1;i<=n;i++)
		a=a+i;
	a=a*a;

	for(i=1;i<=n;i++)
		b=b+(i*i);

	printf("Answer = %ld\n",(a-b));
	system("pause");
}