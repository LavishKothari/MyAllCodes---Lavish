#include<stdlib.h>
#include<stdio.h>
#include"GraphAdjacencyMatrix.h"

struct GraphAdjacencyMatrix * createGraph(int numberOfVertices)
{
	int i,j;
	struct GraphAdjacencyMatrix*graph;
	graph=(struct GraphAdjacencyMatrix*)malloc(sizeof(struct GraphAdjacencyMatrix));
	graph->numberOfVertices=numberOfVertices;
	graph->adjacencyMatrix=(int**)malloc(sizeof(int)*numberOfVertices);
	for(i=0;i<numberOfVertices;i++)
		(graph->adjacencyMatrix)[i]=(int*)malloc(sizeof(int)*numberOfVertices);
		
	for(i=0;i<graph->numberOfVertices;i++)
		for(j=0;j<graph->numberOfVertices;j++)
			if(i==j)
				(graph->adjacencyMatrix)[i][j]=0;
			else
				(graph->adjacencyMatrix)[i][j]=INFINITY;
	
	return graph;
}

void createEdge(struct GraphAdjacencyMatrix*graph,int sourceVertexNumber,int destinationVertexNumber,int weight)
{
	(graph->adjacencyMatrix)[sourceVertexNumber][destinationVertexNumber]=weight;
}

void printGraph(struct GraphAdjacencyMatrix*graph)
{
	int i,j;
	printf("The adjacency Matrix of the graph is : \n");
	for(i=0;i<graph->numberOfVertices;i++)
	{
		for(j=0;j<graph->numberOfVertices;j++)
			if((graph->adjacencyMatrix)[i][j]==INFINITY)
				printf("INF    ");
			else
				printf("%-6d ",graph->adjacencyMatrix[i][j]);
		printf("\n");
	}
}

void print2DMatrix(int ** matrix,int n)
{
	int i,j;
	printf("The Matrix is as follows: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(matrix[i][j]==INFINITY)
				printf("INF    ");
			else
				printf("%-6d ",matrix[i][j]);
		printf("\n");
	}	
}


int  ** findMinimumDistanceMatrix(struct GraphAdjacencyMatrix * graph)
{
	int i,j,k,** matrix;	
	
	matrix=(int**)malloc(sizeof(int*)*graph->numberOfVertices);
	for(i=0;i<graph->numberOfVertices;i++)
		matrix[i]=(int*)malloc(sizeof(int)*graph->numberOfVertices);

	for(i=0;i<graph->numberOfVertices;i++)
		for(j=0;j<graph->numberOfVertices;j++)
			matrix[i][j]=(graph->adjacencyMatrix)[i][j];
				
	for(k=0;k<graph->numberOfVertices;k++)
		for(i=0;i<graph->numberOfVertices;i++)
			for(j=0;j<graph->numberOfVertices;j++)
				if(matrix[i][k]!=INFINITY && matrix[k][j]!=INFINITY && matrix[i][j]>matrix[i][k]+matrix[k][j])
					matrix[i][j]=matrix[i][k]+matrix[k][j];
					
	return matrix;
}

int ** findReachabilityMatrix(struct GraphAdjacencyMatrix * graph)
{
	int i,j,k,** matrix;	
	
	matrix=(int**)malloc(sizeof(int*)*graph->numberOfVertices);
	for(i=0;i<graph->numberOfVertices;i++)
		matrix[i]=(int*)malloc(sizeof(int)*graph->numberOfVertices);

	for(i=0;i<graph->numberOfVertices;i++)
		for(j=0;j<graph->numberOfVertices;j++)
			if(graph->adjacencyMatrix[i][j]==INFINITY)
				matrix[i][j]=0;
			else
				matrix[i][j]=1;
			
	for(k=0;k<graph->numberOfVertices;k++)
		for(i=0;i<graph->numberOfVertices;i++)
			for(j=0;j<graph->numberOfVertices;j++)
				if(matrix[i][k]==1 && matrix[k][j]==1)
					matrix[i][j]=1;
					
	return matrix;
}
