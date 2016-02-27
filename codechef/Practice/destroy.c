#include<stdio.h>
#include<stdlib.h>
int c(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int t,max,counter,i,n,*arr;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		arr=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		qsort(arr,n,sizeof(int),c);
		max=counter=1;
		for(i=1;i<n;i++)
		{
			if(arr[i]==arr[i-1])
				counter++;
			else counter=1;
			if(counter>max)
				max=counter;
		}
		if(max>n/2)
			printf("%d\n",max);
		else
		{
			if(n&1)
				printf("%d\n",n/2+1);
			else printf("%d\n",n/2);
		}
		free(arr);
	}
	return 0;
}
