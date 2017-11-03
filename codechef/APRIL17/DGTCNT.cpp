#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool isOK(ll n,vector<int>&a)
{
	vector<int>b(10,0);
	while(n)
	{
		b[n%10]++;
		n/=10;
	}
	for(int i=0;i<10;i++)
		if(a[i]==b[i])
			return false;
	return true;
}
ll sol(ll l,ll r,vector<int>&a)
{
	ll answer=0;
	for(ll i=l;i<=r;i++)
		if(isOK(i,a))
			answer++;
	return answer;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		vector<int>a(10);
		for(int i=0;i<10;i++)
			scanf("%d",&a[i]);
		cout<<sol(l,r,a)<<endl;
	}
	return 0;
}
