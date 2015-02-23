#include<stdio.h>
#define MOD 10000007
int main()
{
	int arr[10000],n,i,temp,swaps=0,len;
	long long int checksum;
	i=-1;
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
			break;
		i++;
		arr[i]=n;
	}
	len=i+1;
	for(i=0;i<len-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
			swaps++;
			temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=temp;
		}
	}
	printf("%d ",swaps);
	checksum=0;
	i=0;
	while(i<len)
	{
		checksum=((checksum+arr[i])*113)%MOD;
		i++;
	}
	printf("%lld ",checksum);
}

