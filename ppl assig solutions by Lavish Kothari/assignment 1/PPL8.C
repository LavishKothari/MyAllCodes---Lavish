#include<stdio.h>
#include<conio.h>

struct s1
{
	int i1;
	char c1;
	int i2;
	char c2;
};

struct s2
{
	int i1;
	int i2;
	char c1;
	char c2;
};

int main()
{
	struct s1 var1;
	struct s2 var2;

	clrscr();
	printf("\nSize of var1 = %d",sizeof(var1));
	printf("\nSize of var2 = %d",sizeof(var2));

	printf("\n\nAddress of var1.i1 = %u",&var1.i1);
	printf("\nAddress of var1.c1 = %u",&var1.c1);
	printf("\nAddress of var1.i2 = %u",&var1.i2);
	printf("\nAddress of var1.c2 = %u",&var1.c2);


	printf("\n\nAddress of var1.i1 = %u",&var2.i1);
	printf("\nAddress of var1.i2 = %u",&var2.i2);
	printf("\nAddress of var1.c1 = %u",&var2.c1);
	printf("\nAddress of var1.c2 = %u",&var2.c2);

	getch();
	return  0;
}

