#include<stdio.h>
#include<stdlib.h>
int lower_bound(int *arr,int n,int sval)
{	
	int start=0,end=n-1;
	while(1)
	{
		t=(start+end)/2;
		if(sval>arr[t])
	}
}
int main()
{
	int *arr,n;
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int )*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}	
	scanf("%d",&temp);
	printf("%d\n",lower_bound(arr,n,temp));
	return 0;
}
