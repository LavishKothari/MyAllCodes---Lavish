//INLINE FUNCION DEFINED OUTSIDE THE CLASS
//BY LAVISH KOTHARI

#include<iostream.h>
#include<conio.h>

class sample
{
	int a;
	public:
	void display(void);
};

inline void sample::display(void)   //inline function
{
	a=30;
	cout<<"inline function"<<endl<<a;
}

int main()
{
	clrscr();
	sample s;
	s.display();
	getch();
	return 1;
}
