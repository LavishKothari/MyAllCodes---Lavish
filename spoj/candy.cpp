#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	while(1)
	{
		int n;
		cin>>n;
		if(n==-1)
			break;
		int *arr;
		arr=new int[n];
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}
		if(sum%n==0)
		{
			int diff=0;
			for(int i=0;i<n;i++)
			{
				diff+=abs(sum/n-arr[i]);
			}
			cout<<diff/2<<endl;
		}
		else
			cout<<"-1"<<endl;
		delete(arr);
	}
	return 0;
}
