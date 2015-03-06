#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int t,n,k,len,mmin,mmax,i,j,ci,g,*arr;
	long long int product;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		mmax=max(k,n-k);
		mmin=min(k,n-k);
		len=n-mmax;
		arr=(int*)malloc(sizeof(int)*len);
		for(i=0;i<len;i++)
			arr[i]=i+mmax+1;
		for(i=1;i<=mmin;i++)
		{
			ci=i;
			for(j=0;j<len;j++)
			{
				g=gcd(arr[j],ci);
				arr[j]/=g;
				ci/=g;
				if(ci==1)
					break;
			}
		}
		product=1;
		for(i=0;i<len;i++)
			product*=arr[i];
		printf("%lld ",product);
	}
	return 0;
}
