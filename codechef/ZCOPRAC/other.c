#include<stdio.h>
#define MAX 200001
int mini,minj;
void findApt(int*arr,int index,int n)
{
	int min,i,j;
	min=2147483647;
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
			//printf("hey.. %d %d %d\n",i,index+j+3,arr[i]+arr[index+j+3]);
			if(min>=arr[i]+arr[index+j+3])
			{
				mini=i;
				minj=index+j+3;
				min=arr[i]+arr[index+j+3];
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
		//printf("hello lavish kothari %d\n",index);
		findApt(arr,index,n);
		printf("mini,minj = %d %d\n",mini,minj);
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
		//printf("sum = %d\n",sum);
		
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
	printf("%d\n",findAnswer(arr,n));
	return 0;
}
