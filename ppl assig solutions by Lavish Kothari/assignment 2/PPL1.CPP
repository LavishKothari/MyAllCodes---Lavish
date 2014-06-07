#include<iostream.h>

int main()
{
	int i=10;	//i is a normal variable
	int &j=i;   //j is a reference variable
	int *k;		//k is a pointer variable
	k=&i;
	//j  is a reference of i
	//k is a pointer to integer that stores the address of i

	cout<<"Address of i = "<<(&i)<<endl;
	cout<<"Address of j = "<<(&j)<<endl;
	cout<<"Address of i (using k) = "<<k<<endl;

	return 0;
}