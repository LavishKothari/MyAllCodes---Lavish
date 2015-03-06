#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m,n,*a,*b,i,j,*c;
	scanf("%d%d",&m,&n);
	a=(int*)malloc(sizeof(int)*m);
	b=(int*)malloc(sizeof(int)*n);
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	c=(int*)malloc(sizeof(int*)*(m+n));
	for(i=0;i<m+n;i++)
		c[i]=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i+j]+=a[i]*b[j];
		}
	}
	for(i=0;i<m+n-1;i++)
	{
		if(i==0)
			printf("%d ",c[i]);
		else
			printf("+ %dx^%d ",c[i],i);
	}
	return 0;
}
