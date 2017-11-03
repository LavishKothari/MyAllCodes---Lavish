#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool cmp(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
	return a.first<b.first;
}
// merging the intervals
// this function returns the number of elements in 
// all the merged intervals.
ll merge(vector<pair<ll,ll> >&r)
{
	if(r.size()==0)
		return 0;
	sort(r.begin(),r.end(),cmp);
	stack<pair<ll,ll> >s;
	s.push(r[0]);
	for(int i=1;i<r.size();i++)
	{
		pair<ll,ll>p=s.top();
		pair<ll,ll>c=r[i];
		if(p.second<c.first)
			s.push(c);
		else
		{
			s.pop();
			p.second = max(p.second,c.second);
			s.push(p);
		}
	}
	ll ans=0;
	while(!s.empty())
	{	
		pair<ll,ll>p=s.top();
		s.pop();
		ans+=p.second-p.first+1;
	}
	return ans;
}
ll sol(vector<ll>&v,ll l,ll r)
{
	int n=v.size();
	ll ans=0;
	vector<pair<ll,ll> >range;
	sort(v.begin(),v.end());
	for(int i=1;i<n;i++)
	{
		ll y=v[i-1],z=v[i];
		ll n1=max(z-y+1,l);
		ll n2=min(y+z-1,r);
		if(n1<=n2)
			range.push_back(make_pair(n1,n2));
	}
	return merge(range);
}

int main()
{
	ll n,l,r;
	scanf("%lld%lld%lld",&n,&l,&r);
	vector<ll>v(n);
	for(int i=0;i<n;i++)
		scanf("%lld",&v[i]);
	cout<<sol(v,l,r)<<endl;
	return 0;
}
