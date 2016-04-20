#include<stdio.h>
#include<stdlib.h>
int c(const void*x,const void*y)
{
	return *(int*)x-*(int*)y;
}
int main()
{
	int n,i,arr[1000001];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	qsort(arr,n,sizeof(int),c);
	for(i=n-2;i>=0;i--)
		if(arr[i]!=arr[i+1])
			break;
	if(i==-1)
		printf("0\n");
	else printf("%d\n",arr[i]);
	return 0;
}
