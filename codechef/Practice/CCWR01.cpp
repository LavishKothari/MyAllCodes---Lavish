#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		vector<ll>cost(n);
		for(ll i=0;i<n;i++)
			scanf("%lld",&cost[i]);
		ll w,y;
		scanf("%lld%lld",&w,&y);
		sort(cost.begin(),cost.end());
		if(n<y || w<y)
			printf("Not Possible\n");
		else 
		{
			ll mincost=0;
			mincost=(w-y+1)*cost[0];
			for(ll i=1;i<y;i++)
				mincost+=cost[i];
			printf("%lld\n",mincost);
		}
	}
	return 0;
}
