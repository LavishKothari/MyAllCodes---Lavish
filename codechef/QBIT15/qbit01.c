#include<stdio.h>
#include<malloc.h>
int cmp(const void*a,const void*b)
{
	return *(int*)b-*(int*)a;
}
int main()
{
	int t,*arr,n,i,sum,suma;
	scanf("%d",&t);
	while(t--)
	{
		suma=sum=0;
		scanf("%d",&n);
		arr=(int *)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		qsort(arr,n,sizeof(int),cmp);
		i=0;
		while(1)
		{
			suma+=arr[i];
			sum-=arr[i];
			//printf("%d %d\n",suma,sum);
			if(suma>sum)
				break;
			i++;
		}
		printf("%d\n",i+1);
	}
	return 0;
}
