#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<ll,ll>answer;
ll calAnswer(ll n)
{
	if(answer.find(n)==answer.end())
	{
		ll a=calAnswer(n/2);
		ll b=calAnswer(n/3);
		ll c=calAnswer(n/4);

		answer[n]=max(n,a+b+c);
	}
	return answer[n];
}

int main()
{
	ll n;
	for(int i=0;i<=3;i++)
		answer[i]=i;
	while(scanf("%lld",&n)==1)
		cout<<calAnswer(n)<<endl;
	return 0;
}
