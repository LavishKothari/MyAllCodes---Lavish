#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define N 3
int get(vector<int>&v,int i,int j)
{
	return v[i*N+j];
}

bool ismagic(vector<int>&v)
{
	// rows
	for(int i=0;i<N;i++)
	{
		int sum=0;
		for(int j=0;j<N;j++)
		{
			sum+=get(v,i,j);
		}
		if(sum!=(N*(N*N+1))/2)
			return false;
	}

	// cols
	for(int j=0;j<N;j++)
	{
		int sum=0;
		for(int i=0;i<N;i++)
		{
			sum+=get(v,i,j);
		}
		if(sum!=(N*(N*N+1))/2)
			return false;
	}

	// diagonal 1
	int sum=0;
	for(int i=0;i<N;i++)
		sum+=get(v,i,i);
	if(sum!=(N*(N*N+1))/2)
		return false;

	// diagonal 2
	sum=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(i+j==N-1)
				sum+=get(v,i,j);

	if(sum!=(N*(N*N+1))/2)
		return false;

	// all okay
	return true;
}
int findAnswer(vector< vector<int> >magic,vector<int>v)
{
	int min=81;
	int cost=0;
	for(int x=0;x<magic.size();x++)
	{
		int cost=0;
		for(int i=0;i<N*N;i++)
			cost+=abs(magic[x][i]-v[i]);
		if(min>cost)
			min=cost;
	}
	return min;
}
int main()
{
	int arr[N*N];
	for(int i=0;i<N*N;i++)
		arr[i]=i+1;
	vector<int>v(arr,arr+N*N);

	vector< vector<int> >magic;
	while(1)
	{
		if(ismagic(v))
			magic.push_back(v);
		bool x=next_permutation(v.begin(),v.end());
		if(!x)	
			break;
	}
	/*
	   for(int x=0;x<magic.size();x++)
	   {
	   for(int i=0;i<N;i++)
	   {
	   for(int j=0;j<N;j++)
	   cout<<get(magic[x],i,j)<<" ";
	   cout<<endl;
	   }
	   cout<<endl;
	   }
	 */
	for(int i=0;i<N*N;i++)
		cin>>v[i];
	cout<<findAnswer(magic,v)<<endl;
	return 0;
}
