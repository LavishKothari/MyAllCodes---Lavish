#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n;
		scanf("%d%d",&n,&m);
		int*last=(int*)malloc(sizeof(int)*n);
		for(int i=0;i<n;i++)
			last[i]=m-1;
		int*first=(int*)malloc(sizeof(int)*n);
		for(int i=0;i<n;i++)
			first[i]=0;
		int**arr=(int**)malloc(sizeof(int*)*n);
		for(int i=0;i<n;i++)
			arr[i]=(int*)malloc(sizeof(int)*m);
		long long int**val=(long long int**)malloc(sizeof(long long int*)*n);
		for(int i=0;i<n;i++)
			val[i]=(long long int*)malloc(sizeof(long long int)*m);
		for(int i=0;i<n;i++)
		{
			bool flag=true;
		
			for(int j=0;j<m;j++)
			{
				scanf("%d",&arr[i][j]);
				if(arr[i][j]<0)
					last[i]=j;
				if(flag && arr[i][j]<0)
				{
					first[i]=j;
					flag=false;
				}
			}
		}
		int min=1<<30;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				
				long long int value=0;
				long long int maxim1=1<<30;
				for(int k=j;k<=last[i];k++) // move right
				{
					value+=arr[i][k];
					if(value<maxim1)
						maxim1=value;
				}
				value=0;
				long long int maxim2=1<<30;
				for(int k=j;k>=first[i];k--) // move left
				{
					value+=arr[i][k];
					if(value<maxim2)
						maxim2=value;
				}
				value=0;
				long long int maxim3=1<<30;
				for(int k=i;k<n;k++) // move down
				{
					value+=arr[k][j];
					if(value<maxim3)
						maxim3=value;
				}
				value=0;
				long long int maxim4=1<<30;
				for(int k=i;k>=0;k--) // move up
				{
					value+=arr[k][j];
					if(value<maxim4)
						maxim4=value;
				}
				val[i][j]=maxim1+maxim2+maxim3+maxim4-3*arr[i][j];
				if(min>val[i][j])
					min=val[i][j];
			}
		}
				
		printf("%d\n",min);
	}
	return 0;
}
