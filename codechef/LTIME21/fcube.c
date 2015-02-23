#include<stdio.h>
#define MOD 1000000007
int main()
{
	int t,n;
	long long int sc,s,product,counter,i,a;
	scanf("%d",&t);
	while(t--)
	{
		product=s=1;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%lld",&a);
			s=(s*a)%MOD;
		}
		sc=s;
		counter=0;
		while(s%2==0)
		{
			counter++;
			s/=2;
		}
		counter%=3;
		if(counter==1)
			product=(product*2*2)%MOD;
		else if(counter==2)
			product=(product*2)%MOD;
		for(i=3;i*i<=s;i+=2)
		{
			counter=0;
			while(s%i==0)
			{
				counter++;
				s/=i;
			}
			counter%=3;
			if(counter==1)
				product=(((product*i)%MOD)*i)%MOD;
			else if(counter==2)
				product=(product*i)%MOD;
		}
		if(s>2)
			product=(((product*s)%MOD)*s)%MOD;
		printf("%lld",(product*sc)%MOD);
	}
	return 0;
}
