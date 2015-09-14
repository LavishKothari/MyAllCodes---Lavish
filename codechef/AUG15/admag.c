#include<stdio.h>
int main()
{
	int t,i;
	long long int n,arr[100];
	arr[0]=1;
	arr[1]=2;
	for(i=2;i<100;i++)
		arr[i]=arr[i-1]+arr[i-2];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n==1)
			printf("1\n");
		else
		{
			for(i=0;;i++)
			{
				if(arr[i]<=n && arr[i+1]>n)
				{
					printf("%d\n",i+1);
					break;
				}
			}
		}
	}
	return 0;
}
