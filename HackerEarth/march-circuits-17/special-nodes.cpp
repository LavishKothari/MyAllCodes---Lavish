#include<bits/stdc++.h>
using namespace std;
int BFS(int start,vector<vector<int> >&graph,vector<int>&parent)
{
	int n=graph.size();
	queue<int>q;
	q.push(start);
	vector<bool>vis(n,false);
	vis[start]=true;
	int u;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(int i=0;i<graph[u].size();i++)
		{
			int v=graph[u][i];
			if(!vis[v])
			{
				vis[v]=true;
				parent[v]=u;
				q.push(v);
			}
		}
	}
	return u;
}
void sol(vector<int>&path)
{
	int n=path.size();
	int i1,i2,length;
	if((n+1)%4==0) // 4n-1
	{
		int mid=(1+n)/2;
		i2=(mid+1+n)/2-1;
		i1=mid/2-1;
		length=mid-i1-1;
	}
	else if((n+3)%4==0) // 4n-3
	{
		int mid=(n+1)/2;
		int len=(n-1)/2;
		i1=len/2;
		i2=i1+mid;
		length=i1;
	}
	else if(n%2==0) // 2n
	{
		int len=(n-2)/2;
		i1=len/2;
		i2=n-i1-1;
		if(n%4==0)
			length=i1+1;
		else length=i1;
	}
	printf("%d\n%d %d\n",length,path[i1]+1,path[i2]+1);
}
int main() 
{
	int n;
	scanf("%d",&n);
	vector<vector<int> >graph(n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int>parent(n,-1);
	int node1=BFS(0,graph,parent);
	int node2=BFS(node1,graph,parent);
	//printf("%d %d\n",node1,node2);
	int curr=node2;
	vector<int>path;
	while(curr!=node1)
	{
		path.push_back(curr);
		curr=parent[curr];
	}
	path.push_back(node1);
	sol(path);
	int count=path.size();
	if((count+1)%4==0) // 4n-1
	{
		int mid=(1+count)/2;
	}
	return 0;
}
