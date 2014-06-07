/*program in c++ illustrating the swapping of two numbers
	using a function using pass by reference by pointer arguments
*/

#include<iostream.h>
#include<conio.h>

void swap(int*,int*);


int main()
{
	int a,b;
	a=15;
	b=20;
	clrscr();

	cout<<"variables before swapping : "<<endl;
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
	swap(&a,&b);

	cout<<"variables after swapping : "<<endl;
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;

	getch();
	return 0;
}

void swap(int *ptra,int *ptrb)
{
	int tmp;
	tmp=*ptra;
	*ptra=*ptrb;
	*ptrb=tmp;
}

