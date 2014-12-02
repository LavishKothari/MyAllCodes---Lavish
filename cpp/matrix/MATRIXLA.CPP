#include<iostream>
using namespace std;
class matrix
{
	int r,c;
	int **mat;
	void allotmat();
	void getrc();
	void getdata();

	public:
		void createmat();
		void createmat(int);
		void createmat(int,int);
		void createmat(int,int,int);
		void addmat(matrix&,matrix&);
		void printmat();
		matrix addmatrix(matrix&);
};

void matrix::allotmat()
{
	mat=new int* [r];
	for(int i=0;i<r;i++)
		mat[i]=new int [c];
}

void matrix::getrc()
{
	cout<<"enter the rows of matrix";
	cin>>r;
	cout<<"enter the colums of matrix";
	cin>>c;
}

void matrix::createmat()
{
	getrc();
	allotmat();
	getdata();
}


void matrix::getdata()
{
	cout<<"enter the data of matrix";
	for(int i=0;i<r;i++)
	for(int j=0;j<c;j++)
	cin>>mat[i][j];
}

void matrix::createmat(int tmp)
{
	getrc();
	allotmat();
	for(int i=0;i<r;i++)
	for(int j=0;j<c;j++)
	mat[i][j]=tmp;
}

void matrix::createmat(int a,int b)
{
	r=a;
	c=b;
	allotmat();
	getdata();
}

void matrix::createmat(int a,int b,int tmp)
{
	r=a;
	c=b;
	allotmat();
	for(int i=0;i<r;i++)
	for(int j=0;j<c;j++)
	mat[i][j]=tmp;
}

void matrix::addmat(matrix&m1,matrix&m2)
{
	if(m1.r==m2.r&&m2.c==m1.c)
	{
		r=m1.r;
		c=m2.c;
		allotmat();
		for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		mat[i][j]=m1.mat[i][j]+m2.mat[i][j];
	}
	else
	{
		cout<<"matrix addition not possible";
		mat=NULL;
		r=0;c=0;
	}
}


void matrix::printmat()
{
	cout<<"your resultant matrix is as follows:"<<endl;
	for(int i=0;i<r;i++)
	{
	for(int j=0;j<c;j++)
	cout<<mat[i][j]<<"\t";
	cout<<endl;
	}
}

matrix matrix::addmatrix(matrix&m)
{
	matrix m1;
	if(r==m.r&&c==m.c)
	{
		m1.r=r;
		m1.c=c;
		m1.allotmat();
		for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		m1.mat[i][j]=mat[i][j]+m.mat[i][j];
		return m1;
	}
	else
	{
		m1.r=0;
		m1.c=0;
		m1.mat=NULL;
		cout<<"matrix addition not possible";
		return m1;
	}
}


int main()
{
	matrix m1,m2,m3;
	m1.createmat();
	m2.createmat();
	//m3.addmat(m1,m2);
	m3=m2.addmatrix(m1);
	cout<<endl;
	m3.printmat();
	return 1;
}
