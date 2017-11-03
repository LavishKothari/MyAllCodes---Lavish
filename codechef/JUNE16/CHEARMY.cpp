#include<stdio.h>
#include<math.h>
typedef long long int ll;

ll power(ll a,ll b)
{
	if(b==0)
		return 1;
	ll temp=power(a,b/2);
	if(b&1)
		return temp*temp*a;
	return temp*temp;
}

void fa(ll d,ll k)
{	
	if(d==0)
		return;
	ll ck=k;
	int x=(int)(log2(k)/log2(5));
	ll uio=power(5,x);
	if(uio==k)
		x--;
	if(d>x+1)
	{
		printf("0");
		fa(d-1,k); // recursive call
		return;
	}
	if(uio==k)
		x++;
	if(k<=5)
	{
		printf("%lld",(k-1)*2);
		return;
	}
	if(uio==k)
	{
		ll sum=0;
		for(int i=0;i<x;i++)
			sum=sum*10+8;
		printf("%lld",sum);
		return;
	}

	x++;
	ll batch=power(5,x-1);
	k=k-batch;
	ll p;
	if(k%batch!=0)
		p=(k/batch+1)*2;
	else p=(k/batch)*2;
	printf("%lld",p);
	fa(d-1,ck-(batch*(p/2-1)+batch)); // recursive call
}

int main()
{
	ll t,k;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&k);
		int x=(int)(log2(k)/log2(5));

		if(power(5,x)==k)
		{
			ll sum=0;
			for(int i=0;i<x;i++)
				sum=sum*10+8;
			printf("%lld\n",sum);
			continue;
		}

		fa(x+1,k);
		printf("\n");
	}
	return 0;
}
