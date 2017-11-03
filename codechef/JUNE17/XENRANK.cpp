#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll sol(int x,int y)
{
	ll n=x+y;
	return (n*(n+1))/2 + x + 1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",sol(x,y));
	}
}
