#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<vector<int> >F(2*m+1,vector<int>(2*m+1));
	vector<vector<int> >nG(n,vector<int>(n));
	vector<vector<int> >G(n,vector<int>(n));
	for(int i=0;i<2*m+1;i++)
		for(int j=0;j<2*m+1;j++)
			scanf("%d",&F[i][j]);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&G[i][j]);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int p=-m,x=0;p<=m;p++,x++)
				for(int q=-m,y=0;q<=m;q++,y++)
					if(i+p>=0 && i+p<n && j+q>=0 && j+q<n)
						nG[i][j]+=G[i+p][j+q]*F[x][y];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",nG[i][j]);
		printf("\n");
	}
	return 0;
}
