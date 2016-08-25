#include<stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n,k,arr[100001],i,j,answer,flag[101]={0};
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
		flag[arr[i]%k]++;
	}
	if(flag[0])
		answer=1;
	else
		answer=0;
	for(i=1,j=k-1;i<=j;i++,j--)
	{
		answer+=max(flag[i],flag[j]);
	}
	printf("%d\n",answer);
	return 0;
}
