#include<stdio.h>
#include<conio.h>

union u
{
	char c;
	int i;
	float f;
	double d;
};

int main()
{
	union u a;

	clrscr();

	printf("%d",sizeof(a));

	printf("\nAddress of a.c = %u",&a.c);
	printf("\nAddress of a.i = %u",&a.i);
	printf("\nAddress of a.f = %u",&a.f);
	printf("\nAddress of a.d = %u",&a.d);
	getch();
	return 0;
}

