#include<stdio.h>
#include<stdlib.h>
#include"Graph_AdjacencyMatrix.h"
#include"two_D_bit_array.h"
#include"one_D_bit_array.h"

struct Graph_AdjacencyMatrix*makeNewGraph()
{
	struct Graph_AdjacencyMatrix*g;
	g=(struct Graph_AdjacencyMatrix*)malloc(sizeof(struct Graph_AdjacencyMatrix));
	return g;
}
void initializeAdjacencyMatrix(struct Graph_AdjacencyMatrix*g)
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
void createEdge_AdjacencyMatrix(struct Graph_AdjacencyMatrix*g,int a,int b)
{
	set_two_D_bit_array(a,b,g->adjacencyMatrix,g->numberOfVertices);
}
void removeEdge_AdjacencyMatrix(struct Graph_AdjacencyMatrix*g,int a,int b)
{
	reset_two_D_bit_array(a,b,g->adjacencyMatrix,g->numberOfVertices);
}
void showAdjacencyMatrix(struct Graph_AdjacencyMatrix*g)
{
	int i,j,bitNumber;
	printf("The adjacency Matrix of the Graph is as follows : \n");
	for(i=0;i<(g->numberOfVertices);i++)
	{
		for(j=0;j<(g->numberOfVertices);j++)
			printf("%d",get_two_D_bit_array(i,j,g->adjacencyMatrix,g->numberOfVertices));
		printf("\n");
	}
}

int findNumberOfComponents(struct Graph_AdjacencyMatrix*g)
{
	/*
		first of all we need to create a copy of the AdjacencyMatrix.
	*/
	unsigned int *adjacencyMatrix_copy,*flag,sizeOfIntegerColumns,i,j,k,components;
	sizeOfIntegerColumns=((g->numberOfVertices)*(g->numberOfVertices))/32+1;
	adjacencyMatrix_copy=(unsigned int*)malloc(sizeof(unsigned int)*sizeOfIntegerColumns);
	for(i=0;i<sizeOfIntegerColumns;i++)
		adjacencyMatrix_copy[i]=(g->adjacencyMatrix)[i];
	/* copy of adjacencyMatrix created */

	/* 	now we need to keep the track of vertices being merged
		for this we need to introduce a one-D bit array that will keep track of this information.
		let this one-D bit array be flag.
	*/
	flag=(unsigned int *)malloc(sizeof(unsigned int)*(g->numberOfVertices)/32+1);
	for(i=0;i<(g->numberOfVertices)/32+1;i++)
		flag[i]=0;
	/*
		if the nth bit of flag array is 0 this means that the vertex with vertexNumber 'n' is still
		alive and is not merged with any other vertex.

		if the nth bit of flag array is 1 this means that the vertex with vertexNumber 'n' is dead
		and is merged with some other vertex and has no existence now.
	*/
	/* now we are ready for merging vertices in our dummy (copied) adjacencyMatrix.  */
	for(i=0;i<(g->numberOfVertices);i++)
	{
		if(get_one_D_bit_array(i,flag)==0) // means ith vertex is alive
		{
			for(j=0;j<(g->numberOfVertices);j++)
			{
				if(j!=i && get_one_D_bit_array(j,flag)==0) // means the jth vertex is alive
				{
					if(get_two_D_bit_array(i,j,adjacencyMatrix_copy,g->numberOfVertices)==1)
					{
						/*
							now we need to merge the ith node with the jth node
							for this we need to merge
								ith row with jth row, and
								ith col with jth col
						*/
						for(k=0;k<(g->numberOfVertices);k++) // merging the ith and jth rows
						{
							if(get_two_D_bit_array(i,k,adjacencyMatrix_copy,g->numberOfVertices) | get_two_D_bit_array(j,k,adjacencyMatrix_copy,g->numberOfVertices))
								set_two_D_bit_array(i,k,adjacencyMatrix_copy,g->numberOfVertices);
						}
						for(k=0;k<(g->numberOfVertices);k++) // merging the ith and jth cols
						{
							if(get_two_D_bit_array(k,i,adjacencyMatrix_copy,g->numberOfVertices) | get_two_D_bit_array(k,j,adjacencyMatrix_copy,g->numberOfVertices))
								set_two_D_bit_array(k,i,adjacencyMatrix_copy,g->numberOfVertices);
						}
						/* now the jth vertex is merged with ith vertex so the ith vertex should have no existence */
						/* so we need to set the jth bit of flag array to 1 */
						set_one_D_bit_array(j,flag); // declaring that the jth vertex is now dead.
					}
				}
			}
		}
	}
	/* 
		now the total number of components in the graph will be the number of vertices that still have zero 
		correponding to their vertex number in flag array.
	*/
	components=0;
	for(i=0;i<(g->numberOfVertices);i++)
		if(get_one_D_bit_array(i,flag)==0)
			components++;
	return components;
}
struct Graph_AdjacencyList*convertMatrixToList(struct Graph_AdjacencyMatrix*graph)
{
	int i,j;
	struct Graph_AdjacencyList*newGraph;
	newGraph=makeAndInitialiseGraph();
	for(i=0;i<(graph->numberOfVertices);i++)
		addVertex_AdjacencyList(newGraph,makeVertex());
	for(i=0;i<(graph->numberOfVertices);i++)
	{
		for(j=0;j<(graph->numberOfVertices);j++)
		{
			if(get_two_D_bit_array(i,j,graph->adjacencyMatrix,graph->numberOfVertices)==1)
				addEdge_AdjacencyList(newGraph,i,j);
		}
	}
	return newGraph;
}

struct Graph_AdjacencyMatrix*convertListToMatrix(struct Graph_AdjacencyList*graph)
{
	struct Vertex_AdjacencyList*vertex1,*vertex2;
	struct ListNode_Generic*node1,*node2;
	struct Graph_AdjacencyMatrix*newGraph;
	newGraph=makeNewGraph();
	newGraph->numberOfVertices=graph->numberOfVertices;
	newGraph->numberOfEdges=0;
	initializeAdjacencyMatrix(newGraph);
	for(node1=graph->vertexList->start;node1;node1=node1->next)
	{
		vertex1=(struct Vertex_AdjacencyList*)(node1->data);
		for(node2=vertex1->adjacencyList->start;node2;node2=node2->next)
		{
			vertex2=(struct Vertex_AdjacencyList*)(node2->data);
			createEdge_AdjacencyMatrix(newGraph,vertex1->id,vertex2->id);
			(newGraph->numberOfEdges)=(newGraph->numberOfEdges)+1;
		}
	}
	return newGraph;
}
