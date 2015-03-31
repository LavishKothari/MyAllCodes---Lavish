#include<stdio.h>
#include"Graph_AdjacencyList.h"
int main()
{
	struct Graph_AdjacencyList*graph;
	int a,b,weight,isDirected,i,numberOfVertices,numberOfEdges;

	printf("Enter the number of Vertices in the Graph : ");
	scanf("%d",&(numberOfVertices));
	printf("Enter the number of Edges in the Graph : ");
	scanf("%d",&(numberOfEdges));

	graph=makeAndInitialiseGraph();

	for(i=0;i<numberOfVertices;i++)
		addVertex(graph,makeVertex());

	printf("NOTE 1 : The ordering of the Vertices and Edges is zero indexed.\n");
	printf("NOTE 2 : For each edge enter the following in Sequence : \n");
	printf("\t1. Source Vertex Number.\n");
	printf("\t2. Destination Vertex Number.\n");
	
	for(i=0;i<numberOfEdges;i++)
	{
		printf("Enter the edge Number %d : ",i+1);
		scanf("%d%d",&a,&b);
		addEdge(graph,a,b);
	}
	printGraph_AdjacencyList(graph);
	printf("Program Execution Successful...\n");
	return 0;
}
