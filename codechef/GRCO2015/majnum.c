#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void *a,const void *b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	int t,n,*arr,size,i,j,count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		arr=(int*)malloc(sizeof(int)*n);
		size=0;
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		qsort(arr,n,sizeof(int),cmpfunc);
		for(i=0;i<n;i++)
		{
			for(count=0,j=i;j<n && arr[i]==arr[j];j++,count++);
			if(count > n/2)
				break;
		}
		if(i==n)
			printf("NO MAJOR\n");
		else
			printf("%d\n",arr[i]);
	}
	return 0;
}

