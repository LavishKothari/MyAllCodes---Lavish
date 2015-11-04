#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,k;
		scanf("%lld%lld",&n,&k);
		long long int sum=(n*(n+1))/2;
		if(sum%2==0)
		{
			if((k%2)==0 && k<=sum && k>=-sum)
				printf("YES\n");
			else printf("NO\n");
		}
		else 
		{
			if((k%2)!=0 && k<=sum && k>=-sum)
				printf("YES\n");
			else printf("NO\n");
		}
	}
}
