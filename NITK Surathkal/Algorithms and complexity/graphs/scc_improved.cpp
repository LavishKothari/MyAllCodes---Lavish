#include<stdio.h>
#include<stack>
#include<list>
std::stack<int>myStack;
class Vertex
{
	public:
		int color,startTime,finishTime,parent;
		std::list<int>adjacencyList;
};
class Graph
{
	private:
		int numberOfVertices,numberOfEdges;
		Vertex*vertexArray;
	public:
		Graph(int,int);
		void addEdge(int,int);
		void printGraph();
		void DFS(int);
		int DFSVisit(int ,int ,int);
		Graph transpose();
};
Graph::Graph(int numberOfVertices,int numberOfEdges)
{
	this->numberOfVertices=numberOfVertices;
	this->numberOfEdges=numberOfEdges;
	vertexArray=new Vertex[numberOfVertices];
}
void Graph::addEdge(int s,int d)
{
	vertexArray[s].adjacencyList.push_back(d);
}
void Graph::printGraph()
{
	printf("Printing the Graph : \n");
	for(int i=0;i<numberOfVertices;i++)
	{
		printf("%d : ",i);
		for(std::list<int>::iterator j=vertexArray[i].adjacencyList.begin();j!=vertexArray[i].adjacencyList.end();j++)
			printf("%d, ",(*j));
		printf("\n");
	}
	printf("\n");
}

int Graph::DFSVisit(int u,int time,int flag)
{
	if(flag==1)
		printf("%d ",u);
	time++;
	vertexArray[u].startTime=time;
	vertexArray[u].color=1;
	for(std::list<int>::iterator i=vertexArray[u].adjacencyList.begin();i!=vertexArray[u].adjacencyList.end();i++)
	{
		int v=(*i);
		if(vertexArray[v].color==0)
			time=DFSVisit(v,time,flag);
	}
	if(flag==0)
		myStack.push(u);
	time++;
	vertexArray[u].finishTime=time;
	return time;
}
void Graph::DFS(int flag)
{
	int time=0;
	for(int i=0;i<numberOfVertices;i++)
		vertexArray[i].color=0;
	if(flag==0)
		for(int i=0;i<numberOfVertices;i++)
		{
			if(vertexArray[i].color==0)
				time=DFSVisit(i,time,flag);
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
			if(vertexArray[i].color==0)
			{
				printf("Component %d : ",++counter);
				time=DFSVisit(i,time,flag);
				printf("\n");
			}
		}
	}
}
Graph Graph::transpose()
{
	Graph tGraph(numberOfVertices,numberOfEdges);
	for(int i=0;i<numberOfVertices;i++)
		for(std::list<int>::iterator j=vertexArray[i].adjacencyList.begin();j!=vertexArray[i].adjacencyList.end();j++)
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
