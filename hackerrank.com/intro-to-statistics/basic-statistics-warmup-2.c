#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int c(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	double std,mean;
	long long int sum=0,i;
	int n,arr[2501],flag[100001]={0},max,mode;
	scanf("%d",&n);
	max=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		flag[arr[i]]++;
		sum+=arr[i];
	}
	for(i=0;i<100001;i++)
		if(flag[i]>max)
		{
			max=flag[i];
			mode=i;
		}	
	mean=sum/(double)n;
	sum=0;
	for(i=0;i<n;i++)
		sum+=fabs(arr[i]-mean)*fabs(arr[i]-mean);
	std=sqrt(sum/(double)n);
	qsort(arr,n,sizeof(int),c);
	printf("%g\n",mean);
	if(n&1)
		printf("%d\n",arr[n/2]);
	else printf("%g\n",(arr[n/2]+arr[n/2-1])/2.0);
	printf("%d\n",mode);
	printf("%g\n",std);
}
