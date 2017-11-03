#include<iostream>
#include<vector>
#include<set>
using namespace std;

bool *isvisited;
int *parent;
void DFSr(vector< set<int> > &graph,int n,int start)
{
	//cout<<start<<" ";
	for(set<int>::iterator it=graph[start].begin();it!=graph[start].end();it++)
	{
		int v=*it;
		if(!isvisited[v])
		{
			isvisited[v]=1;
			parent[v]=start;
			DFSr(graph,n,v);
		}	
	}

}
/*
   void DFS(vector< set<int> > &graph,int n)
   {
   vector<int>s;
   bool *isvisited=new bool[n];
   int *parent=new int[n];

   s.push_back(0);
   parent[0]=-1;
   isvisited[0]=1;

   while(!s.empty())
   {
   int u=*(s.end()-1);
   s.erase(s.end()-1);

   for(set<int>::iterator it=graph[u].begin();it!=graph[u].end();it++)
   {
   int v=*it;
   if(!isvisited[v])
   {
   s.push_back(v);
   isvisited[v]=1;
   parent[v]=u;
   }	
   }
   }
   for(int i=0;i<n;i++)
   cout<<parent[i]<<" ";

   delete parent;
   delete isvisited;
   }
 */
int main()
{
	int n,e;
	cin>>n>>e;

	vector< set<int> >graph(n);

	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		graph[a].insert(b);
		graph[b].insert(a);
	}
	isvisited=new bool[n];
	parent=new int[n];

	for(int i=0;i<n;i++)
		isvisited[i]=false;

	parent[0]=-1;
	isvisited[0]=1;

	DFSr(graph,n,0);

	for(int i=0;i<n;i++)
		cout<<parent[i]<<" ";
	return 0;
}                                        
