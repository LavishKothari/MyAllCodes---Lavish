#include<stdio.h>
int main()
{
	int t,**matrix;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&e);
		matrix=(int**)malloc(sizeof(int*)*n);
		for(i=0;i<n;i++)
			matrix[i]=(int*)malloc(sizeof(int)*n);
		for()
		for(i=0;i<e;i++)
		{
			scanf("%d%d",&s,&d);
			matrix[s-1][d-1]++;
		}
	}
	return 0;
}
