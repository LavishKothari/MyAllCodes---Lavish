#include<stdio.h>

int main()
{
	long long int breads,k;
	int t,n,num,i;
	scanf("%d",&t);
	while(t--)
	{
		breads=0;
		scanf("%d%lld",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",&num);
			breads+=num;
			if(breads%k!=0)
				breads++;
		}
		if(breads%k==0)
			printf("%lld\n",breads/k);
		else
			printf("%lld\n",breads/k+1);
	}
	return 0;
}
