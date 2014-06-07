//PROGRAM TO ILLUSTRATE CONCEPT OF VIRTUAL CLASS
//SOLUTION OF DIAMOND PROBLEM
//BY LAVISH KOTHARI

#include<iostream.h>
#include<conio.h>

class base
{
	public:
	int a;
	void display()
	{
		cout<<"within base class"<<endl;
	}

};

class derived1:public virtual base
{
	public:
	void display()
	{
		cout<<"within derived 1"<<endl;
	}
};

class derived2:virtual public base
{
	public:
		void display()
		{
			cout<<"within derived 2"<<endl;
		}
};

class child:public derived1,public derived2
{
	public:
		void display()
		{
			cout<<"within child"<<endl;
		}
};

int main()
{
	clrscr();

	child c;
	c.display();

	derived2 d2;
	d2.display();

	derived1 d1;
	d1.display();

	base b;
	b.display();  //as b is an object of base class so
				  //display() of base class will be executed

	getch();
	return 1;
}
