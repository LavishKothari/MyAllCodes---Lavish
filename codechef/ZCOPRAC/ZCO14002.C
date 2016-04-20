#include<stdio.h>
#define MAX 200001
int mini,minj;
void findApt(int*arr,int index,int n)
{
	int min,i,j;
	min=0;
	for(i=index;i<index+3;i++)
	{
		if(n-i<=3 && arr[i]<=min)
		{
			mini=i;
			minj=-1;
			min=arr[i];
			continue;
		}
		for(j=0;j<i-index+1;j++)
		{
			if(min>=arr[i]+arr[i+j+1])
			{
				mini=i;
				minj=i+j+1;
				min=arr[i]+arr[i+j+1];
			}
		}
	}
}
int findAnswer(int *arr,int n)
{
	int sum=0,index;
	if(n<=3)
		return 0;
	index=0;
	while(n-index>=3)
	{
		findApt(arr,index,n);
		if(minj!=-1)
		{
			sum=sum+arr[mini]+arr[minj];
			index=minj+1;
		}
		else
		{
			sum=sum+arr[mini];
			break;
		}
	}
	return sum;
}
int main()
{
	int n,i,arr[MAX];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	findAnswer(arr,n);
	return 0;
}
