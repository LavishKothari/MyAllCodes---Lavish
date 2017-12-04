#include<bits/stdc++.h>
using namespace std;
bool isInBetween(int x,int l,int u)
{
	//cout<<"upper and lower are = "<<u<<","<<l<<endl;
	return x>=l && x<=u;
}
bool solve(int n,int r,vector<int>&v)
{
	int lower=0,upper=INT_MAX,i=1;
	for(;;)
	{
		if(i<n && v[i]<v[i-1])
		{
			while(i<n && v[i]<v[i-1])
			{
				if(!isInBetween(v[i],lower,upper))
					return false;
				i++;
			}
			lower = v[i-1];
			upper = v[i-2];

		}
		else
		{
			while(i<n && v[i]>v[i-1])
			{
				if(!isInBetween(v[i],lower,upper))
					return false;
				i++;
			}
			upper = v[i-1];
			lower = v[i-2];
		}
		if(i>=n)
			break;
	}
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,r;
		scanf("%d%d",&n,&r);
		vector<int>v(n);
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]);
		if(solve(n,r,v))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
