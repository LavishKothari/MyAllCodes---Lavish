#include"Graph_AdjacencyList.h"
//#include"LinkedList_Generic.h"
#include<stdlib.h>
#include<stdio.h>
struct Graph_AdjacencyList*makeAndInitialiseGraph()
{
	struct Graph_AdjacencyList*graph;
	graph=(struct Graph_AdjacencyList*)malloc(sizeof(struct Graph_AdjacencyList));
	graph->numberOfVertices=0;
	graph->vertexList=makeAndInitialiseLinkedList(sizeof(struct Vertex_AdjacencyList));
	return graph;
}
struct Vertex_AdjacencyList *makeVertex()
{
	static int vertexNumber=0;
	struct Vertex_AdjacencyList*vertex;
	vertex=(struct Vertex_AdjacencyList*)malloc(sizeof(struct Vertex_AdjacencyList));
	(vertex->id)=vertexNumber++;
	vertex->adjacencyList=makeAndInitialiseLinkedList(sizeof(int));
	return vertex;
}
int getVertexId(struct ListNode_Generic*node)
{
	return ((struct Vertex_AdjacencyList*)(node->data))->id;
}
void addVertex(struct Graph_AdjacencyList*graph,struct Vertex_AdjacencyList*vertex)
{
	(graph->numberOfVertices)++;
	addElement(graph->vertexList,makeAndInitialiseListNode(graph->vertexList,vertex));
}
void removeVertex(struct Graph_AdjacencyList*graph,int vertexNumber)
{
	(graph->numberOfVertices)--;
	removeElement(graph->vertexList,vertexNumber,getVertexId);
}
void addEdge(struct Graph_AdjacencyList*graph,int sourceVertexNumber,int destinationVertexNumber)
{
	int*dPtr;
	struct ListNode_Generic*ptr;
	dPtr=(int*)malloc(sizeof(int));
	(*dPtr)=destinationVertexNumber;
	for(ptr=(graph->vertexList)->start;ptr && (((struct Vertex_AdjacencyList*)(ptr->data))->id)!=sourceVertexNumber;ptr=ptr->next);
	if(ptr)
		addElement(((struct Vertex_AdjacencyList*)(ptr->data))->adjacencyList,makeAndInitialiseListNode(((struct Vertex_AdjacencyList*)(ptr->data))->adjacencyList,dPtr));
}
void removeEdge(struct Graph_AdjacencyList *graph,int sourceVertexNumber,int destinationVertexNumber)
{
	struct ListNode_Generic*ptr; // this ptr will point to an element of vertex list --> means it will point to a vertex.
	for(ptr=(struct ListNode_Generic*)((graph->vertexList)->start);ptr && (((struct Vertex_AdjacencyList*)(ptr->data))->id)!=sourceVertexNumber;ptr=ptr->next);
	if(ptr)
		removeElement(((struct Vertex_AdjacencyList*)(ptr->data))->adjacencyList,destinationVertexNumber,getVertexId);
}
void printGraph_AdjacencyList(struct Graph_AdjacencyList*graph)
{
	struct Vertex_AdjacencyList*vertexPtr;
	struct ListNode_Generic*pointer;
	int i;
	struct ListNode_Generic*ptr;
	printf("\nTotal Number Of Vertices in the Graph : %d\n",graph->numberOfVertices);
	printf("\nPrinting the Adjacency List of each vertex. \n");
	for(ptr=(struct ListNode_Generic*)((graph->vertexList)->start);ptr;ptr=ptr->next)
	{
		vertexPtr=ptr->data;
		printf("Vertex No. : %d: ",vertexPtr->id); // Printing the id of current vertex number.
		for(pointer=(struct ListNode_Generic*)((vertexPtr->adjacencyList)->start);pointer;pointer=pointer->next)
			printf("%d ",*(((int*)pointer->data)));
		printf("\n");
	}
}
