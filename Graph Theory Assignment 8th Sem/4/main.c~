#include<stdio.h>
#include"Graph_AdjacencyList.h"
int main()
{
	struct Graph_AdjacencyList*graph;
	int a,b,weight,isDirected,i,numberOfVertices,numberOfEdges,sourceVertexNumber,destinationVertexNumber,vertexNumber;

	printf("Enter the number of Vertices in the Graph : ");
	scanf("%d",&(numberOfVertices));
	printf("Enter the number of Edges in the Graph : ");
	scanf("%d",&(numberOfEdges));

	graph=createGraph(numberOfVertices);

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
	
	/*
	// Deleting an Edge 
	printf("To Remove an Edge Enter the source and destination vertex number : ");
	scanf("%d%d",&sourceVertexNumber,&destinationVertexNumber);
	removeEdge(graph,sourceVertexNumber,destinationVertexNumber);
	printGraph_AdjacencyList(graph);
	
	// Deleting a Vertex 
	printf("To delete a vertex enter the vertex number :");
	scanf("%d",&vertexNumber);
	removeVertex(graph,vertexNumber);
	printGraph_AdjacencyList(graph);
    */
    
    printf("\nBFS : ");
    printGraph_AdjacencyList(BFS(graph,0));  
	
	printf("\nDFS : ");
    printGraph_AdjacencyList(DFS(graph,0));  
	
	printf("Program Execution Successful...\n");
	return 0;
}
