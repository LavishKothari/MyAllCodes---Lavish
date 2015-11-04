#include<stdio.h>
#include<list>
using namespace std;
class Vertex
{
	public:
	int vertexNumber;
	list<int>adjacencyList;
};

class Edge
{
	public:
	int start,end,color;
	Edge(int,int);
};

Edge::Edge(int start,int end)
{
	this->start=start;
	this->end=end;
}
class Graph
{
	public:
	int numberOfVertices,numberOfEdges;
	Vertex* vertexArray;
	list<Edge> edgeList;
	
	Graph(int,int);
	void addEdge(int,int);
	void print();
	void deleteGraph();
	void colorEdge(Edge&);
};

Graph::Graph(int numberOfVertices,int numberOfEdges)
{
	this->numberOfVertices=numberOfVertices;
	this->numberOfEdges=numberOfEdges;
	vertexArray=new Vertex[numberOfVertices];
}
void Graph::addEdge(int start,int end)
{
	Edge*e=new Edge(start,end);
	colorEdge(*e);
	(this->edgeList).push_back(*e);
	vertexArray[start].adjacencyList.push_back(end);
	vertexArray[end].adjacencyList.push_back(start);
}
void Graph::colorEdge(Edge&e)
{
	e.color=5;
}
void Graph::print()
{
	printf("\nThe graph is as follows : \n");
	printf("\nThe number of Vertices in the Graph = %d\n",numberOfVertices);
	printf("The number of Edges in the Graph = %d\n",numberOfEdges);
	printf("\nThe adjacency List of the Graph is as follows : \n");
	for(int i=0;i<numberOfVertices;i++)
	{
		printf("%d : ",i);
		for(list<int>::iterator j=vertexArray[i].adjacencyList.begin();j!=vertexArray[i].adjacencyList.end();j++)
			printf("%d, ",(*j));
		printf("\n");
	}
	printf("\nThe edge List of the Graph is as follows : \n");
	for(list<Edge>::iterator i=edgeList.begin();i!=edgeList.end();i++)
		printf("%d --- %d Color = %d\n",(*i).start,(*i).end,(*i).color);
	printf("\n");
}
void Graph::deleteGraph()
{
	
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
		printf("Graph initialization complete\n");
		for(int i=0;i<e;i++)
		{
			int s,d;
			fscanf(fp,"%d%d",&s,&d);
			graph.addEdge(s,d);
		}
		graph.print();
		graph.deleteGraph();
	}
	else printf("There was some error in opening the file.\n");
	return 0;
}
