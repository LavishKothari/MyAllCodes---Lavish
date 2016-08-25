#include<stdio.h>
#include<stdlib.h>
void heapifytop(int*arr,int start,int last)
{
	int lchild,rchild,temp,min;
	lchild=start*2+1;
	rchild=start*2+2;
	
	min=start;
	if(lchild<=last && arr[lchild]<arr[min])
		min=lchild;
	if(rchild<=last && arr[rchild]<arr[min])
		min=rchild;
	if(min!=start)
	{
		temp=arr[start];
		arr[start]=arr[min];
		arr[min]=temp;
		
		heapifytop(arr,min,last);
	}
}

void heapifybottom(int *arr,int start,int last)
{
	int parent=(start-1)/2,temp;
	if(parent>=0 && arr[parent]>arr[start])
	{
		temp=arr[parent];
		arr[parent]=arr[start];
		arr[start]=temp;
		
		heapifybottom(arr,parent,last);
	}
}

int main()
{
	int n,t,*arr,i,temp;
	scanf("%d",&t);
	arr=(int*)malloc(sizeof(int)*t);
	n=0;
	while(t--)
	{
		scanf("%d",&temp);
		if(temp!=0)
		{
			arr[n++]=temp;
			heapifybottom(arr,n-1,n-1);
		}
		else 
		{
			temp=arr[n-1];
			arr[n-1]=arr[0];
			arr[0]=temp;
			
			n--;
			heapifytop(arr,0,n-1);
		}
		
	}
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
