#include<stdio.h>

int main()
{
	int t,arr[500][500],i,j,m,n,sum,counter;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&arr[i][j]);
		counter=1;	
		if(n==m && n==1)
		{
			printf("%d\n",arr[0][0]);
			continue;
		}
		if(n==1)
		{
			for(i=0;i<m;i++)
				printf("%d ",arr[0][i]);
			printf("\n");
			continue;
		}
		if(m==1)
		{
			for(i=0;i<n;i++)
				printf("%d ",arr[i][0]);
			printf("\n");
			continue;
		}
		for(sum=0;sum<m*n-1;sum++)
		{
			if(sum<m)
				i=0;
			else
			{
				i=counter;
				counter++;
			}
			for(;i<=sum;i++)
			{
				j=sum-i;
				if(i<n && j<m)
					printf("%d ",arr[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
