#include<stdio.h>
#include<stdlib.h>
int *arr,n;
void find()
{
	int *dp,i,j,m;
	dp=(int*)calloc(sizeof(int),n);
	
	dp[0]=arr[0];
	dp[1]=0;
	dp[2]=dp[0]+arr[2];
	
	for(i=3;i<n;i++)
		dp[i]=arr[i]+(dp[i-3]>dp[i-2]?dp[i-3]:dp[i-2]);
	printf("%d ",dp[n-1]>dp[n-2]?dp[n-1]:dp[n-2]);
	free(dp);
}
void input()
{
	int counter,i,sum;
	char str[10000];
	scanf(" %[^\n]s",str);
	counter=0;
	for(i=0;str[i];i++)
		if(str[i]==' ')
			counter++;
	counter++;
	arr=(int*)malloc(sizeof(int)*counter);
	counter=0;sum=0;
	for(i=0;str[i];i++)
	{
		//printf("%c",str[i]);
		if(str[i]==' ')
		{
			arr[counter++]=sum;
			//printf("*****************%d\n",sum);
			sum=0;
		}
		else
		{
			sum=sum*10+str[i]-'0';
		}
	}
	arr[counter++]=sum;
	n=counter;
	/*
	for(i=0;i<*n;i++)
		printf("%d\n",arr[i]);
	*/
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		input();
		/*
		for(i=0;i<n;i++)
			printf("%d\n",arr[i]);
		*/
		find(arr,n);
		//free(arr);
	}
	return 0;
}
