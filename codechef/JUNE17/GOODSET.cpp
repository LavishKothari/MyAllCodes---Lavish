#include <bits/stdc++.h>
using namespace std;
bool isPossible(set<int>&s,int sum)
{
	for(set<int>::iterator it1 = s.begin();it1!=s.end();it1++)
	{
		set<int>::iterator it2=it1;
		it2++;
		for(;it2!=s.end();it2++)
			if(sum==*it1+*it2)
				return true;
	}
	return false;
}
void sol(int n)
{
	if(n==1)
	{
		printf("1\n");
		return ;
	}
	if(n==2)
	{
		printf("1 2\n");
		return ;
	}
	set<int>s;
	for(int i=1;i<=500;i++)
		s.insert(i);
	set<int>s1;
	set<int>::iterator it=s.begin();it++;it++;
	s1.insert(1);
	s1.insert(2);
	for(int i=2;i<n && it!=s.end();it++)
	{
		if(!isPossible(s1,*it))
		{
			s1.insert(*it);
			i++;
		}
	}
	it=s1.begin();
	for(;it!=s1.end();it++)
		printf("%d ",*it);
	printf("\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		sol(n);
	}
	return 0;
}
