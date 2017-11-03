#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
void getCum(vector<ll>&A,vector<ll>&sum)
{
	sum[0]=A[0]%MOD;
	for(int i=1;i<A.size();i++)
		sum[i] = (sum[i-1]+A[i])%MOD;
}
ll modmul(ll a,ll b=1,ll c=1,ll d=1)
{
	return (((((a*b)%MOD)*c)%MOD)*d)%MOD;
}

ll sol(vector<ll>&P,vector<ll>&Q,vector<ll>&R)
{
	sort(P.begin(),P.end());
	sort(R.begin(),R.end());

	vector<ll>sumP(P.size(),0);
	vector<ll>sumR(R.size(),0);

	getCum(P,sumP);
	getCum(R,sumR);
	ll answer=0;
	for(int i=0;i<Q.size();i++)
	{
		ll y = Q[i];
		int n = upper_bound(P.begin(),P.end(),Q[i])-P.begin();
		int m = upper_bound(R.begin(),R.end(),Q[i])-R.begin();
		if(n==0 || m==0)
			continue;
		ll xsum=sumP[n-1],zsum=sumR[m-1];

		ll ca;
		ca = modmul(y,y,n,m) + modmul(y,zsum,n) + modmul(y,xsum,m) + modmul(xsum,zsum);
		answer = (answer+ca)%MOD;
	}	
	return answer;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int p,q,r;
		scanf("%d%d%d",&p,&q,&r);

		vector<ll>P(p);
		vector<ll>Q(q);
		vector<ll>R(r);

		for(int i=0;i<p;i++)
			scanf("%lld",&P[i]);
		for(int i=0;i<q;i++)
			scanf("%lld",&Q[i]);
		for(int i=0;i<r;i++)
			scanf("%lld",&R[i]);
		cout<<sol(P,Q,R)<<endl;
	}
	return 0;
}
