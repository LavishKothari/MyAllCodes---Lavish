#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll isValidMagicSquare(ll**arr,int n)
{
	ll sum=0;
	for(ll i=0;i<n;i++)
		sum+=arr[0][i];
	
	// for rows;
	for(int i=1;i<n;i++)
	{
		ll s=0;
		for(int j=0;j<n;j++)
			s+=arr[i][j];
		if(s!=sum)
			return -1;
	}
	
	// for columns
	for(int j=0;j<n;j++)
	{
		ll s=0;
		for(int i=0;i<n;i++)
			s+=arr[i][j];
		if(s!=sum)
			return -1;
	}
	
	ll s=0;
	for(int i=0;i<n;i++)
		s+=arr[i][i];
	if(s!=sum)
		return -1;
	s=0;	
	for(int i=0;i<n;i++)
		s+=arr[i][n-i-1];
	if(s!=sum)
		return -1;
	return sum;
}
void fill(ll**arr,int x,int y,ll sum,int n)
{
	ll currentsum=0;
	for(int i=0;i<n;i++)
		currentsum+=arr[x][i];
	arr[x][y]=sum-currentsum;
}
ll getAppSum(ll**arr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		int j;
		for(j=0;j<n;j++)
			if(arr[i][j]==0)
				break;
		if(j==n)
			break;
	}
	ll sum=0;
	for(int j=0;j<n;j++)
		sum+=arr[i][j];
	return sum;
}
int main()
{
	int n;
	cin>>n;
	ll**arr=new ll*[n];
	for(ll i=0;i<n;i++)
		arr[i]=new ll[n];
	int x,y;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]==0)
			{
				x=i;y=j;
			}
		}
	
	if(n==1)
	{
		cout<<"1"<<endl;
		return 0;
	}
	
	ll sum=getAppSum(arr,n);
	fill(arr,x,y,sum,n);
	if(arr[x][y]<=0)
		cout<<"-1"<<endl;
	else
	{
		ll s=isValidMagicSquare(arr,n);
		if(s!=-1)
			cout<<arr[x][y]<<endl;
		else cout<<"-1\n";
	}
	return 0;
}
