#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1000000
#define MOD 1000000007
vector<ll>sum(N+1,0);

int main()
{
	int t,a,b;
	for(int i=2;i<sum.size();i++)
		sum[i]=(sum[i-1]+(((ll)i*(i-1))/2)%MOD)%MOD;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		printf("%lld\n",(sum[b-1]-sum[max(0,a-2)]+MOD)%MOD);
	}
	return 0;
}
