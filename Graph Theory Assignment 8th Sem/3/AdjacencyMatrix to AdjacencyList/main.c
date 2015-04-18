/*
	this is a demo main program that shows the conversion of 
	Graph in Adjacency Matrix Representation to Graph in Adjacency List Representation.
*/
#include<stdio.h>
#include"Graph_AdjacencyMatrix.h"

int main()
{
	int i,n,a,b;
	struct Graph_AdjacencyMatrix*graph_AdjacencyMatrix,*copyGraph;
	struct Graph_AdjacencyList*graph_AdjacencyList;
	graph_AdjacencyMatrix=makeNewGraph();
	printf("Enter the number of Vertices in the Graph : ");
	scanf("%d",&(graph_AdjacencyMatrix->numberOfVertices));
	printf("Enter the number of Edges in the Graph : ");
	scanf("%d",&(graph_AdjacencyMatrix->numberOfEdges));
	initializeAdjacencyMatrix(graph_AdjacencyMatrix);
	printf("NOTE : The ordering of the vertices is zero indexed.\n");
	for(i=0;i<(graph_AdjacencyMatrix->numberOfEdges);i++)
	{
		printf("Enter the edge Number %d : ",i+1);
		scanf("%d%d",&a,&b);
		createEdge_AdjacencyMatrix(graph_AdjacencyMatrix,a,b);
	}
	showAdjacencyMatrix(graph_AdjacencyMatrix);
	
	graph_AdjacencyList=convertMatrixToList(graph_AdjacencyMatrix);
	printGraph_AdjacencyList(graph_AdjacencyList);
	
	copyGraph=convertListToMatrix(graph_AdjacencyList);
	showAdjacencyMatrix(copyGraph);
	
	//printf("Number of components in the Graph = %d\n",findNumberOfComponents(graph_AdjacencyMatrix));
	printf("\nProgram execution successful...\n");
	return 0;
}
