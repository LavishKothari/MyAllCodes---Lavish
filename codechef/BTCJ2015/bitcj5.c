#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmpfunc(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int t,*arr,min,count,mincount,k,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		arr=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		qsort(arr,n,sizeof(int),cmpfunc);
		count=1;
		min=1001;
		for(i=1;i<n;i++)
		{
			if(arr[i]==arr[i-1])
				count++;
			else
			{
				if(abs(count-k)<min)
				{
					min=abs(count-k);
					mincount=count;
				}
				count=1;
			}
		}
		if(min==1001 && n!=k)
			printf("%d\n",k);
		else if(min==1001 && n==k)
			printf("0\n");
		else
			printf("%d\n",min);
		free(arr);
	}
	return 0;
}

