#include<stdio.h>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class Edge
{
	public:
		int a,b;
		Edge(int,int);
};
Edge::Edge(int a,int b)
{
	this->a=a;
	this->b=b;
}
class Graph
{
	public:
		int n,e;
		vector<Edge>edges;
		vector< list<int> >adjacencyList;
		Graph(int,int);
		void addEdge(int,int);
		void print();
		void removeEdge(int,int);
		int findAnswer();
		int countVertices(int);
};
Graph::Graph(int n,int e)
{
	this->n=n;
	this->e=e;
	for(int i=0;i<n;i++)
		adjacencyList.push_back(*(new list<int>()));
}
void Graph::addEdge(int a,int b)
{
	edges.push_back(Edge(a,b));
	adjacencyList[a].push_back(b);
	adjacencyList[b].push_back(a);
}
void Graph::print()
{
	int i=0;
	for(vector<list<int> >::iterator it=adjacencyList.begin();it!=adjacencyList.end();it++)
	{
		printf("%d : ",i+1);i++;
		for(list<int>::iterator is=(*it).begin();is!=(*it).end();is++)
			printf("%d ",(*is)+1);
		printf("\n");
	}
}
void Graph::removeEdge(int x,int y)
{
	for(vector<Edge>::iterator it=edges.begin();it!=edges.end();it++)
	{
		if((*it).a==x && (*it).b==y)
		{
			edges.erase(it);
			break;
		}
	}
	adjacencyList[x].remove(y);
	adjacencyList[y].remove(x);
}
int Graph::countVertices(int x)
{
	bool *flag=new bool[n];
	for(int i=0;i<n;i++)
		flag[i]=true;
	int answer=1;
	queue<int>q;
	q.push(x);
	flag[x]=false;
	while(!q.empty())
	{
		int y=q.front();
		q.pop();
		for(list<int>::iterator it=adjacencyList[y].begin();it!=adjacencyList[y].end();it++)
		{
			if(flag[*it])
			{
				answer++;
				q.push(*it);
				flag[*it]=false;
			}
		}
	}
	return answer;
}
int Graph::findAnswer()
{
	int answer=0;
	for(int i=0;i<e;i++)
	{
		vector<Edge>::iterator it=edges.begin();
		int start=(*it).a;
		int end=(*it).b;
		removeEdge(start,end);
		int counta=countVertices(start);
		int countb=countVertices(end);
		if(counta%2==0 && countb%2==0)
		{
			answer++;
			//printf("Deleting of (%d,%d) is successful\n",start,end);
		}
		addEdge(start,end);
	}
	return answer;
}
int main()
{
	int n,e;
	scanf("%d%d",&n,&e);
	Graph g=Graph(n,e);
	while(e--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g.addEdge(x-1,y-1);
	}
	//g.print();
	printf("%d\n",g.findAnswer());
	return 0;
}
