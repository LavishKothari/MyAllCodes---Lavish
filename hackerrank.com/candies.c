#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
long long int findAnswer(int *arr,int n)
{
	long long int a;
	long long int i,answer[n+1];
	if(n==1)
		return 1;
	
	answer[0]=0;
	if(arr[0]>arr[1])
		answer[1]=2;
	else answer[1]=1;
	
	for(i=1;i<n;i++)
	{
		if(arr[i]>arr[i-1])
			answer[i+1]=answer[i]+1;
		else
		{
			if(i!=n-1)
			{
				if(arr[i+1]>=arr[i])
					answer[i+1]=1;
				else 
					answer[i+1]=2;
			}
			else answer[i+1]=1;
		}
	}
	a=0;
	
	
	for(i=1;i<=n;i++)
	{
		printf("%lld ",answer[i]);
		a+=answer[i];
	}
	printf("\n");
	return a;
}
ll findAnswer(int *arr,int n)
{
	long long int a;
	long long int i,answer[n+1];
	answer[0]=0;
	for(i=1;i<=n;i++)
		answer[i]=1;
	for(i=0;i<n;i++)
	{
		ci=i+1;
		flag=0;
		while(arr[ci]>arr[i])
		{
			flag=1;
			ci++;
		}
		if(flag==1)
		{
			x=1;
			for(j=i;j<ci;i++)
			{
				answer[j]=x;
				x++;
			}
		}
		if(flag==0)
		{
			ci=i+1;
			flag=0;
			while(arr[ci]<arr[i])
			{
				flag=1;
				ci++;
			}
			if(flag==1)
			{
				x=ci-i;
				for(j=i;j<ci;i++)
				{
					answer[j]=x;
					x--;
				}
			}
			else
			{
				
			}
		}
		
	}
}

int main()
{
    int i,n,*arr;
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
	printf("%lld\n",findAnswer(arr,n));
	return 0;
}
