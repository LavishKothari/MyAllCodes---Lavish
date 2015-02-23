#include<stdio.h>
#include<stdlib.h>
int numberOfZero(int*arr,int n)
{
	int i,counter=0;
	for(i=0;i<n;i++)
		if(arr[i]==0)
			counter++;;
	return counter;
}
void printArray(int*arr,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
int  main()
{
	int n,k,i,*arr,counter;
	scanf("%d%d",&n,&k);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		arr[i]=0;

	for(i=0,--k;numberOfZero(arr,n)!=1;)
	{
		for(counter=0;counter!=k;i=(i+1)%n)
			if(arr[i]==0)
				counter++;
		while(arr[i]==1)
			i=(i+1)%n;
		arr[i]=1;
	}
	for(i=0;i<n;i++)
		if(arr[i]==0)
			break;
	printf("%d",i+1);
	return 0;
}
