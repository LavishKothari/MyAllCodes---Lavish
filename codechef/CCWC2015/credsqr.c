#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007
void fill(long long int n,long long int*factor)
{	
	long long int i,count;
	for(i=2;n!=1;i++)
	{
		count=0;
		while(n%i==0)
		{
			count++;
			n/=i;
		}
		if(count>factor[i])
			factor[i]=count;
	}
}
long long int power(int a,int b)
{
	long long int t;
	if(b==0)
		return 1;
	if(b==1)
		return a%MOD;
	if(b%2==0)
	{
		t=power(a,b/2);
		return (t*t)%MOD;
	}
	else
	{
		t=power(a,b/2);
		return (((t*t)%MOD)*a)%MOD;
	}
}
int main()
{
	long long int answer;
	long long int n,*arr,i,copy,factor[100];
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		arr=(long long int*)malloc(sizeof(long long int)*n);
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		for(i=0;i<100;i++)
			factor[i]=0;	
		for(i=0;i<n;i++)
		{
			fill(arr[i],factor);
		}
		for(i=0;i<100;i++)
		{
			if(factor[i]!=0)
			{
				factor[i]=factor[i]-factor[i]/2;
			}
		}
		
		
		answer=1;
		for(i=0;i<100;i++)
		{
			if(factor[i]!=0)
			{
				answer=(answer*power(i,factor[i]))%MOD;
			}
		}
		answer=(answer*answer)%MOD;
		printf("%lld\n",answer);
	}
	return 0;
}
