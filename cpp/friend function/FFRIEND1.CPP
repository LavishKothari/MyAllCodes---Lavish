//FRIEND FUNCTION
//AN EXTERNAL FUNCTION FRIENDLY TO MORE THAN ONE CLASS
//BY LAVISH KOTHARI

#include<iostream.h>
#include<conio.h>

class sample2;    //forward declaration of sample2 is compulsory
class sample1
{
	int a;
	friend void add(sample1&,sample2&);
};

class sample2
{
	int b;
	friend void add(sample1&,sample2&);
};

void add(sample1&s1,sample2&s2)
{
	s1.a=10;
	s2.b=20;
	cout<<(s1.a)+(s2.b);
}


int main()
{
	clrscr();
	sample1 s1;
	sample2 s2;
	add(s1,s2);
	getch();
	return 1;
}
