#include<stdio.h>
#define MAX 100001
typedef long long int ll;
ll div[MAX]={0};
ll sum[MAX]={0};
void populateDivisors()
{
	int i,j;
	sum[0]=div[0]=0;
	for(i=1;i<MAX;i++)
	{
		if(i&1)
			for(j=i;j<MAX;j+=i)
				div[j]+=i;
		sum[i]=sum[i-1]+div[i];
	
	}
	printf("%lld\n",div[9999]);
	//for(i=0;i<=10;i++)
	//	printf("this is a test %d = %lld %lld\n",i,div[i],sum[i]);
}

int main()
{
	int t,l,r;
	scanf("%d",&t);
	populateDivisors();
	
	while(t--)
	{
		scanf("%d%d",&l,&r);
		printf("%lld\n",sum[r]-sum[l-1]);
	}
	return 0;
}
