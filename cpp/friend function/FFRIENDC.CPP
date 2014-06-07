//A CLASS FRIENDLY TO ANOTHER CLASS
//BY LAVISH KOTHARI

#include<iostream.h>
#include<conio.h>

class sample2;

class sample1
{
	int a;
	friend sample2;
};

class sample2
{
	int b;
	public:
	void add(sample1&);
};

void sample2::add(sample1&s1)
{
	s1.a=20;
	b=30;
	cout<<s1.a+b;
}

int main()
{
	clrscr();
	sample1 s1;
	sample2 s2;
	s2.add(s1);
	getch();
	return 1;
}
