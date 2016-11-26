#include<bits/stdc++.h>
using namespace std;
int dist2(int a,int b,int c,int d)
{
	return (c-a)*(c-a)+(d-b)*(d-b);
}
int findRadius(vector<string>&graph,int x,int y)
{
	int n=graph.size();
	if(graph[x][y]=='*')
		return 0;
	for(int r=1;r<=n;r++)
	{
		int blocksize=r*2+1;
		for(int i=x-r;i<=x+r;i++)
		{
			if(i<0 || i>=n)
				return r-1;
			for(int j=y-r;j<=y+r;j++)
			{
				if(j<0 || j>=n)
					return r-1;
				if(dist2(i,j,x,y)<=r*r && graph[i][j]=='*')
				{
					return r-1;
				}
			}
		}
	}

	return (n-1)/2;
}
int findAnswer(vector<string>&graph)
{
	int n=graph.size();
	int maxi=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			maxi=max(maxi,findRadius(graph,i,j));
	}
	return maxi;
}

int main()
{
	int n;
	cin>>n;
	vector<string>graph(n,string(""));
	for(int i=0;i<n;i++)
		for(int i=0;i<n;i++)
		{
			char c;
			cin>>c;
			graph[i].push_back(c);
		}
	cout<<findAnswer(graph)<<endl;
	return 0;
}