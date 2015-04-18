#include<stdio.h>
#include<stdlib.h>
int com(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int flagn=0,flag0=0,flag1=0,n,i,temp,*arr,min=101;
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]<0)
			flagn++;
		if(arr[i]==0)
			flag0=1;
		if(arr[i]==1)
			flag1=1;
	}
	qsort(arr,n,sizeof(int),com);
	if(flagn==0 && flag0==1) // if no negative number are there and 0's are there.
	{
		for(i=0;i<n;i++)
			printf("%d ",arr[i]);
	}
	else if(flagn==0 && flag0==0) // if no negative number and no 0 then print minimum in array.
	{
		for(i=0;i<n;i++)
			if(min>arr[i])
				min=arr[i];
		printf("%d",min);
	}
	else if(flagn!=0 && flag0==0) 
	{
		if(flagn%2==0)
		{
			for(i=0;i<flagn-1;i++)
				printf("%d ",arr[i]);
			for(i=0;i<n;i++)
				if(arr[i]>0)
					printf("%d ",arr[i]);
		}
		else
		{
			for(i=0;i<n;i++)
				if(arr[i]<0 || arr[i]>0)
					printf("%d ",arr[i]);
		}
	}
	else if(flagn!=0 && flag0==1)
	{
		if(flagn%2==0)
		{
			for(i=0;i<flagn-1;i++)
				printf("%d ",arr[i]);
			for(i=0;i<n;i++)
				if(arr[i]>0)
					printf("%d ",arr[i]);
		}
		else
		{
			for(i=0;i<n;i++)
				if(arr[i]<0 || arr[i]>0)
					printf("%d ",arr[i]);
		}
	}
	return 0;
}
