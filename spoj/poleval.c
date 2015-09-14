#include<stdio.h>
#include<stdlib.h>
int main()
{	
	int *arr,cas;
	long long int answer,j,i,k,n,temp;
	cas=0;
	while(1)
	{
		scanf("%lld",&n);
		if(n==-1)
			break;
		arr=(int*)malloc(sizeof(int)*(n+1));
		for(i=0;i<=n;i++)
			scanf("%d",&arr[i]);
		scanf("%lld",&k);
		cas++;
		printf("Case %d:\n",cas);
		for(i=0;i<k;i++)
		{
			answer=0;
			scanf("%lld",&temp);
			for(j=0;j<=n;j++)
				answer=answer*temp+arr[j];
			printf("%lld\n",answer);
		}
		free(arr);
	}
	return 0;
}
