#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll n,q;
	cin>>n>>q;
	vector<vector<ll> >v(n,vector<ll>());
	ll lastAnswer=0;
	while(q--)
	{
		int type;
		ll x,y;
		cin>>type>>x>>y;
		if(type==1)
		{
			v[(x^lastAnswer)%n].push_back(y);
		}
		else
		{
			lastAnswer = v[(x^lastAnswer)%n][y%v[(x^lastAnswer)%n].size()];
			cout<<lastAnswer<<endl;
		} 
	}
	return 0;
}
