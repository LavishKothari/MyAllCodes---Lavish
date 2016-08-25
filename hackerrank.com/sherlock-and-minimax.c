#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
	return a>b?b:a;
}
int find(int a,int b,int c,int d)
{
	if(a>)
}
int find1(int a,int b,int c)
{
	if(a>=b && a<=c)
		return 0;
		
}
int cmp(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int arr[101],n,x,max,i,p,q;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	qsort(arr,n,sizeof(int),cmp);
	scanf("%d%d",&p,&q);
	max=0;
	for(i=0;i<n-1;i++)
	{
		x=find(arr[i],arr[i+1],p,q);
		if(max<x)
			max=x;
	}
	x=find1(arr[0],p,q);
	y=find1(arr[n-1],p,q);
	printf("%d\n",max);
	
	return 0;
}
