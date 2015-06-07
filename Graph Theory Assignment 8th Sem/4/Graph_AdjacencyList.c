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
struct Graph_AdjacencyList*createGraph(int numberOfVertices)
{
    int i;
	struct Graph_AdjacencyList*graph;
	graph=(struct Graph_AdjacencyList*)malloc(sizeof(struct Graph_AdjacencyList));
	graph->numberOfVertices=0;
	graph->vertexList=createList(sizeof(struct Vertex_AdjacencyList));
	for(i=0;i<numberOfVertices;i++)
		addVertex(graph,makeVertex(i));
	return graph;
}
struct Vertex_AdjacencyList *makeVertex(int vertexNumber)
{
	struct Vertex_AdjacencyList*vertex;
	vertex=(struct Vertex_AdjacencyList*)malloc(sizeof(struct Vertex_AdjacencyList));
	(vertex->id)=vertexNumber;
	vertex->adjacencyList=createList(sizeof(struct Vertex_AdjacencyList*));
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
	addElement(graph->vertexList,createNode(graph->vertexList,vertex));
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
		createNode
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
		printf("\n");
	}
}
struct Vertex_AdjacencyList*getVertexReferenceByID(struct Graph_AdjacencyList*graph,int id)
{
	struct ListNode_Generic*node;
	struct Vertex_AdjacencyList*vertex;
	for(node=graph->vertexList->start;node;node=node->next)
	{
		vertex=(struct Vertex_AdjacencyList*)(node->data);
		if(vertex->id==id)
			return vertex;
	}
	return NULL;
}
void BFSVisit(struct Graph_AdjacencyList*graph,int startingVertexNumber,struct Graph_AdjacencyList*BFSTree)
{
	struct Queue*queue;
	struct ListNode_Generic*p;
	struct Vertex_AdjacencyList*startingVertex,*u,*v;
	
	startingVertex=getVertexReferenceByID(graph,startingVertexNumber);
	
	// basic initialization part of BFS
	
	startingVertex->color=GRAY;
	startingVertex->distance=0;
	startingVertex->parent=NULL;
	// basic initialization completes here
	
	queue=createQueue(sizeof(struct Vertex_AdjacencyList));
	enqueue(queue,createNode(queue->list,startingVertex));
	//printf("Running BFS : \n");
	while((queue->numberOfElements)!=0)
	{
		u=(struct Vertex_AdjacencyList*)(dequeue(queue)->data);
		//printf("%d ",u->id);
		for(p=u->adjacencyList->start;p;p=p->next)
		{
		    v=(struct Vertex_AdjacencyList*)(p->data);
		    if(v->color==WHITE)
		    {
		        addEdge(BFSTree,u->id,v->id);
		        v->color=GRAY;
		        v->distance=u->distance+1;
		        v->parent=u;
		        enqueue(queue,createNode(queue->list,v));   
		    }
		}
		u->color=BLACK;
	}
	//printf("\nBFS finished\n");
}
struct Graph_AdjacencyList*BFS(struct Graph_AdjacencyList*graph,int startingVertexNumber)
{
    struct ListNode_Generic*node;
    struct Vertex_AdjacencyList*vertex;
    struct Graph_AdjacencyList*BFSTree;
	BFSTree=createGraph(graph->numberOfVertices);
    for(node=graph->vertexList->start;node;node=node->next)
	{
		vertex=(struct Vertex_AdjacencyList*)(node->data);
		vertex->color=WHITE;
		vertex->distance=INFINITY;
		vertex->parent=NULL;
	}
	for(node=graph->vertexList->start;node;node=node->next)
	{
		vertex=(struct Vertex_AdjacencyList*)(node->data);
		if(vertex->color==WHITE)
		    BFSVisit(graph,vertex->id,BFSTree);
	}
	return BFSTree;
}

void DFSVisit(struct Graph_AdjacencyList*graph,int startingVertexNumber,struct Graph_AdjacencyList*DFSTree)
{
    struct Stack*stack;
    struct ListNode_Generic*ptr;
    struct Vertex_AdjacencyList *u,*v,*startingVertex;
    startingVertex=getVertexReferenceByID(graph,startingVertexNumber);
	
	// basic initialization part of DFS
	
	startingVertex->color=GRAY;
	startingVertex->distance=0;
	startingVertex->parent=NULL;
	// basic initialization completes here
	stack=createStack(sizeof(struct Vertex_AdjacencyList));
    push(stack,createNode(stack->list,startingVertex));
    
    while(stack->numberOfElements!=0)
    {
        u=(struct Vertex_AdjacencyList*)(getTopOfStack(stack)->data);
        // now we need to traverse the adjacency List of u and find a node whose color is white
        v=NULL;
        for(ptr=u->adjacencyList->start;ptr;ptr=ptr->next)
        {
            v=(struct Vertex_AdjacencyList*)(ptr->data);
            if(v->color==WHITE)
                break;
            v=NULL;
        }
        if(v==NULL)
        {
            u->color=BLACK;
            pop(stack);
        }
        else
        {
            addEdge(DFSTree,u->id,v->id);
            push(stack,createNode(stack->list,v));
            printf("%d ",v->id);
            v->color=GRAY;
        }
    }
}
struct Graph_AdjacencyList*DFS(struct Graph_AdjacencyList*graph,int startingVertexNumber)
{
    struct ListNode_Generic*node;
    struct Vertex_AdjacencyList*vertex;
    struct Graph_AdjacencyList*DFSTree;
	DFSTree=createGraph(graph->numberOfVertices);
    for(node=graph->vertexList->start;node;node=node->next)
	{
		vertex=(struct Vertex_AdjacencyList*)(node->data);
		vertex->color=WHITE;
		vertex->distance=INFINITY;
		vertex->parent=NULL;
	}
	for(node=graph->vertexList->start;node;node=node->next)
	{
		vertex=(struct Vertex_AdjacencyList*)(node->data);
		if(vertex->color==WHITE)
		    DFSVisit(graph,vertex->id,DFSTree);
	}
	return DFSTree;
}
