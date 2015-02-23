#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int t,*f,*b,i,d,n,mini;
	double speed;
	long long int min,steps;
	scanf("%lld",&t);
	//min=9223372036854775807L;
	while(t--)
	{
		min=9223372036854775807L;
		scanf("%lld",&n);
		f=(long long int*)malloc(sizeof(long long int)*n);
		b=(long long int*)malloc(sizeof(long long int)*n);
		for(i=0;i<n;i++)
			scanf("%lld",&f[i]);
		for(i=0;i<n;i++)
			scanf("%lld",&b[i]);
		scanf("%lld",&d);
		for(i=0;i<n;i++)
		{
			speed=(d-f[i])/(double)(f[i]-b[i]);
			if(speed<=0)
			{
				speed=1;
				if(d<min)
				{
					min=d;
					mini=i;
				}
				continue;
			}
			else if((int)((speed-(int)speed)*100000)!=0)
				speed=(long long int)speed+1;
			steps=(long long int)speed*(b[i]+f[i]);
			steps=steps+d-(long long int)speed*(f[i]-b[i]);
			if(steps<min)
			{
				min=steps;
				mini=i;
			}
			//printf("%lld %lld\n",i,steps);
		}
		printf("%lld\n",(mini+1));
	}
	return 0;
}
