//OPERATOR OVERLOADING
//OVERLOADING BINARY OPERATOR
//BY LAVISH KOTHARI

#include<iostream.h>
#include<conio.h>

class matrix
{
	int **mat,r,c;
	public:
		void getdata();
		void printmat();
		void allotmat();
		matrix operator+(matrix&);
};

void matrix::allotmat()
{
	mat=new int* [r];
	for(int i=0;i<r;i++)
		mat[i]=new int [c];
}


void matrix::getdata()
{
	cout<<"enter the rows and columns of matrix";
	cin>>r>>c;
	allotmat();
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>mat[i][j];
}

void matrix::printmat()
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cout<<mat[i][j]<<"\t" ;
		cout<<endl;
	}
}

matrix matrix::operator+(matrix& m1)
{
	matrix m2;
	if(r==m1.r&&c==m1.c)
	{
		m2.r=r;
		m2.c=c;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				m2.mat[i][j]=mat[i][j]+m1.mat[i][j];
		return m2;
	}
	else
	{
		cout<<"matrix addition not possible";
		m2.c=m2.r=0;
		mat=NULL;
		return m2;
	}

}

int main()
{
	clrscr();
	matrix m1,m2,m3;
	m1.getdata();
	m2.getdata();
	m3=m1+m2;
	m3.printmat();
	getch();
	return 1;
}
