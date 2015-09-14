#include<stdio.h>

int main()
{
	int n,i;
	long long int answer=0;
	scanf("%d",&n);
	i=1;
	while(1)
	{
		if(i*i>n)
			break;
		answer+=n/i-i+1;
		i++;
	}
	printf("%lld\n",answer);
	return 0;
}
