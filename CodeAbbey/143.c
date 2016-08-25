#include<stdio.h>
typedef long long int ll;

long long int px,py;

ll GCD(ll a,ll b)
{
	ll temp,x,y,tempx,tempy,gcd,q,ca,cb;
	
	y=px=1;
	py=x=0;
	ca=a;cb=b;
	while(b!=0)
	{
		q=a/b;
		
		tempx=px;
		tempy=py;
		
		px=x;py=y;
		x=tempx-q*x;
		y=tempy-q*y;
		
		temp=a-q*b;
		a=b;
		b=temp;
	}
	//printf("%lld x %lld + %lld x %lld\n",ca,px,cb,py);
	return a;
}

int main()
{
	ll t,a,b,g;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		g=GCD(a,b);
		printf("%lld %lld %lld\n",g,px,py);
	}
	
	return 0;
}
