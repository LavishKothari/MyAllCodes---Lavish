#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int index,data;
};
int cm(const void*a,const void*b)
{
	struct Node aa,bb;
	aa=*(struct Node*)a;
	bb=*(struct Node*)b;
	return aa.data-bb.data;
}
int findMax(int*arr,struct Node*nodeArray,int a,int b,int n)
{
	int i;
	if(a==b)
		return arr[a];
	for(i=n-1;i>=0;i--)
	{
		if(nodeArray[i].index>=a && nodeArray[i].index<=b)
			return nodeArray[i].data;
	}
	return 0;
}
int main()
{
	long long int answer;
	struct Node*nodeArray;
	int n,*arr,m,max,j,y,x,i,a,b,k;
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	nodeArray=(struct Node*)malloc(sizeof(struct Node)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		nodeArray[i].data=arr[i];
		nodeArray[i].index=i;		
	}
	qsort(nodeArray,n,sizeof(struct Node),cm);
	scanf("%d%d%d",&m,&x,&y);
	answer=0;
	for(i=0;i<m;i++)
	{
		a=x<y?x:y;
		b=x>y?x:y;
		//printf("x=%d y=%d        a=%d b=%d\n",x,y,a,b);
		//printf("%d\n",findMax(arr,nodeArray,a,b,n));
		answer+=findMax(arr,nodeArray,a,b,n);
		x=(x+7)%(n-1);
		y=(y+11)%(n);
	}
	printf("%lld\n",answer);
	return 0;
}
