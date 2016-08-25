#include<stdio.h>
#include<stdlib.h>

#define MAX 65536

void findAnswer(int *arr,int n)
{
	int i,stack[n],flag,top=-1,nge[MAX];
	for(i=0;i<n;i++)
	{
		if(top==-1)
		{
			stack[++top]=arr[i];
			continue;
		}
		flag=0;
		while(top>=0 && arr[i]>stack[top])
		{
			flag=1;
			nge[stack[top]]=arr[i];
			top--;
		}
		
		if(flag==1)
		{
			stack[++top]=arr[i];
			continue;
		}
		if(arr[i]<=stack[top])
			stack[++top]=arr[i];
	}
	while(top!=-1)
	{
		nge[stack[top]]=-1;
		top--;
	}
	for(i=0;i<n;i++)
		printf("%d %d\n",arr[i],nge[arr[i]]);
}
int main()
{
	int i;
	int n,*arr;scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	findAnswer(arr,n);
	return 0;
}
