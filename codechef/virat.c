#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int pro=1;
	int n,*arr,numberOfNegative=0,i,allPosetive=1,min=100,maxNegative=-100,oneZero=0,oneNonZero=0;
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if(min>arr[i])
			min=arr[i];
		if(maxNegative<arr[i] && arr[i]<0)
			maxNegative=arr[i];
		if(arr[i]<0)
		{
			numberOfNegative++;
			allPosetive=0;
		}
		if(arr[i]==0)
			oneZero=1;
		else
			oneNonZero=1;
		if(arr[i]!=0)
			pro*=arr[i];
	}
	if(oneNonZero==0)
		printf("0");
	else if(allPosetive==1)
		printf("%d",min);
	else if(numberOfNegative%2==0)
		printf("%lld",pro/maxNegative);
	else 
		printf("%lld",pro);
	return 0;
}
