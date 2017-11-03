#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<pair<ll,ll>,ll>m;

ll sol(vector<ll>&v,ll i,ll k)
{
	pair<ll,ll>p=make_pair(i,k);
	if(m.find(p)!=m.end())
		return m[p];
	if(i==0)
	{
		if(v[0]>k)
		{
			m[p]=1;
			return 1;
		}
		m[p]=0;
		return 0;
	}
	ll answer=sol(v,i-1,k)+sol(v,i-1,k/v[i])+(v[i]>k);
	return m[p]=answer;
}
int main()
{
	ll N,K;
	scanf("%lld%lld",&N,&K);
	vector<ll>v(N);
	for(int i=0;i<N;i++)
		scanf("%lld",&v[i]);
	printf("%lld\n",((ll)1<<N)-1 - sol(v,N-1,K));
	return 0;
}
