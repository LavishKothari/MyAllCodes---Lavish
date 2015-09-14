#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int answer;
	int t,i,*arr,n,min;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		arr=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			if(i==0)
				min=arr[i];
			else if(arr[i]<min)
				min=arr[i];
		}
		answer=min*(long long int)(n-1);
		printf("%lld\n",answer);
	}
	return 0;
}
