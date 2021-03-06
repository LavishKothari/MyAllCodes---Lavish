#include<stdio.h>
#include<stdlib.h>
#define MOD 1000003
#define MAX 1000003
long long int *f;
long long int power(int n,int p)
{
	long long int t;
	if(p==0) return 1;
	t=power(n,p/2);
	if(p%2==0) return (t*t)%MOD;
	else return (((n*t)%MOD)*t)%MOD;
}
long long int ei(int n)
{
    return power(n,MOD-2);
}
long long int fact(int n)
{
	if(n>=MOD)
		return 0;
	return f[n];
}
/*
long long int ncr(int n,int r)
{
    return ( fact(n) * ( ( ei(fact(r)) * ei(fact(n-r)) ) % MOD ) ) % MOD;
}
*/
long long int ncr(int n,int r)
{
	long long int i,small,numerator,denominator;
	small=(n-r)<r?(n-r):r;
	denominator=numerator=1;
	for(i=0;i<small;i++)
	{
		numerator=numerator*(n-i);
	}
	denominator=f[small];
	printf("%lld,%lld\n",numerator,denominator);
	return (numerator*ei(denominator))%MOD;
}

int main()
{
	long long int t,n,l,r,x,j;
	long long int i,answer;
	//printf("%d",((-5)%2));
	f=(long long int *)malloc(sizeof(long long int)*(MAX+1));
    for(i=0;i<=MAX;i++)
    	f[i]=1;
    for(i=2;i<=MAX;i++)
        f[i]=(f[i-1]*i)%MOD;
    
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&l,&r);
		x=(long long int)abs(r-l)+1;
		answer=ncr(x+n,n)-1;
		if(answer<0)
			answer+=MOD;
		
//		for(i=2;i<=n;i++)
//			answer=(answer+ncr(x+i-1,i))%MOD;
		printf("%lld\n",answer);
	}
	free(f);
	return 0;
}
/*

int main()
{
	int i;
	f=(long long int *)malloc(sizeof(long long int)*(MAX+1));
    for(i=0;i<=MAX;i++)
    	f[i]=1;
    for(i=2;i<=MAX;i++)
        f[i]=(f[i-1]*i)%MOD;
	printf("%lld\n",ncr(5,2));
	return 0;
}
*/
