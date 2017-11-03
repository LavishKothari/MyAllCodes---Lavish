#include<bits/stdc++.h>
using namespace std;
int fun(vector<int>&v,int curr,int index)
{
	int n=v.size();
	if(index==n-1)
		return index;
	for(int i=index+1;i<n;i++)
		if((curr>v[index] && v[i]<v[i-1]) || (curr<v[index] && v[i]>v[i-1]))
			return i-1;
	return n-1;
}
int sol(vector<int>&v)
{
	int n=v.size();
	int curr=v[0],i=1,answer=0;
	for(;i<n-1;)
	{
		int index=fun(v,curr,i);
		// i to index is a section.
		if(i==index)
		{
			curr=v[i];
			i++;
			continue;
		}
		if(index==n-1)
		{
			answer+=index-i+1;
			return answer; 
		}
		else 
		{
			int a=v[i];
			int b=v[index];
			int c=v[index+1];
			answer+=index-i+1;
		}
	}
	return answer;
}
int main()
{
	int n;
	scanf("%d",&n);
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("%d\n",sol(arr));
	return 0;
}
