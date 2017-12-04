#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll inverse(ll a,ll b)
{
	ll temp,q,remainder,quotient,px,py,ca,cb,x,y;
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
	}
	return (x+cb)%cb;
}
ll power(ll a,ll b,ll mod)
{
	if(b==0)
		return 1;
	ll t=power(a,b/2,mod);
	if(b&1)
		return (((t*t)%mod)*a)%mod;
	else return (t*t)%mod;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll N,P,Q;
		scanf("%lld%lld%lld",&N,&P,&Q);
		vector<ll>v(N),pro(N),inv(N),B(Q/64+2);
		for(int i=0;i<N;i++)
			scanf("%lld",&v[i]);
		for(int i=0;i<N;i++)
			pro[i]=((i-1>=0?pro[i-1]:1)*v[i])%P;
		inv[0]=(inverse(v[0],P)+P)%P;
		for(int i=1;i<N;i++)
			inv[i]=(inverse(v[i],P)*inv[i-1]+P)%P;

		ll x=0,prevL,prevR,Li,Ri;

		for(int i=0;i<B.size();i++)
			scanf("%lld",&B[i]);

		for(int i=0;i<Q;i++)
		{
			if(i%64==0)
			{
				Li=(B[i/64]+x)%N;
				Ri=(B[i/64+1]+x)%N;
			}
			else
			{
				Li=(prevL+x)%N;	
				Ri=(prevR+x)%N;
			}
			if(Li>Ri)
				swap(Li,Ri);
//			ll answer = (pro[Ri]*(Li-1>=0?inverse(pro[Li-1],P):1))%P;
			ll answer = (pro[Ri]*(Li-1>=0?inv[Li-1]:1))%P;
			x=(answer+1)%P;
			prevL = Li;
			prevR = Ri;
		}
		printf("%lld\n",x);
	}
	return 0;
}
