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
void initializeGraph(struct Graph*g)
{
	// assuming you have defined numberOfVertices
	/*
		So this function should be called after the makeNewGraph is called and
		a value is assigned to numberOfVertices
	*/
}
void createEdge(struct Graph*g,int a,int b)
{
	setMatrix_i_j(a,b,g->adjacencyMatrix,g->numberOfVertices);
}
void removeEdge(struct Graph*g,int a,int b)
{
	resetMatrix_i_j(a,b,g->adjacencyMatrix,g->numberOfVertices);
}
