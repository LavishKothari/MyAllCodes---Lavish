#include<stdio.h>
typedef long long int ll;
#define MAX_T 1000000000
#define MAX 100001
ll n,w,l,h[MAX],r[MAX],newh[MAX];

ll findNew(ll t)
{
	ll maxredeemption=0,i;
	for(i=0;i<n;i++)
	{	
		newh[i]=h[i]+r[i]*t;
		if(newh[i]>=l)
			maxredeemption+=newh[i];
	}
	return maxredeemption;
}
ll findAnswer()
{
	ll w1,w2,w3,startt=0,endt=MAX_T,t;
	if(findNew(0)>=w)
		return 0;
	while(1)
	{
		t=(startt+endt)/2;
		
		w1=findNew(t);
		w2=findNew(t-1);
		w3=findNew(t+1);
		
		//printf("hello lavish kothari %lld %lld %lld\n",t,w1,w2);
		
		if(w2<w && w1>=w)
			return t;
		if(w3>=w && w1<w)
			return t+1;
		if(w1>w)
			endt=t-1;
		else startt=t+1;
		if(startt>=endt)
			break;
	}
	return t;
}
int main()
{
	ll i;
	scanf("%lld%lld%lld",&n,&w,&l);
	for(i=0;i<n;i++)
		scanf("%lld%lld",h+i,r+i);
	printf("%lld\n",findAnswer());
	return 0;
}
