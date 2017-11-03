#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<vector<ll> >v;
ll n,m;
bool cmp(const pair<int,pair<int,int> >&a,const pair<int,pair<int,int> >&b)
{
	if(a.first!=b.first)
		return a.first>b.first;
	return a.second.first>b.second.first;
}
void sol1()
{
	ll sum=-n*n,counter=0; 
	vector<pair<int,pair<int,int> > >vpp(n*n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			vpp[counter++]=make_pair((i+1)*(j+1),make_pair(i,j));
			sum+=v[i][j];
			v[i][j]=1;
		}
	sort(vpp.begin(),vpp.end(),cmp);
	for(int i=0;sum;i++)
	{	
		int x=vpp[i].second.first;
		int y=vpp[i].second.second;
		ll inc=m-1;	
		if(inc<=sum)
			v[x][y]=m,sum-=inc;
		else
			v[x][y]=1+sum,sum=0;
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%lld ",v[i][j]);
		printf("\n");
	}
}
int main()
{
	scanf("%lld%lld",&n,&m);
	v=vector<vector<ll> >(n,vector<ll>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%lld",&v[i][j]);

	sol1();
	return 0; 
}
