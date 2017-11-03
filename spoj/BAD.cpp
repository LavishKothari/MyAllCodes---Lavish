#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<unordered_set<int> >m(n+1),mnew(n+1);
		for(int i=0;i<(n*(n-1))/2;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			m[a].insert(b);
		}
		for(int i=1;i<=n;i++)
		{
			for(unordered_set<int>::iterator it=m[i].begin();it!=m[i].end();it++)
			{
				mnew[i].insert(*it);
				for(unordered_set<int>::iterator it1=m[*it].begin();it1!=m[*it].end();it1++)
				{
					mnew[i].insert(*it1);
				}
			}
		}
		unsigned int player,count=0;
		for(int i=1;i<=n;i++)
		{
			if(mnew[i].size()>count)
			{
				count = mnew[i].size();
				player = i;
			}
		}
		printf("%d %d\n",player,count);
	}
	return 0;
}
