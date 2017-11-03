#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
		int number,turns,dist;	
		Node(){}
		Node(int number)
		{
			this->number=number;
			dist=INT_MAX;
			turns=0;
		}
};

void dijkstras(vector<Node>&graph)
{

}
bool operator(const A&a,const B&b)
{
	if(a.turns!=b.turns)
		return a.turns<b.turns;
	return a.dir<b.dir;
}
void bfs(vector<vector<int> >&graph,int start,int end)
{
	queue<int> q;
	vector<bool>isv(graph.size(),false);
	isv[start]=true;
	q.push(start);

	set<A>s;
	s.insert(A(0,0,-1));
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		//if(!isv[u])
		{
			//isv[u]=true;
			for(int i=0;i<graph[u].size();i++)
			{
				int v=graph[u][i];
				if(!isv[v])
				{
					q.push(v);
					isv[v]=true;
				}
			}
		}
	}
}


int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<string>vs;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		vs.push_back(s);
	}
	vector<vector<int> >graph(n*m);
	vector<int>x,y;
	x.push_back(-1);
	x.push_back(0);
	x.push_back(1);
	y.push_back(-1);
	y.push_back(0);
	y.push_back(1);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(vs[i][j]=='V')
				start=i*m+j;
			if(vs[i][j]=='H')
				end=i*m+j;
			if(vs[i][j]!='*')
			{
				for(int p=0;p<3;p++)
				{
					for(int q=0;q<3;q++)
					{
						int currentx=i+x[p];
						int currenty=j+y[q];
						if(currentx==i && currenty==j) continue;
						if(x[p]!=0 && y[p]!=0) continue;
						if(currentx<n && currentx>=0 && currenty<m && currenty>=0 && vs[currentx][currenty]!='*')
							graph[i*m+j].push_back(currentx*m+currenty);
					}
				}
			}
		}
	}
	for(int i=0;i<graph.size();i++)
	{
		cout<<i<<": ";
		for(int j=0;j<graph[i].size();j++)
			cout<<graph[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
