#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	double *arr,*narr;
	scanf("%d",&n);
	arr=(double*)malloc(sizeof(double)*n);
	narr=(double*)malloc(sizeof(double)*n);
	for(i=0;i<n;i++)
		scanf("%lf",&arr[i]);
	narr[0]=arr[0];
	narr[n-1]=arr[n-1];
	for(i=1;i<n-1;i++)
		narr[i]=(arr[i-1]+arr[i]+arr[i+1])/3.0;
	for(i=0;i<n;i++)
		printf("%.8f ",narr[i]);
	return 0;
}
