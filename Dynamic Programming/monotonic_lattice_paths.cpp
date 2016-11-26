#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll findMonotonicLatticePaths(int n)
{
	// simple formula is Catalan number 
	// 2nCn / (n+1)
	ll**table;
	table=new ll*[n+1];
	for(int i=0;i<=n;i++)
		table[i]=new ll[n+1];
	// table[i][j] denotes the number of shortest paths to reach (0,n) from (n,0)
	table[n][0]=0;
	table[n][1]=1;
	
	for(int j=1;j<=n;j++)
	{
		table[n][j]=1; // base case
		for(int i=n-1;i+j>=n;i--)
		{
			int x=0,y=0;
			if(j-1>=0 && i+j-1>=n)
				x=table[i][j-1];
			if(i+1<=n && i+1+j>=n)
				y=table[i+1][j];
			table[i][j]=x+y;
		}
	}
	return table[0][n];
}

int main()
{
	int n;
	cin>>n;
	cout<<findMonotonicLatticePaths(n)<<endl;
}