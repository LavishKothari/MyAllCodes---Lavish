#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		cin>>n;
		ll x=(n*(n+1))/2 * (n*(n+1))/2;
		ll y=(n*(n+1)*(2*n+1))/6;
		cout<<abs(x-y)<<endl;
	}
	return 0;
}