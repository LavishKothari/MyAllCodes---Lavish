#include<stdio.h>
#include<stdlib.h>
#include"Graph_AdjacencyMatrix.h"
#include"two_D_bit_array.h"
#include"one_D_bit_array.h"

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
	set_two_D_bit_array(a,b,g->adjacencyMatrix,g->numberOfVertices);
}
void removeEdge(struct Graph*g,int a,int b)
{
	reset_two_D_bit_array(a,b,g->adjacencyMatrix,g->numberOfVertices);
}
void showAdjacencyMatrix(struct Graph*g)
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

int findNumberOfComponents(struct Graph*g)
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
			for(j=i+1;j<(g->numberOfVertices);j++)
			{
				if(get_one_D_bit_array(j,flag)==0) // means the jth vertex is alive
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
