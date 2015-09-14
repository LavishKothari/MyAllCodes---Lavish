#include<iostream>
#include<stdlib.h>
using namespace std;
int c(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int*x,*y;
		x=new int[n];
		y=new int[n];
		for(int i=0;i<n;i++)
			cin>>x[i];
		for(int i=0;i<n;i++)
			cin>>y[i];
		qsort(x,n,sizeof(int),c);
		qsort(y,n,sizeof(int),c);
		long long int sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=x[i]*y[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
