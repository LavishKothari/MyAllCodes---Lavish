#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,m,c,i,j,num,**mat;
	scanf("%d%d%d",&n,&m,&c);
	
	mat=(int**)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		mat[i]=(int*)malloc(sizeof(int)*m);
		
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			mat[i][j]=25;
	
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			printf("1 %d %d %d %d 1 10\n",i,i,j,j);
			fflush(stdout);
			scanf("%d",&num);
			if(num==1)
				mat[i][j]=5;
		}
	printf("3\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
	return 0;
}
