/*
	This representation of graph is the Adjacency List representation.
	Corresponding to each vertex of the graph we maintain a list of vertices that are connected to that vertex.
	for maintaining the vertex list (adjacency List) corresponding to each vertex, we maintain a Generic List.
	this generic list is defined in LinkedList_Generic.c
	
	this adjacencyList corresponding to each vertex will just store the references of vertex (reference of c, don't get confused with the reference variables of c++)
	
	this storing of reference will have the following advantage :
		Suppose you need to modify any of the data for a specific vertex, then you just need to modify the data correnponding to that vertex in the vertex list.
		you dont need to modify each and every node where this vertex may apper in the adjacencyList of any vertex.
*/

#include"Graph_AdjacencyList.h"
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
	vertex->adjacencyList=makeAndInitialiseLinkedList(sizeof(struct Vertex_AdjacencyList*));
	return vertex;
}
struct Vertex_AdjacencyList*getVertexReference(struct Graph_AdjacencyList*graph,int n)
{
	struct Vertex_AdjacencyList*vertex;
	struct ListNode_Generic*node;
	for(node=graph->vertexList->start;node;node=node->next)
	{
		vertex=(struct Vertex_AdjacencyList*)(node->data);
		if(vertex->id==n)
			return vertex;
	}
}
void addVertex(struct Graph_AdjacencyList*graph,struct Vertex_AdjacencyList*vertex)
{
	(graph->numberOfVertices)++;
	addElement(graph->vertexList,makeAndInitialiseListNode(graph->vertexList,vertex));
}

void removeVertex(struct Graph_AdjacencyList*graph,int vertexNumber)
{
	int i;
	struct ListNode_Generic*node;
	struct Vertex_AdjacencyList*vertex;
	for(node=graph->vertexList->start;node;node=node->next)
	{
		vertex=(struct Vertex_AdjacencyList*)(node->data);
		removeEdge(graph,vertex->id,vertexNumber);
	}
	removeElement(graph->vertexList,getNodeReferenceWithGivenData(graph->vertexList,getVertexReference(graph,vertexNumber)));
}

void addEdge(struct Graph_AdjacencyList*graph,int sourceVertexNumber,int destinationVertexNumber)
{
	addElement
	(
		getVertexReference(graph,sourceVertexNumber)->adjacencyList,
		makeAndInitialiseListNode
		(
			getVertexReference(graph,sourceVertexNumber)->adjacencyList,
			getVertexReference(graph,destinationVertexNumber)
		)
	);
}
void removeEdge(struct Graph_AdjacencyList *graph,int sourceVertexNumber,int destinationVertexNumber)
{
	removeElement
	(
		getVertexReference(graph,sourceVertexNumber)->adjacencyList,
		getNodeReferenceWithGivenData
		(
			getVertexReference(graph,sourceVertexNumber)->adjacencyList,
			getVertexReference(graph,destinationVertexNumber)
		)
	);
}
void printGraph_AdjacencyList(struct Graph_AdjacencyList*graph)
{
	struct Vertex_AdjacencyList*vertexPtr,*jointVertex;
	struct ListNode_Generic*pointer,*ptr;
	int i;
	printf("\nTotal Number Of Vertices in the Graph : %d\n",graph->numberOfVertices);
	printf("\nPrinting the Adjacency List of each vertex. \n");
	for(ptr=(struct ListNode_Generic*)((graph->vertexList)->start);ptr;ptr=ptr->next)
	{
		vertexPtr=(struct Vertex_AdjacencyList*)(ptr->data);
		printf("Vertex No. : %d: ",vertexPtr->id); // Printing the id of current vertex number.
		for(pointer=(struct ListNode_Generic*)((vertexPtr->adjacencyList)->start);pointer;pointer=pointer->next)
		{
			jointVertex=(struct Vertex_AdjacencyList*)(pointer->data);
			printf("%d ",jointVertex->id);
		}
		printf("\n\n");
	}
}
