#include<stdio.h>
#include<list>
#include<stack>
using namespace std;
stack<int>myStack;
class Graph
{
	private:
		int numberOfVertices,numberOfEdges;
		list<int>*adjacencyList;
	public:
		Graph(int,int);
		void addEdge(int,int );
		void printGraph();
		void DFS(int);
		int DFSVisit(int ,int ,int ,bool*);
		Graph transpose();
};

Graph::Graph(int numberOfVertices,int numberOfEdges)
{
	this->numberOfVertices=numberOfVertices;
	this->numberOfEdges=numberOfEdges;
	adjacencyList=new list<int>[numberOfVertices];
}
void Graph::addEdge(int s,int d)
{
	adjacencyList[s].push_back(d);
}
void Graph::printGraph()
{
	printf("Printing the Graph : \n");
	for(int i=0;i<numberOfVertices;i++)
	{
		printf("%d : ",i);
		for(std::list<int>::iterator j=adjacencyList[i].begin();j!=adjacencyList[i].end();j++)
			printf("%d, ",(*j));
		printf("\n");
	}
}
int Graph::DFSVisit(int u,int time,int flag,bool*visited)
{
	if(flag==1)
		printf("%d ",u);
	time++;
	visited[u]=true;
	for(std::list<int>::iterator i=adjacencyList[u].begin();i!=adjacencyList[u].end();i++)
	{
		int v=(*i);
		if(visited[v]==false)
			time=DFSVisit(v,time,flag,visited);
	}
	if(flag==0)
		myStack.push(u);
	time++;
	return time;
}
void Graph::DFS(int flag)
{
	bool *visited;
	visited=new bool[numberOfVertices];
	for(int i=0;i<numberOfVertices;i++)
		visited[i]=false;
	int time=0;
	if(flag==0)
		for(int i=0;i<numberOfVertices;i++)
		{
			if(visited[i]==false)
				time=DFSVisit(i,time,flag,visited);
		}
	else
	{
		printf("The vertices in Strongly Connected Components are : \n");
		int counter=0;
		for(int j=0;myStack.size()!=0;j++)
		{
			int i=myStack.top();
			//printf("this is  a check %d\n",i);
			myStack.pop();
			if(visited[i]==0)
			{
				printf("Component %d : ",++counter);
				time=DFSVisit(i,time,flag,visited);
				printf("\n");
			}
		}
	}
}
Graph Graph::transpose()
{
	Graph tGraph(numberOfVertices,numberOfEdges);
	for(int i=0;i<numberOfVertices;i++)
		for(std::list<int>::iterator j=adjacencyList[i].begin();j!=adjacencyList[i].end();j++)
			tGraph.addEdge(*j,i);
	return tGraph;
}

int main()
{
	FILE*fp;
	fp=fopen("test.txt","r");
	if(fp)
	{
		int n,e;
		fscanf(fp,"%d%d",&n,&e);
		Graph graph(n,e);
		for(int i=0;i<e;i++)
		{
			int s,d;
			fscanf(fp,"%d%d",&s,&d);
			graph.addEdge(s,d);
		}
		
		graph.printGraph();
		graph.DFS(0);
		Graph tGraph=graph.transpose();
		tGraph.printGraph();
		tGraph.DFS(1);
	}
	return 0;
}
