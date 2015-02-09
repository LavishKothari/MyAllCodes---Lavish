#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int max_ending_here,max_so_far;
	int *arr,x,n,t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		arr=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			arr[i]-=x;
		}
		max_so_far=0;
		max_ending_here=0;
		for(i=0;i<n;i++)
		{
			max_ending_here=max_ending_here+arr[i];
			if(max_ending_here<0)
				max_ending_here=0;
			if(max_so_far<max_ending_here)
				max_so_far=max_ending_here;
		}
		printf("%lld\n",max_so_far);
	}
	return 0;
}
