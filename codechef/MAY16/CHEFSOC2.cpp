#include<stdio.h>
typedef long long int ll;
#define NEG_INF -2147483647
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,m,s,arr[1001];
		scanf("%lld%lld%lld",&n,&m,&s);
		for(int i=0;i<m;i++)
			scanf("%lld",&arr[i]);
		ll flag[1001]={0};
		ll start=0,end=(1<<m)-1;
		for(ll i=start;i<=end;i++)
		{
			ll ci=i;
			ll temp=s,counter=0;
			for(ll j=0;j<m;j++)
			{
				if(i&1) temp+=arr[counter];
				else temp-=arr[counter];
				if(temp<1 || temp>n)
				{
					temp=NEG_INF;
					break;
				}
				i/=2;
				counter++;
			}
			if(temp>=1 && temp<=n)
				flag[temp]++;
			i=ci;
		}
		for(int i=1;i<=n;i++)
			printf("%lld ",flag[i]);
		printf("\n");
		
	}
}
