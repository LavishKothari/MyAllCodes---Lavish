#include<stdlib.h>
#include<stdio.h>
#define MOD 1000000007
long long int s(int newArray[], int n, int i)
{
   	long long int sum=0;
    i++;
 	while(i>0)
    {
        sum=(sum+newArray[i])%MOD;
 		i-=i&(-i);
    }
    return sum;
}
void uForSum(long long int*newArray,int n,int i,int value)
{
	i++;
	while(i<=n)
	{
		newArray[i]=(newArray[i]+value)%MOD;
       	i+=i&(-i);
	}
}
void uForMul(long long int*newArray,int n,int i,int value)
{
	i++;
	while(i<=n)
	{
		newArray[i]=(newArray[i]*value)%MOD;
       	i+=i&(-i);
	}
}
void u(long long int*newArray,int n,int i,int value)
{
	i++;
	while(i<=n)
	{
		newArray[i]=value;
       	i+=i&(-i);
	}
}

long long int *initializeForSum(long long int*arr,int n)
{
	long long int*newArray;
	newArray=(long long int*)malloc(sizeof(long long int)*(n+1));
	for(i=0;i<=n;i++)
		newArray[i]=0;
	for(i=0;i<n;i++)
		uForSum(newArray,n,i,arr[i]);
	return newArray;
}
long long int *initializeForMul(long long int*arr,int n)
{
	long long int*newArray;
	newArray=(long long int*)malloc(sizeof(long long int)*(n+1));
	for(i=0;i<=n;i++)
		newArray[i]=1;
	for(i=0;i<n;i++)
		uForMul(newArray,n,i,arr[i]);
	return newArray;
}
int main()
{
	int n,q,i,type,x,y,v;
	long long int*arr,sum;
	scanf("%d%d",&n,&q);
	arr=(long long int*)malloc(sizeof(long long int)*n);
	
	for(i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	sumArray=initializeForSum(arr,n);
	mulArray=initializeForMul(arr,n);
	while(q--)
	{
		scanf("%d",&type);
		switch(type)
		{
			case 1:
			{
				scanf("%d%d%d",&x,&y,&v);
				x--;
				y--;
				uForSum(sumArray,n,)
				/*
				for (i = x; i <= y; i++)	
					arr[i]=(arr[i]+v)%MOD;
				*/
				break;
			}
			case 2:
			{
				scanf("%d%d%d",&x,&y,&v);
				x--;
				y--;
				for (i = x; i <= y; i++)	
					arr[i]=(arr[i]*v)%MOD;
				break;
			}
			case 3:
			{
				scanf("%d%d%d",&x,&y,&v);
				x--;
				y--;
				for (i = x; i <= y; i++)	
					arr[i]=v;
				break;
			}
			case 4:
			{
				scanf("%d%d",&x,&y);
				x--;
				y--;
				sum=0;
				for (i = x; i <= y; i++)	
					sum=(sum+arr[i])%MOD;
				printf("%lld",sum);
				break;
			}
		}
	}
	return 0;
}
