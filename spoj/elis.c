#include<stdio.h>

#include<stdlib.h>
int LIS(int*arr,int n)
{
	/*
		this function returns the length of Longest Increasing Subsequence
		this function also prints all the numbers in the Longest Increasing Subsequence
		this function also prints sum of all the numbers in the Longest Increasing Subsequence
	*/
	int sum;
	int *L,i,j,max,cmax;
	L=(int*)malloc(sizeof(int)*n);
	L[0]=1;
	for(i=1;i<n;i++)
	{
		max=1;
		for(j=0;j<i;j++)
			if(arr[j]<arr[i] && max<L[j]+1)
				max=L[j]+1;
		L[i]=max;
	}
	
	/* finding maximum of all the LIS values. */
	max=1;
	for(i=0;i<n;i++)
		if(L[i]>max)
			max=L[i];
	free(L);
	return max;
}

int main()
{
	int n,*arr,i;
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("%d",LIS(arr,n));
	return 0;
}
