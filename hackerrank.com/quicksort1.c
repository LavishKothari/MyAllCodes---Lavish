#include<stdio.h>
int n,arr[1001];
void print()
{
	int i,l[1001],g[1001],e[1001],counter1=0,counter2=0,counter3=0;
	
	for(i=0;i<n;i++)
	{
		if(arr[i]<arr[0])
			l[counter1++]=arr[i];
		if(arr[i]>arr[0])
			g[counter2++]=arr[i];
		if(arr[i]==arr[0])
			e[counter3++]=arr[i];
	}
	for(i=0;i<counter1;i++)
		printf("%d ",l[i]);
	for(i=0;i<counter3;i++)
		printf("%d ",e[i]);
	for(i=0;i<counter2;i++)
		printf("%d ",g[i]);
	printf("\n");		
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	print();	
}
