#include<stdio.h>
#define MAX 100001
int main()
{
	int n,k,arr[MAX],index[MAX],i,i1,i2,v1,v2,temp;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		index[arr[i]]=i;
	}
	for(i=0;i<n && k>0;i++)
	{
		if(arr[i]==n-i)
			continue;
		i1=i;
		i2=index[n-i];
		
		v1=arr[i];
		v2=n-i;
		
		k--;
		temp=arr[i1];
		arr[i1]=arr[i2];
		arr[i2]=temp;
		
		
		temp=index[v1];
		index[v1]=index[v2];
		index[v2]=temp;
	}
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
