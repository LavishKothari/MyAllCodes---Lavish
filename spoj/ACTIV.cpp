// sorting according to the finishing time
// and then applying dynamic programming
#include<bits/stdc++.h>
using namespace std;
#define MOD 100000000 
typedef long long int ll;
void prettyprint(int n) {
	n%=MOD;
	string s="";
	while(n)
	{
		s.push_back((n%10)+'0');
		n/=10;
	}

	for(int i=7;i>=0;i--)
		if(i>=s.size()) printf("0");
		else printf("%c",s[i]);
	printf("\n");
}
void solve(vector<pair<ll,ll> >&vp) {
	sort(vp.begin(),vp.end(),[](const pair<ll,ll>&a,const pair<ll,ll>&b)->bool{return a.second<b.second;});
	vector<ll>dp(vp.size(),0);

	dp[0]=1;
	for(int i=1;i<dp.size();i++)
	{
		int x = 0, y = 0, z = 0;
		x = dp[i-1];
		y = upper_bound(vp.begin(),vp.begin()+i,vp[i],[](const pair<ll,ll>&a,const pair<ll,ll>&b)->bool{return a.first<b.second;})-vp.begin();
		if(y>0)
			z = dp[y-1];
		dp[i] = (1 + x + z)%MOD;
	}
	prettyprint(dp[vp.size()-1]);
}

int main() {

	ll a,b;
	while(true) {
		ll n;scanf("%lld",&n);
		if(n<1)
			break;
		vector<pair<ll,ll> >vp(n);
		for(int i=0;i<n;i++) {
			scanf("%lld%lld",&a,&b);
			vp[i]=make_pair(a,b);
		}
		solve(vp);
	}
	return 0;
}
