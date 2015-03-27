#include"Graph_Generic.h"
#include"LinkedList_Generic.h"
#include<stdlib.h>
struct Graph_Generic*makeAndInitialiseGraph(int numberOfVertices,int numberOfEdges)
{
	struct Graph_Generic*graph;
	graph=(struct Graph_Generic*)malloc(sizeof(struct Graph_Generic));
	graph->numberOfVertices=numberOfVertices;
	graph->numberOfEdges=numberOfEdges;
	graph->vertexList=makeAndInitialiseLinkedList(sizeof(struct Vertex));
	graph->edgeList=makeAndInitialiseLinkedList(sizeof(struct Edge));
	return graph;
}
struct Edge *makeEdge(int sourceVertex,int destinationVertex,int weight,int isDirected)
{
	static int edgeNumber=0;
	struct Edge*edge;
	edge=(struct Edge*)malloc(sizeof(struct Edge));
	edge->sourceVertex=sourceVertex;
	edge->destinationVertex=destinationVertex;	
	edge->weight=weight;
	edge->isDirected=isDirected;
	edge->id=edgeNumber++;
	return edge;
}
int getVertexId(struct ListNode_Generic*node)
{
	return ((struct Vertex*)(node->data))->id;
}
int getEdgeId(struct ListNode_Generic*node)
{
	return ((struct Edge*)(node->data))->id;
}

void addVertex(struct Graph_Generic*graph,struct Vertex*vertex)
{
	addElement(graph->vertexList,vertex);
}
void removeVertex(struct Graph_Generic*graph,int vertexNumber)
{
	removeElement(graph->vertexList,vertexNumber,getVertexId);
}
void addEdge(struct Graph_Generic*graph,struct Edge*edge)
{
	addElement(graph->edgeList,edge);
}
void removeEdge(struct Graph_Generic *graph,int edgeNumber)
{
	removeElement(graph->edgeList,edgeNumber,getEdgeId);
}
