//PROGRAM TO ILLUSTRATE THE CONCEPT OF VIRTUAL FUNCTION
//BY LAVISH KOTHARI

#include<iostream.h>
#include<conio.h>

class base
{
	public:
		void display()
		{
			cout<<"IN THE DISPLAY OF BASE CLASS"<<endl;
		}
		virtual void print()
		{
			cout<<"IN THE PRINT OF BASE CLASS"<<endl;
		}

};

class derived:public base
{
	public:
		void display()
		{
			cout<<"IN THE DISPLAY OF DERIVED CLASS"<<endl;
		}
		void print()
		{
			cout<<"IN THE PRINT OF DERIVED CLASS"<<endl;
		}
};

class child:public derived
{
	public:
		void display()
		{
			cout<<"IN THE DISPLAY OF CHILD CLASS"<<endl;
		}
		void print()
		{
			cout<<"IN THE PRINT OF CHILD CLASS"<<endl;
		}
};

int main()
{
	clrscr();

	derived *p;
	derived d;
	p=&d;
	p->display(); //output->IN THE DISPLAY OF DERIVED CLASS

	base*ptr;
	derived d2;
	ptr=&d2;
	ptr->display();  //output->IN THE DISPLAY OF BASE CLASS

	/*if the function display() is not virtual then
	ptr->display() will execute the display of base
	class because ptr is a pointer to base class
	the contents of pointer does not matter
	rather the type of pointer should be considered*/

	base *pointer;
	base b;
	child c;
	pointer=&b;
	pointer->print(); //IN THE PRINT OF BASE CLASS
	pointer=&d;
	pointer->print(); //IN THE PRINT OF DERIVED CLASS
	pointer=&c;
	pointer->print();//IN THE PRINT OF CHILD CLASS

	/*as the function print is declared virtual in the base
	class so pointer->print() will execute print() depending
	upon the contents of the "pointer"*/

	getch();
	return 1;
}
