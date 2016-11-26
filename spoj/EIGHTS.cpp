#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<ll,ll>answer;
ll max_num=LLONG_MIN;
ll findAnswer(ll n)
{
	if(max_num<n)
		max_num=n;
	if(answer.find(n)==answer.end())
	{
		// here calculate answer[n]

	}
	return answer[n];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<findAnswer(n);
	}
	return 0;
}
