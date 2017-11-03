#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return (a*b)/gcd(a,b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		cin>>n;
		ll l=1;
		for(int i=2;i<=n;i++)
			l=lcm(l,i);
		cout<<l<<endl;
	}
	return 0;
}