#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll solve(vector<ll>&v,int d)
{
	int n=v.size();
	ll sum=0;
	for(int i=0;i<n;i++)
		sum+=v[i];
	if(sum%n!=0)
		return -1;
	int div=sum/n,answer=0,cd=0,extra=0;
	for(int i=0;i<n;i++)
	{
		extra+=v[i]-div;
		cd=(cd+1)%d;
		if(cd==0)
			answer+=abs(extra);
		if(i==n-1)
			answer+=abs(extra);
	}
	return answer;
}
int main()
{
	int n,d;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&d);
		vector<ll>v(n);
		for(int i=0;i<n;i++)
			scanf("%lld",&v[i]);
		printf("%lld\n",solve(v,d));
	}
	return 0;
}
