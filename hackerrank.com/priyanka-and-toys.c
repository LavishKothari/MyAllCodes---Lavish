#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n,*arr,i,temp,counter;
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	qsort(arr,n,sizeof(int),cmp);
	counter=0;
	for(i=0;i<n;)
	{
		counter++;
		temp=arr[i];
		i++;
		while(arr[i]<=temp+4)
			i++;
	}
	printf("%d\n",counter);
	free(arr);
	return 0;
}
