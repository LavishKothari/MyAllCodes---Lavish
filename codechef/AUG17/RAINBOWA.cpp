#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int>&v)
{
	int n=v.size();
	int current=1;
	for(int i=0,j=n-1;i<=j;i++,j--)
	{
		if(v[i]>7 || v[j]>7)
			return false;
		if(v[i]!=v[j])
			return false;
		if(v[i]==current+1)
			current++;
		else if(v[i]!=current)
			return false;
	}
	if(current!=7)
		return false;
	return true;
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
		if(solve(v))
			printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
