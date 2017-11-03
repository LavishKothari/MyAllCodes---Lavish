#include<bits/stdc++.h>
typedef long long int ll;
#define MOD 1000000007
using namespace std;
ll answer=0;
ll power(ll a,ll b)
{
	if(b==0)
		return 1;
	ll t = power(a,b/2);
	ll tt = (t*t)%MOD;
	if(b&1)
		return (tt*a)%MOD;
	return tt;
}

void sol(int c,vector<int>&v,ll prev)
{
	if(c>=v.size()) return;
	int n=v.size();
	ll p = power(2,n-c-2);
	answer = answer + prev*p;
	answer = answer+v[c]*p;
	sol(c+1,v,0);
	if(c+1>=v.size()) return;
	if(prev) prev = prev*v[c]*v[c+1];
	else prev = v[c]*v[c+1];
	sol(c+2,v,prev);
}

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int>v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		sol(0,v,0);
		cout<<answer<<endl;
	}
	return 0;
}
