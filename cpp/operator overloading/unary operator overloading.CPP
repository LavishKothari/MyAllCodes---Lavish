//UNARY OPERATOR OVERLOADING
//BY LAVISH KOTHARI

#include<iostream.h>
#include<conio.h>

class matrix
{
	int **mat,r,c;
	public:
		void allotmat();
		void getdata();
		void printmat();
		matrix operator-();
};

void matrix::printmat()
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cout<<mat[i][j]<<"\t";
		cout<<endl;
	}
}

void matrix::allotmat()
{
	mat=new int*[r];
	for(int i=0;i<r;i++)
		mat[i]=new int[c];
}

void matrix::getdata()
{
	cout<<"enter the number of rows and columns";
	cin>>r>>c;
	allotmat();
	cout<<"enter the data of matrix";
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>mat[i][j];
}

matrix matrix::operator-()
{
	matrix m;
	m.r=r;
	m.c=c;
	m.allotmat();
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			m.mat[i][j]=-mat[i][j];
	return m;
}

int main()
{
	clrscr();
	matrix m1,m2;
	m1.getdata();
	m2=-m1;
	m2.printmat();
	getch();
	return 1;
}

