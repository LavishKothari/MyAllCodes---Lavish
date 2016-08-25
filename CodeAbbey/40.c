#include<stdio.h>
#include<stdlib.h>
int findAnswer(int**a,int m,int n)
{
	int T[m][n],x,y,i,j;
	T[0][0]=1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{	
			if(a[i][j]==0)
			{
				T[i][j]=0;
				continue;
			}
			if(i==0 && j==0)
				continue;
			x=0;y=0;
			if(j-1>=0) x=T[i][j-1];
			if(i-1>=0) y=T[i-1][j];
			T[i][j]=x+y;
		
		}
	}
	return T[m-1][n-1];
}
int main()
{
	int m,n;char temp;
	int **a,i,j;
	scanf("%d%d",&m,&n);
	a=(int**)malloc(sizeof(int*)*m);
	for(i=0;i<m;i++)
		a[i]=(int*)malloc(sizeof(int)*n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			scanf(" %c",&temp);
			if(temp=='+' || temp=='@' || temp=='$')
				a[i][j]=1;
			else a[i][j]=0;
		}
	printf("%d\n",findAnswer(a,m,n));
	return 0;
}
