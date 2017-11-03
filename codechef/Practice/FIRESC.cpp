#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007
#define MAX 100001
typedef long long int ll;

int p[MAX];
int r[MAX];
int find(int n)
{
	if(p[n]==n)
		return n;
	return p[n]=find(p[n]);
}
void merge(int x,int y)
{
	int px=find(x);
	int py=find(y);
	if(px==py)
		return;
	if(r[px]>r[py])
	{
		p[py]=px;
		r[px]+=r[py];
	}
	else
	{
		p[px]=py;
		r[py]+=r[px];
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			p[i]=i;
			r[i]=1;
		}
		for(int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			merge(x,y);
		}
		ll pro=1;
		int count=0;
		for(int i=1;i<=n;i++)
		{
			if(p[i]==i)
			{
				count++;
				pro=(pro*r[i])%MOD;
			}
		}
		printf("%d %lld\n",count,pro);
	}
	return 0;
}
