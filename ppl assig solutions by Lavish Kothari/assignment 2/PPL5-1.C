#include<stdio.h>
#include<conio.h>
void print(int);
int main()
{
	print(20);
	getch();
	return 0;
}

void print(int n)
{
	if(n==0)
		return;
	print(n-1);
	printf("%d\t",n);
}