#include<stdio.h>

int main()
{
	long long int t,f,m;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&f,&m);
		if(m%f==0)
			printf("CORRECT\n");
		else
			printf("WRONG\n");
	}
	return 0;
}
