#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define N 1010
vector<ll>factorial(N);
ll power(ll a,ll b)
{
	if(b==0)
		return 1;
	ll temp = power(a,b/2);
	if(b&1)
		return ((temp*temp)%MOD*a)%MOD;
	else return (temp*temp)%MOD;
}

ll inv(ll a)
{
	return power(a,MOD-2);
}
void populateFactorial()
{
	factorial[0]=factorial[1]=1;
	for(int i=2;i<N;i++)
		factorial[i]=(i*factorial[i-1])%MOD;
}

ll findAnswer(int n,int m)
{
	return ((factorial[m+n]*inv(factorial[m]))%MOD*inv(factorial[n]))%MOD;
}
int main()
{
	populateFactorial();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		cout<<findAnswer(n,m)<<endl;
	}
	return 0;
}
