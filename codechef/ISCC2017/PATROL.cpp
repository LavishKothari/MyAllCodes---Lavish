#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll t,u,v,x;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&u,&v,&x);
		printf("%.10lf\n",(double)x/(u+v));
	}
	return 0;
}
