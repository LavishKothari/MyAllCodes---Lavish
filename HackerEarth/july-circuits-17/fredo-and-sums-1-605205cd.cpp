#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(vector<ll>&v)
{
	sort(v.begin(),v.end());
	int n=v.size();
	ll mina=0,maxa=0;
	for(int i=0,j=n-1;i<j;i++,j--)
		maxa+=abs(v[i]-v[j]);
	for(int i=0;i+1<n;i+=2)	
		mina+=abs(v[i]-v[i+1]);
	printf("%lld %lld\n",mina,maxa);
}
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<ll>v(n);
		for(int i=0;i<n;i++)
			scanf("%lld",&v[i]);
		solve(v);	
	}
	return 0;
}
