#include<stdio.h>

int main()
{
	long long int t,temp,num,x,countx,countn,i;
	scanf("%lld",&t);
	while(t--)
	{
		num=0;
		for(i=0;i<15;i++)
		{
			scanf("%lld",&temp);
			num=num^temp;
		}
		scanf("%lld",&x);
		countn=0;
		while(num)
		{
			if(num&1)
				countn++;
			num>>=1;
		}
		if(countn>x)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
