#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll findAnswer(ll n)
{
	ll answer=0;
	for(int currentPower=1;n;n>>=1,currentPower*=2)
		if(!(n&1))
			answer+=currentPower;
	return answer;
}
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		ll n;
		cin>>n;
		cout<<findAnswer(n)<<endl;
	}
	return 0;
}
