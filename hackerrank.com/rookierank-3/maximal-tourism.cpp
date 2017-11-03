#include<bits/stdc++.h>
using namespace std;
int dfs(int start,vector<vector<int> >&graph,vector<bool>&isVisited)
{	
	stack<int> s;
	s.push(start);
	isVisited[start]=true;
	int count=0;
	while(!s.empty())
	{
		int u=s.top();
		count++;
		s.pop();
		for(int i=0;i<graph[u].size();i++)
		{
			int v=graph[u][i];
			if(!isVisited[v])
				s.push(v);
			isVisited[v]=true;
		}
	}
	return count;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> >graph(n,vector<int>());
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<bool>isVisited(n,false);
	int answer=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(!isVisited[i])
		{
			answer=max(answer,dfs(i,graph,isVisited));
		}
	}
	cout<<answer<<endl;
	return 0;
}
