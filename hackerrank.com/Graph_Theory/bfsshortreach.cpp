#include<stdio.h>
#include<list>
#include<queue>
#include<stdlib.h>
using namespace std;
class Graph
{
	private:
		int numberOfVertices,numberOfEdges;
		list<int>*adjacencyList;
	public:
		Graph(int,int);
		void addEdge(int,int);
		void printGraph();
		int* BFS(int); // the argument specifies the starting vertex.
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
	adjacencyList[d].push_back(s);
}
void Graph::printGraph()
{
	printf("Printing the Graph : \n");
	for(int i=0;i<this->numberOfVertices;i++)
	{
		printf("%d : ",i);
		for(list<int>::iterator j=adjacencyList[i].begin();j!=adjacencyList[i].end();j++)
		{
			printf("%d, ",(*j));
		}
		printf("\n");
	}
}
int* Graph::BFS(int start)
{
	int*distance;
	int*color;
	color=(int*)malloc(sizeof(int)*numberOfVertices);
	distance=(int*)malloc(sizeof(int)*numberOfVertices);
	/*
	   color specification 

	   0 = white
	   1 = gray
	   2 = black
	 */
	for(int i=0;i<numberOfVertices;i++)
	{
		distance[i]=-1;
		color[i]=0;
	}
	color[start]=1;
	distance[start]=0;

	queue<int>Q;
	Q.push(start);
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		for(list<int>::iterator i=adjacencyList[u].begin();i!=adjacencyList[u].end();i++)
		{
			int v=(*i);
			if(color[v]==0)
			{
				color[v]=1;
				distance[v]=distance[u]+1;
				Q.push(v);
			}
		}
		color[u]=2; // this sigifies that all the adjacent vertices of u are visited.
	}

	free(color);
	return distance;
}
int main()
{
	int t,n,e,s,d,start;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&e);
		Graph graph(n,e);
		for(int i=0;i<e;i++)
		{
			scanf("%d%d",&s,&d);
			graph.addEdge(s-1,d-1);
		}
		//graph.printGraph();
		scanf("%d",&start);
		int*distance=graph.BFS(start-1);
		for(int i=0;i<n;i++)
			if(i!=start-1)
			{
				if(distance[i]!=-1)
					printf("%d ",distance[i]*6);
				else printf("-1 ");
			}
		printf("\n");
		free(distance);
	}
	return 0;
}
