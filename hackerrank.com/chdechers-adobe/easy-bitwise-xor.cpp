1#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll power1(ll a,ll b,ll m)
{
	if(b==0)
		return 1;
	ll t=power1(a,b/2,m);
	if(b&1)
		return (((t*t)%m)*a)%m;
	return (t*t)%m ;
}



ll getSum(ll n,ll a,ll d,ll m)
{
	a%=m;
	n%=m;
	d%=m;

	//ll x=((n*( (2*a)%m + ((n-1)*d)%m )%m )%m*(m/2+1))%m;
	ll x=((n*( (2*a)%m + ((n-1)*d)%m )%m )%m*(power1(2,m-2,m)))%m;
	//ll x=((n*( (2*a)%m + ((n-1)*d)%m )%m )%m*(m/2+1))%m;
	return (x+m)%m;
}
ll f(ll a,ll b,ll d,ll m)
{

	if(d%2==0)
	{
		ll n=(b-a)/d+1;

		if(a+(n-1)*d>=b)
			n--;

		if(a&1)
			a--;
		else a++;

		ll s=getSum(n,a,d,m);

		return s;
	}
	else
	{
		ll n=(b-a)/d+1;

		if(a+(n-1)*d>=b)
			n--;

		ll n1,n2;
		if(n%2==0)
		{
			n1=n/2;
			n2=n/2;
		}
		else
		{
			n1=n/2+1;
			n2=n/2;
		}

		ll a1,a2;
		if(a&1)
			a1=a-1;
		else a1=a+1;

		a+=d;

		if(a&1)
			a2=a-1;
		else a2=a+1;
		//cout<<a1<<" "<<a2<<" "<<n1<<" "<<n2<<" "<<getSum(n1,a1,2*d,m)<<" "<<getSum(n2,a2,2*d,m)<<endl;
		return (getSum(n1,a1,2*d,m)+getSum(n2,a2,2*d,m))%m;

	}

}
ll f1(ll a, ll b,ll d,ll m) {
	ll s = 0;

	while (a < b) {
		s = (s + (a ^ 1))%m;
		a = a + d;
	}

	return s % m;
}



int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,b,d,m;
		scanf("%lld%lld%lld%lld",&a,&b,&d,&m);
		printf("%lld\n",f(a,b,d,m));
		//printf("loop %lld\n",f1(a,b,d,m));

	}

	return 0;
}
