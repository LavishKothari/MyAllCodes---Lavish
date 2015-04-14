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
	edge=(struct Edge*)malloc(sizeof(struct Edge));
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

void addVertex(struct Graph_Generic*graph,struct Vertex*vertex)
{
	(graph->numberOfVertices)++;
	addElement(graph->vertexList,makeAndInitialiseListNode(graph->vertexList,vertex));
}
void removeVertex(struct Graph_Generic*graph,int vertexNumber)
{
	struct Edge*e;
	struct ListNode_Generic*ptr,*ptr1;
	(graph->numberOfVertices)--;
	for(ptr=graph->vertexList->start;ptr;ptr=ptr->next)
	{
		if(((struct Vertex*)(ptr->data))->id==vertexNumber)
			break;
	}
	if(ptr)
	{
		/*
			when you will be deleting an vertex then all the edges from and to that vertex should be deleted.
		*/
		for(ptr1=graph->edgeList->start;ptr1;ptr1=ptr1->next)
		{
			e=(struct Edge*)(ptr1->data);
			if(e->sourceVertex==vertexNumber || e->destinationVertex==vertexNumber)
				removeEdge(graph,e->sourceVertex,e->destinationVertex,e->weight);
		}
		removeElement(graph->vertexList,ptr);
	}
}
void addEdge(struct Graph_Generic*graph,struct Edge*edge)
{
	(graph->numberOfEdges)++;
	addElement(graph->edgeList,makeAndInitialiseListNode(graph->edgeList,edge));
}
void removeEdge(struct Graph_Generic *graph,int sourceVertex,int destinationVertex,int weight)
{
	struct ListNode_Generic*ptr;
	(graph->numberOfEdges)--;
	for(ptr=(graph->edgeList->start);ptr;ptr=ptr->next)
	{
		if(
			((struct Edge*)(ptr->data))->sourceVertex==sourceVertex &&
			((struct Edge*)(ptr->data))->destinationVertex==destinationVertex &&
			((struct Edge*)(ptr->data))->weight==weight
		) break;
	}
	if(ptr)
		removeElement(graph->edgeList,ptr);
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
