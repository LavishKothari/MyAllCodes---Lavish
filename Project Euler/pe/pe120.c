#include<stdio.h>
long long int findmax(const long long int a)
{
	long long int i,mod,max;
	long long int flag[a*a];
	for(i=0;i<a*a;i++)
		flag[i]=0;
	for(i=0;;i++)
	{
		if(i%2==0)
		{
			mod=2;
		}
		else 
		{
			mod=(2*a*i)%(a*a);
			if(flag[mod])
				break;
		}
		//printf("n=%lld mod=%lld\n",i,mod);
		flag[mod]=1;
	}
	max=0;
	for(i=0;i<a*a;i++)
		if(flag[i] && i>max)
			max=i;
	return max;
}
int main()
{
	long long int i,sum=0;
	for(i=3;i<=1000;i++)
		sum+=findmax(i);
	printf("%lld\n",sum);
	return 0;
}
