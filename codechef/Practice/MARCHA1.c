#include<stdio.h>

int arr[21],n,m;
void dp()
{
	int i,j;
	int T[n+1][m+1];
	for(j=0;j<=m;j++)
		T[0][j]=0;
	for(i=0;i<=n;i++)
		T[i][0]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			T[i][j]=T[i-1][j];
			if(j-arr[i-1] >=0)
				T[i][j]=(T[i][j] | T[i-1][j-arr[i-1]]);
		}
	if(T[n][m])
		printf("Yes\n");
	else printf("No\n");
}
int main()
{
	int t,i;scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		dp();
	}
	return 0;
}
