#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	else return gcd(b,a%b);
}
void solve(int x1,int v1,int x2,int v2)
{
	int d=gcd(v1,v2);
	if((x2-x1)%d==0)
	{
		printf("YES\n");
		return;
	}
	printf("NO\n");
}
int main()
{
	int x1,v1,x2,v2;
	scanf("%d%d",&x1,&v1,&x2,&v2);
	solve(x1,v1,x2,v2);
	return 0;
}
