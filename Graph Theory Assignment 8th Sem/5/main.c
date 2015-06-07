#include<stdio.h>
#include<stdlib.h>
#include"GraphAdjacencyMatrix.h"

int main()
{
	int s,d,w,i,numberOfVertices,numberOfEdges;
	struct GraphAdjacencyMatrix *graph;
	printf("Enter the number of vertices : ");
	scanf("%d",&numberOfVertices);
	graph=createGraph(numberOfVertices);
	printf("Enter the number of edges : ");
	scanf("%d",&numberOfEdges);
	printf("Enter the source desination and weight for each edge : \n");
	for(i=0;i<numberOfEdges;i++)
	{
		scanf("%d%d%d",&s,&d,&w);
		createEdge(graph,s,d,w);
	}
	printGraph(graph);
	
	print2DMatrix(findMinimumDistanceMatrix(graph),numberOfVertices);
	
	print2DMatrix(findReachabilityMatrix(graph),numberOfVertices);

	return 0;
}
