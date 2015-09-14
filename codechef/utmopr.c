#include<stdio.h>

int main()
{
	int t,n,sum,k,i,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			sum=(sum+temp)%2;
		}
		if(k==1)
		{
			if(sum==0)
				printf("odd\n");
			else
				printf("even\n");
		}
		else
			printf("even\n");
	}
	return 0;
}
