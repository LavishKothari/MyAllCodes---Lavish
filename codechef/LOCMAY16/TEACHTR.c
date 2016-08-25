#include<stdio.h>
#define MAX 1001
int main()
{
	int n,mat[MAX][MAX],i,j,k,q,a,b;
	scanf("%d",&n);
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			mat[i][j]=0;
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&a,&b);
		mat[a-1][b-1]=1;
	}
	
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				mat[i][j]=(mat[i][j] || (mat[i][k] && mat[k][j]));
	/*	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
	*/
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&a,&b);
		a--;b--;
		if(mat[a][b]==1)
			printf("%d taught %d\n",a+1,b+1);
		else if(mat[b][a]==1)
			printf("%d taught %d\n",b+1,a+1);
		else printf("No idea\n");
	}
	
	return 0;
}
