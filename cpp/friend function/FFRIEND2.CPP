//FRIEND FUNCTION
//A MEMBER OF A CLASS FRIENDLY TO ANOTHER CLASS
//BY LAVISH KOTHARI

#include<iostream.h>
#include<conio.h>

class sample2;  //forward declaration is necessary

class sample1
{
	int a;
	public:
	void add(sample2&);
};

//class def. is required prior to def. of add function

class sample2
{
	int b;
	friend void sample1::add(sample2&);
};

void sample1::add(sample2&s)
{
	a=10;
	s.b=20;
	cout<<a+s.b;
}

int main()
{
	clrscr();
	sample1 s1;
	sample2 s2;
	s1.add(s2);
	getch();
	return 1;
}
