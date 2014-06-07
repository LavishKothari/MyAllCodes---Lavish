#include<stdio.h>
#include<conio.h>

int main()
{
	int i=8,j=9;
	clrscr();
	printf("%d\n%d\n",(i>j),(j>i));
	printf("%d",sizeof(i+j));
	getch();
	return 1;
}
