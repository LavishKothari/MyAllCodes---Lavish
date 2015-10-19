#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,*arr,i,n,sum;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		arr=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		if(sum && sum%n==0)
			printf("%d\n",sum/n);
		else printf("-1\n");
	}
	return 0;
}
