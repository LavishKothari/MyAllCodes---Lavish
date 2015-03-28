#include"Graph_Generic.h"
#include"LinkedList_Generic.h"
#include<stdlib.h>
#include<stdio.h>
struct Graph_Generic*makeAndInitialiseGraph()
{
	struct Graph_Generic*graph;
	graph=(struct Graph_Generic*)malloc(sizeof(struct Graph_Generic));
	graph->numberOfVertices=0;
	graph->numberOfEdges=0;
	graph->vertexList=makeAndInitialiseLinkedList(sizeof(struct Vertex));
	graph->edgeList=makeAndInitialiseLinkedList(sizeof(struct Edge));
	return graph;
}
struct Edge *makeEdge(int sourceVertex,int destinationVertex,int weight,int isDirected)
{
	static int edgeNumber=0;
	struct Edge*edge;
	printf("hello Rakshit Kothari\n");
	edge=(struct Edge*)malloc(sizeof(struct Edge));
	printf("hello lavish Kothari\n");
	edge->sourceVertex=sourceVertex;
	edge->destinationVertex=destinationVertex;	
	edge->weight=weight;
	edge->isDirected=isDirected;
	edge->id=edgeNumber++;
	return edge;
}
struct Vertex *makeVertex()
{
	static int vertexNumber=0;
	struct Vertex*vertex;
	vertex=(struct Vertex*)malloc(sizeof(struct Vertex));
	(vertex->id)=vertexNumber++;
	return vertex;
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
	(graph->numberOfVertices)++;
	addElement(graph->vertexList,makeAndInitialiseListNode(graph->vertexList,vertex));
}
void removeVertex(struct Graph_Generic*graph,int vertexNumber)
{
	(graph->numberOfVertices)--;
	removeElement(graph->vertexList,vertexNumber,getVertexId);
}
void addEdge(struct Graph_Generic*graph,struct Edge*edge)
{
	(graph->numberOfEdges)++;
	addElement(graph->edgeList,makeAndInitialiseListNode(graph->edgeList,edge));
}
void removeEdge(struct Graph_Generic *graph,int edgeNumber)
{
	(graph->numberOfEdges)--;
	removeElement(graph->edgeList,edgeNumber,getEdgeId);
}
void printGraph_Generic(struct Graph_Generic*graph)
{
	int i;
	struct ListNode_Generic*ptr;
	printf("\nPrinting the vertex List : \n");
	printf("\nTotal Number Of Vertices in the Graph : %d\n",graph->numberOfVertices);
	for(ptr=(struct ListNode_Generic*)((graph->vertexList)->start);ptr;ptr=ptr->next)
		printf("%d ",((struct Vertex*)(ptr->data))->id);
	printf("\nTotal Number Of Edges in the Graph : %d\n",graph->numberOfEdges);
	for(ptr=(struct ListNode_Generic*)((graph->edgeList)->start);ptr;ptr=ptr->next)
		printf("Edge No. : %d, from %d to %d with weight=%d and isDirected?=%d\n",((struct Edge*)(ptr->data))->id,((struct Edge*)(ptr->data))->sourceVertex,((struct Edge*)(ptr->data))->destinationVertex,((struct Edge*)(ptr->data))->weight,((struct Edge*)(ptr->data))->isDirected);
}
