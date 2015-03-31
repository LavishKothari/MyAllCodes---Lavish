#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int answer;
	int i,n,*arr,j,max=0,temp,a;
	scanf("%d",&n);
	arr=(int*)calloc(1000001,sizeof(int));
	
	/*
	for(i=0;i<=1000001;i++)
		arr[i]=0;
	*/
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(max<temp)
			max=temp;
		arr[temp]++;
	}
	
	answer=((long long int)n*(n-1))/2;
	for(i=1;i<=max;i++)
	{
		a=arr[i];
		if(a!=0 && a!=1)
			answer=answer-((long long int)a*(a-1))/2;
	}
	printf("%lld",answer);
	return 0;
}
