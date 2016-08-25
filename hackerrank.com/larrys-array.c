#include<stdio.h>
#define MAX 1001
int n,arr[MAX];
int findMaxIndex(int l,int r)
{
	int i,index,max;
	index=l;max=arr[l];
	
	for(i=l+1;i<=r;i++)
	{
		if(arr[i]>max)
		{
			index=i;max=arr[i];
		}
	}
	return index;
}
int findAnswer(int a,int b)
{
	int i,maxIndex,x,y,z;
	
	/*
	printf("calling for %d %d array is ",a,b);
	for(i=a;i<=b;i++)
		printf("%d ",arr[i]);
	printf("\n");
	*/
	if(b-a+1==3)
	{
		x=arr[a];
		y=arr[a+1];
		z=arr[a+2];
		
		if(x>=y && y<=z && x>=z)
			return 1;
		if(x<=y && y>=z && x>=z)
			return 1;
		if(x<=y && y<=z && x<=z)
			return 1;
		return 0;
	}
	maxIndex=findMaxIndex(a,b);
	
	while(maxIndex!=b && maxIndex!=b-1)
	{
		x=arr[maxIndex];
		y=arr[maxIndex+1];
		z=arr[maxIndex+2];
		
		arr[maxIndex]=y;
		arr[maxIndex+1]=z;
		arr[maxIndex+2]=x;
		
		maxIndex+=2;
	}
	if(maxIndex==b-1)
	{
		x=arr[maxIndex-1];
		y=arr[maxIndex];
		z=arr[maxIndex+1];
		
		arr[maxIndex-1]=z;
		arr[maxIndex]=x;
		arr[maxIndex+1]=y;
	}
	return findAnswer(a,b-1);
}

int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",arr+i);
		if(findAnswer(0,n-1))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
