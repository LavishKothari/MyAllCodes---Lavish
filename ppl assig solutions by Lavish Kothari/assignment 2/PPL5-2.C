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
	printf("%d\t",n);
	print(n-1);
}