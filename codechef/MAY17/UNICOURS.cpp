#include<bits/stdc++.h>
using namespace std;
int sol(vector<int>&v)
{
	int n=v.size();
	int answer=0;
	for(int i=1;i<n;i++)
	{
		answer=max(answer,v[i]);
	}
	return n-answer;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int>v(n);
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]);
		printf("%d\n",sol(v));
	}
}
