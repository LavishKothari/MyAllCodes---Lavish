//CREATING AN INLINE FUNCTION INSIDE A CLASS
//BY LAVISH KOTHARI

#include<iostream.h>
#include<conio.h>

class sample
{
	int a;
	public:
		int square()
		{
			return a*a;
		}
		void getdata()
		{
			cout<<"enter value of a"<<endl;
			cin>>a;
		}
};

int main()
{
	clrscr();
	sample s;
	s.getdata();
	cout<<s.square();
	getch();
	return 1;
}

