#include<iostream.h>
#include<conio.h>

int add(int&,int&);

int main()
{
	int a,b,sum;
	a=15;
	b=25;
	clrscr();
	cout<<"the  values of variables before calling function : "<<endl;
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;

	sum=add(a,b);

	cout<<"the  values of variables after calling function : "<<endl;
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;

	cout<<"sum = "<<sum<<endl;
	getch();
	return 0;
}

int add(int &ref_a,int &ref_b)
{
	int sum;
	sum=ref_a+ref_b;
	ref_a++;
	ref_b++;
	return sum;
}