#include"linkedlist.h"
#include<vertex.h>
struct Graph
{
	int numberOfVertices,numberOfEdges;
	struct Vertex*vertices;
};
struct Graph*makeNewGraph();
void initializeAdjacencyMatrix(struct Graph*);
void createEdge(struct Graph*,int,int);
void removeEdge(struct Graph*,int,int);
