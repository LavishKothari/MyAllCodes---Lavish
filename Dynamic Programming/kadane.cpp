#include<bits/stdc++.h>
using namespace std;
int kadane(int*arr,int n)
{
	int sum=0,max=INT_MIN;
	for(int i=0;i<n;i++)
	{
		sum=sum+arr[i];
		if(max<sum)
			max=sum;
		if(sum<0)
			sum=0; 
	}
	return max;
}
int main()
{
	int *arr,n;
	cin>>n;
	arr=new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<kadane(arr,n)<<endl;
	return 0;
}