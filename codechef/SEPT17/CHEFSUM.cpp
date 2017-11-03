#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void sol(vector<ll>&v)
{
	int n=v.size();
	vector<ll>pre(n,0),pos(n,0);
	for(int i=0;i<n;i++)
		pre[i]=(i-1<0?0:pre[i-1])+v[i];
	for(int i=n-1;i>=0;i--)
		pos[i]=(i+1>n-1?0:pos[i+1])+v[i];
	ll m=LONG_MAX;
	int index=-1;
	for(int i=0;i<n;i++)
		if(m>pre[i]+pos[i])
		{
			m=pre[i]+pos[i];
			index=i;
		}
	printf("%d\n",index+1);


}
int main()
{
	int t;
	scanf("%d",&t);
	int n;
	while(t--)
	{
		scanf("%d",&n);
		vector<ll>v(n);
		for(int i=0;i<n;i++)
			scanf("%lld",&v[i]);
		sol(v);
	}
	return 0;
}

