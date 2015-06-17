
#include<stdlib.h>
#include<stdio.h>
struct polygon
{
	int number,answer;
	long long int max;
};
int cf1(const void*x,const void*y)
{
	long long int a,b;
	a=(*(struct polygon*)x).max;
	b=(*(struct polygon*)y).max;
	
	return a-b;
}
int cf2(const void*x,const void*y)
{
	int a,b;
	a=(*(struct polygon*)x).number;
	b=(*(struct polygon*)y).number;
	
	return a-b;
}
int main()
{
	int t,n,m,i,j;
	struct polygon*pArray;
	long long int x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		pArray=(struct polygon*)malloc(sizeof(struct polygon)*n);
		for(i=0;i<n;i++)
		{
			pArray[i].number=i;
			scanf("%d",&m);
			pArray[i].max=-1000000000;
			for(j=0;j<m;j++)
			{
				scanf("%lld%lld",&x,&y);
				if(x>pArray[i].max)
					pArray[i].max=x;
			}
		}
		qsort(pArray,n,sizeof(struct polygon),cf1);
		for(i=0;i<n;i++)
			pArray[i].answer=i;
		qsort(pArray,n,sizeof(struct polygon),cf2);
		for(i=0;i<n;i++)
			printf("%d ",pArray[i].answer);
		printf("\n");
		free(pArray);
	}
	return 0;
}
