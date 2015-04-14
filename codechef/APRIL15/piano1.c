#include<stdio.h>

int main()
{
	int t,n,i,a,blocks;
	long long int answer;
	char str[101];
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str);
		scanf("%d",&n);
		answer=a=0;
		for(i=0;str[i];i++)
		{
			if(str[i]=='S')
				a++;
			else a+=2;
		}
		blocks=12*n-1;
		for(i=0;i<=12*n-a-1;i++)
		{
			blocks=12*n-1-i;
			answer+=blocks/a;
		}
		printf("%lld\n",answer);
	}
	return 0;
}
