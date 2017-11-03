#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll sol1(ll n,ll k,string s)
{
	vector<ll>a(n,0);
	vector<ll>b(n,0);

	if(s[0]=='a')
		a[0]=1;
	for(int i=1;i<n;i++)
		if(s[i]=='a')
			a[i]=a[i-1]+1;
		else a[i]=a[i-1];

	if(s[n-1]=='b')
		b[n-1]=1;
	for(int i=n-2;i>=0;i--)
		if(s[i]=='b')
			b[i]=b[i+1]+1;
		else b[i]=b[i+1];

	ll answer=0;
	for(int i=0;i<n;i++)
		if(s[i]=='a')
			answer+=b[i];
	answer=answer*k;
	return answer+a[n-1]*b[0]*((k*(k-1))/2);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,k;
		scanf("%lld%lld",&n,&k);
		string s;
		cin>>s;
		printf("%lld\n",sol1(n,k,s));
	}
	return 0;
}
