//PROGRAM TO ILLUSTRATE THE USE OF DESTRUCTOR FUNCTION
//BY LAVISH KOTHARI

#include<iostream.h>
#include<conio.h>

class sample
{
	int s;
	public:
	~sample();
};

sample::~sample()
{
	cout<<"DESTRUCTOR CALLED";
}

int main()
{
	clrscr();
	sample s;
	getch();
	return 1;
}
