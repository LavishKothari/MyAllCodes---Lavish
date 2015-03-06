#include<stdlib.h>
#include<stdio.h>
struct Graph
{
	int numberOfVertices,numberOfEdges;
	unsigned int*adjacencyMatrix;
};
struct Graph*makeNewGraph();
void initializeAdjacencyMatrix(struct Graph*g);
void createEdge(struct Graph*g,int,int);
void showAdjacencyMatrix(struct Graph*g);
int numberOfParallelEdges(struct Graph*);
int numberOfSelfLoops(struct Graph*);
int numberOfIsolatedNodes(struct Graph*);
int numberOfPendantNodes(struct Graph*);

