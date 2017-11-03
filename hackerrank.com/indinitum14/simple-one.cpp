#include<stdio.h>
#include<utility>
#define MOD 1000000007
using namespace std;
typedef long long int ll;
long long int x,y;
long long int GCD(long long int a,long long int b)
{
	long long int temp,q,remainder,quotient,px,py,ca,cb;
	py=x=0;
	ca=a;
	cb=b;
	px=y=1;
	while(b!=0)
	{
		quotient=a/b;
		remainder=a%b;

		a=b;
		b=remainder;
		if(remainder==0)
			break;

		temp=x;
		x=px-x*quotient;
		px=temp;

		temp=y;
		y=py-y*quotient;
		py=temp;
		//printf("%lld = %lld * %lld + %lld * %lld\n",remainder,x,ca,y,cb);

	}
	return a;
}
pair<ll,ll> tanna(pair<ll,ll>f,ll n)
{
	if(n==1)
		return f;
	pair<ll,ll>r=tanna(f,n/2);
	if(n&1)
	{
		pair<ll,ll>inter;
		if((r.second*r.second-r.first*r.first)%MOD<0) inter=make_pair((-2*r.first*r.second)%MOD,(-r.second*r.second+r.first*r.first)%MOD);
		else inter=make_pair((2*r.first*r.second)%MOD,(r.second*r.second-r.first*r.first)%MOD);
		if((f.second*inter.second-f.first*inter.first)%MOD<0)
			return make_pair((-(f.first*inter.second+f.second*inter.first))%MOD,(-f.second*inter.second+f.first*inter.first)%MOD);
		return make_pair((f.first*inter.second+f.second*inter.first)%MOD,(f.second*inter.second-f.first*inter.first)%MOD);
	}
	else
	{
		if((r.second*r.second-r.first*r.first)%MOD<0)
			return make_pair((-2*r.first*r.second)%MOD,(-r.second*r.second+r.first*r.first)%MOD); 
		return make_pair((2*r.first*r.second)%MOD,(r.second*r.second-r.first*r.first)%MOD);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll p,q,n;
		scanf("%lld%lld%lld",&p,&q,&n);
		pair<ll,ll>result=tanna(make_pair(p,q),n);
		ll a,b;
		a=result.first;
		b=result.second;
		GCD(b,MOD);
		ll answer=(a*x)%MOD;
		while(answer<0) answer+=MOD;
		printf("%lld\n",answer);
	}
	return 0;
}
