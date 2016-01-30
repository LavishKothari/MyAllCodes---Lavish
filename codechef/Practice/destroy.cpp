#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
bool cm(pair<int,int>a,pair<int,int>b)
{
	return a.second>b.second;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{	
		int n;
		scanf("%d",&n);
		map<int,int>m;
		for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			if(m.find(temp)==m.end())
				m[temp]=1;
			else 
				m[temp]++;
		}
		map<int,int>mm;	
		int i=0;
		for(map<int,int>::iterator it=m.begin();it!=m.end();it++,i++)
			mm[it->second]=it->first;
		long long int answer=0;
		while(mm.size()>1)
		{
			map<int,int>::iterator it=(mm.end());
			it--;
			int v1=it->first;
			it--;
			int v2=it->first;
			printf("size = %d and value = %d %d\n",mm.size(),v1,v2);
			if(v1==v2)
			{
				map<int,int>::iterator it1=mm.end();it1--;
				mm.erase(it1);
				it1=mm.end();it1--;
				mm.erase(it1);
				answer+=v1;
			}
			/*
			else if(v2>v1)
			{
				map<int,int>::iterator it1=mm.end();it1--;
				mm.erase(it1);
				it1=mm.end();it1--;
				int f=it1->first-v1;
				int s=it1->second;
				mm.erase(it1);
				mm[f]=s;
				answer+=v1;
			}
			*/
			else if(v1>v2)
			{
				map<int,int>::iterator it1=mm.end();it1--;it1--;
				mm.erase(it1);
				it1=mm.end();it1--;
				int f=(it1)->first-v2;
				int s=(it1)->second;
				mm.erase(it1);
				mm[f]=s;
				answer+=v2;
			}
		}
		if(mm.size()==1)
			answer+=(*(mm.begin())).second;
		printf("%lld\n",answer);
	}
	return 0;
}
