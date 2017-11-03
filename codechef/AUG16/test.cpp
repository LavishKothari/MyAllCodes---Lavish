#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void printVector(vector<ll>&x)
{
	for(int i=0;i<x.size();i++)
		cout<<x[i]<<" ";
	cout<<endl;
}
ll getSum(vector<ll>&s,int start,int end)
{
	if(start<0 || end<0)
		return 0;
	if(start<end)
	{
		if(start-1>=0)
			return s[end-1]-s[start-1];
		return s[end-1];
	}
	else if(start>end)
	{
		ll x=s[s.size()-1]-s[start-1];
		ll y=0;
		if(end-1>=0)
			y=s[end-1];
		return x+y;
	}	
	else 
	{
		if(start==0)
			return s[start];
		return s[start]-s[start-1];
	}
}
int main()
{
	int n;
	cin>>n;
	vector<ll>v(n),cs(n),sc(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		if(i==0)
			cs[i]=v[i];
		else cs[i]=cs[i-1]+v[i];
	}


	int t;
	cin>>t;
	while(t--)
	{

		int start,end;
		cin>>start>>end;
		cout<<getSum(cs,start,end)<<endl;
	}
	return 0;
}
