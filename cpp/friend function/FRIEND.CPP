//FRIEND FUNCTION
//AN OUTSIDE FUNCTION FRIENDLY TO A CLASS

#include<iostream.h>
#include<conio.h>

class sample
{
	int p;
	public:
		void display()
		{
			cout<<"in the display of class sample";
		}
		void friend another(sample&);
};

void another(sample&obj)
{
	obj.p=20;	//accessing private data member of class
	obj.p++;
	cout<<obj.p*10<<endl<<"in friend function";
}


int main()
{
	clrscr();
	sample obj;
	another(obj);
	getch();
	return 1;
}

