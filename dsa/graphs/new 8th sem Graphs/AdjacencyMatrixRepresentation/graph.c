#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
#include"matrix.h"
#include"queue.h"
#include"vertex.h"
struct Graph*makeNewGraph()
{
	struct Graph*g;
	g=(struct Graph*)malloc(sizeof(struct Graph));
	return g;
}
void initializeAdjacencyMatrix(struct Graph*g)
{
	/*
		The adjacencyMatrix corresponding to vertex u and v will contain 1 if there is an edge from u to v
		otherwise it will contain 0

		Description of data structure used for making adjacencyMatrix:
			* We will need n*n bits to represent the existence of an edge between two vertices
			* These n*n bits should be assumed to be arranged in the linear fashion
			* For implementing this linear fashion we will use an array of integers.
			* For a standard 32 bit compiler (like gcc 4.8.2) size of an integer is 32 bits (4 bytes).
			* By this linear arrangement of AdjacencyMatrix we will optimally exploit every single bit.
	*/
	int sizeOfIntegerColumns,i,j;
	sizeOfIntegerColumns=((g->numberOfVertices)*(g->numberOfVertices))/32+1;
	(g->adjacencyMatrix)=(unsigned int*)malloc(sizeof(unsigned int)*sizeOfIntegerColumns);
	for(i=0;i<sizeOfIntegerColumns;i++)
		(g->adjacencyMatrix)[i]=0;
}
void createEdge(struct Graph*g,int a,int b)
{
	setMatrix_i_j(a,b,g->adjacencyMatrix,g->numberOfVertices);
}
void removeEdge(struct Graph*g,int a,int b)
{
	resetMatrix_i_j(a,b,g->adjacencyMatrix,g->numberOfVertices);
}
void showAdjacencyMatrix(struct Graph*g)
{
	int i,j,bitNumber;
	printf("The adjacency Matrix of the Graph is as follows : \n");
	for(i=0;i<(g->numberOfVertices);i++)
	{
		for(j=0;j<(g->numberOfVertices);j++)
			printf("%d",getMatrix_i_j(i,j,g->adjacencyMatrix,g->numberOfVertices));
		printf("\n");
	}
}
void BFS(struct Graph*g,int startingVertexNumber)
{
	/* BREADTH FIRST SEARCH */
	struct Queue*queue;
	const int MAX_INT=2147483647;
	int i,currentVertexNumber;
	struct Vertex*vertexArray;
	vertexArray=(struct Vertex*)malloc(sizeof(struct Vertex)*(g->numberOfVertices));
	for(i=0;i<(g->numberOfVertices);i++)
	{
		vertexArray[i].vertexNumber=i;
		vertexArray[i].color=WHITE; // Initially every node should be of WHITE color
		vertexArray[i].distance=MAX_INT; // Initially distance of every node should be set to INFINITY
		vertexArray[i].parentVertexNumber=-1; // Initially every node has undefined parent.
	}

	/* Initializing the starting vertex. */
	vertexArray[startingVertexNumber].color=GRAY;
	vertexArray[startingVertexNumber].distance=0;
	vertexArray[startingVertexNumber].parentVertexNumber=-1;

	/* Preparing an empty queue of size (g->numberOfVertices) */
	queue=(struct Queue*)makeAndInitializeQueue(g->numberOfVertices);
	enqueue(queue,startingVertexNumber); // the satrting vertex should be enqueued.
	printf("The BFS Traversal is as follows : ");
	while((queue->numberOfElements)!=0)
	{
		currentVertexNumber=dequeue(queue);
		printf("%d ",currentVertexNumber);
		for(i=0;i<(g->numberOfVertices);i++)
		{
			if(getMatrix_i_j(currentVertexNumber,i,g->adjacencyMatrix,g->numberOfVertices)==1 && vertexArray[i].color==WHITE)
			{
				vertexArray[i].color=GRAY;
				vertexArray[i].distance=vertexArray[currentVertexNumber].distance+1;
				vertexArray[i].parentVertexNumber=currentVertexNumber;
				enqueue(queue,i);
			}
		}
		vertexArray[currentVertexNumber].color=BLACK; // because every neighbour of currentVertexNumber is visited now.
	}
	freeQueue(queue);
	free(vertexArray);
}

