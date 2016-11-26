
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define MOD 1000000007

int nearestThatDivides(vector<ll>&s,ll n)
{
	int x=(int)sqrtl(n);
	int index=lower_bound(s.begin(),s.end(),x)-s.begin();
	if(s[index]==x && n%s[index]==0)
	{
		return index;
	}
	
}

int main()
{
    
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;int m;
		scanf("%lld%d",&n,&m);
		vector<ll>s(m);
		for(int i=0;i<m;i++)
			cin>>s[i];

		sort(s.begin(),s.end());

		
	}
    return 0;
}