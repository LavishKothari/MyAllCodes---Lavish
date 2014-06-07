#include<stdio.h>
#include<conio.h>

int main()
{
	int*p,*q;

	p--;

	p++;

	p=p-q;

	//p=p+q;	NOT ALLOWED
	//p=p*q;	NOT ALLOWED
	//p=p/q;	NOT ALLOWED	
	//p=p%q;	NOT ALLOWED
	//p=p<<q;	NOT ALLOWED
	//p=p>>p;	NOT ALLOWED

	getch();
	return 0;
}
