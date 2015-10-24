#include<stdlib.h>
#include<stdio.h>
int cp(const void*a,const void *b)
{
	return *(int*)b-*(int*)a;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int*arr;
	arr=new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	qsort(arr,n,sizeof(int),cp);
	int counter,amount;
	counter=amount=0;
	for(int i=0;i<n;counter++)
		for(int j=0;j<k && i<n;j++,i++)
			amount+=arr[i]*(counter+1);
	printf("%d\n",amount);
	delete(arr);
	return 0;
}
