#include<stdio.h>
#include<cstring>
#include<vector>
#include<stdlib.h>
#include<stack>
using namespace std;
stack<int>newStack;
struct Vertex
{
	vector<int>adjacencyList;
	int color,startTime,finishTime,parent;
};
struct Graph
{
	int numberOfVertices,numberOfEdges;
	struct Vertex*vertexArray;
};

struct Graph*initialiseGraph(int n,int e)
{
	int i;
	struct Graph*graph;
	graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->numberOfVertices=n;
	graph->numberOfEdges=e;
	graph->vertexArray=(struct Vertex*)malloc(sizeof(struct Vertex)*n);
	for(i=0;i<n;i++)
	{
		printf("till here you are doing everything right %d\n",i);
		struct Vertex *vertex;
		vertex=(struct Vertex*)malloc(sizeof(struct Vertex));
		//std::memcpy(&((graph->vertexArray)[i]),vertex,sizeof(struct Vertex));
		(graph->vertexArray)[i]=*vertex;
		
		(graph->vertexArray)[i].color=0;
		(graph->vertexArray)[i].startTime=-1;
		(graph->vertexArray)[i].finishTime=-1;
		(graph->vertexArray)[i].parent=-1;
		printf("this is the final check of size : %d\n",(graph->vertexArray)[i].adjacencyList.size());
		
		//printf("this is size of zero = %d %d\n",i,(graph->vertexArray)[i].adjacencyList.size());
	}
	printf("Graph successfully Initialized...\n");
	return graph;
}
void addEdge(struct Graph*graph,int s,int d)
{
	printf("Adding edge : %d %d\n",s,d);
	if(s<(graph->numberOfVertices) && d<(graph->numberOfVertices))
	{
		printf("helllo lavish kothari\n");
		printf("finally = %d %d = %d\n",s,d,(graph->vertexArray)[s].adjacencyList.size());
		(((graph->vertexArray)[s]).adjacencyList).push_back(d);
		printf("after finally\n");
	}
}
void printGraph(struct Graph*graph)
{
	int i,j;
	printf("\nPrinting the graph : \n");
	for(i=0;i<(graph->numberOfVertices);i++)
	{
		printf("%d : ",i);
		for(j=0;j<(graph->vertexArray)[i].adjacencyList.size();j++)
			printf("%d ",(graph->vertexArray)[i].adjacencyList[j]);
		printf("\n");
	}
}
int dfsVisit(struct Graph*graph,int u,int time,int flag)
{
	int i,v;
	printf("%d ",u);
	time++;
	(graph->vertexArray)[u].startTime=time;
	(graph->vertexArray)[u].color=1;
	for(i=0;i<(graph->vertexArray)[u].adjacencyList.size();i++)
	{
		v=(graph->vertexArray)[u].adjacencyList[i];
		if((graph->vertexArray)[v].color==0)
		{
			(graph->vertexArray)[v].parent=u;
			dfsVisit(graph,v,time,flag);
		}
	}
	/* the uth vertex is now finished */
	if(flag==0)
		newStack.push(u);
	(graph->vertexArray)[u].color=2;
	time++;
	(graph->vertexArray)[u].finishTime=time;
	return time;
}
void dfs(struct Graph*graph,int flag)
{
	int i,time,j;
	for(i=0;i<(graph->numberOfVertices);i++)
	{
		(graph->vertexArray)[i].color=0;
		(graph->vertexArray)[i].startTime=-1;
		(graph->vertexArray)[i].finishTime=-1;
		(graph->vertexArray)[i].parent=-1;
	}
	time=0;
	if(flag==0)
		for(i=0;i<(graph->numberOfVertices);i++)
		{
			if((graph->vertexArray)[i].color==0)
				time=dfsVisit(graph,i,time,flag);
		}
	else
		for(j=0;newStack.size()!=0;j++)
		{
			//printf("this is the stack size = %d\n",newStack.size());
			i=newStack.top();
			newStack.pop();
			if((graph->vertexArray)[i].color==0)
			{
				printf("\n");
				time=dfsVisit(graph,i,time,flag);
			}
		}
}
struct Graph*transpose(struct Graph*graph)
{
	int i,j;
	struct Graph*newGraph;
	newGraph=initialiseGraph(graph->numberOfVertices,graph->numberOfEdges);
	for(i=0;i<(graph->numberOfVertices);i++)
	{
		for(j=0;j<(graph->vertexArray)[i].adjacencyList.size();j++)
		{
			addEdge(newGraph,(graph->vertexArray)[i].adjacencyList[j],i);
		}
	}
	return newGraph;
}
int main()
{
	struct Graph*graph,*newGraph;
	int n,e,s,d,i;
	FILE*fp;
	fp=fopen("test.txt","r");
	if(fp)
	{
		fscanf(fp,"%d%d",&n,&e);
		graph=initialiseGraph(n,e);
		for(i=0;i<e;i++)
		{
			fscanf(fp,"%d%d",&s,&d);
			addEdge(graph,s,d);
		}
		
		printGraph(graph);
		dfs(graph,0); // zero means stack is not yet filled
		
		newGraph=transpose(graph);
		printGraph(newGraph);
		printf("\nPrinting the vertices in strongly connected components : \n");
		dfs(newGraph,1); // 1 means stack is now filled and perform dfs on basis of elements in stack.
		fclose(fp);	
	}
	else printf("there was some error in opening the file\n");
	printf("\nprogram execution seccessful\n");
	return 0;
}
