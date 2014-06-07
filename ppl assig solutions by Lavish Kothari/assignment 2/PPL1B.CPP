/*
	program in c++ to illustrate the swapping of two integers
	using a function by implementing call by reference using
	reference variables
*/

#include<iostream.h>
#include<conio.h>

void swap(int &,int &);

int main()
{
	int a,b;
	clrscr();
	a=15;
	b=20;
	cout<<"values of variables before swapping : "<<endl;
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
	swap(a,b);
	cout<<"values of variables after swapping : "<<endl;
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
	getch();
	return 0;
}

void swap(int &refa, int &refb)
{
	int tmp;
	tmp=refa;
	refa=refb;
	refb=tmp;
}
