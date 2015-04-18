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
unsigned int countParallelEdges_AdjacencyList(struct Graph_AdjacencyList*graph)
{
	int i,count=0,*flag;
	struct Vertex_AdjacencyList*vertex1,*vertex2;
	struct ListNode_Generic*pointer1,*pointer2;
	flag=(int*)malloc(sizeof(int)*(graph->numberOfVertices));
	for(pointer1=graph->vertexList->start;pointer1;pointer1=pointer1->next)
	{
		vertex1=(struct Vertex_AdjacencyList*)(pointer1->data);
		
		for(i=0;i<(graph->numberOfVertices);i++)
			flag[i]=0;
		
		for(pointer2=vertex1->adjacencyList->start;pointer2;pointer2=pointer2->next)
		{
			vertex2=(struct Vertex_AdjacencyList*)(pointer2->data);
			flag[vertex2->id]++;
		}
		for(i=0;i<(graph->numberOfVertices);i++)
		{
			if(flag[i]>1)
			{
				/*uncomment the next line to display number of parallel edges from source to destination.*/
				//printf("%d Parallel Edges from %d to %d\n",flag[i],vertex1->id,i);
				count=count+flag[i];
			}
		}
	}
	return count;
}
unsigned int countSelfLoops_AdjacencyList(struct Graph_AdjacencyList*graph)
{
	int count=0;
	struct Vertex_AdjacencyList*vertex1,*vertex2;
	struct ListNode_Generic*pointer1,*pointer2;
	for(pointer1=graph->vertexList->start;pointer1;pointer1=pointer1->next)
	{
		vertex1=(struct Vertex_AdjacencyList*)(pointer1->data);
		for(pointer2=vertex1->adjacencyList->start;pointer2;pointer2=pointer2->next)
		{
			vertex2=(struct Vertex_AdjacencyList*)(pointer2->data);
			if((vertex1->id)==(vertex2->id))
				count+=1;
		}
	}
	return count;
}
unsigned int countIsolatedNodes_AdjacencyList(struct Graph_AdjacencyList*graph)
{
	int count=0,*flag,i,j;
	struct Vertex_AdjacencyList*vertex1,*vertex2;
	struct ListNode_Generic*pointer1,*pointer2;
	
	flag=(int*)malloc(sizeof(int)*(graph->numberOfVertices));
	for(i=0;i<(graph->numberOfVertices);i++)
		flag[i]=0;
	
	for(pointer1=graph->vertexList->start;pointer1;pointer1=pointer1->next)
	{
		vertex1=(struct Vertex_AdjacencyList*)(pointer1->data);
		for(pointer2=vertex1->adjacencyList->start;pointer2;pointer2=pointer2->next)
		{
			vertex2=(struct Vertex_AdjacencyList*)(pointer2->data);
			flag[vertex1->id]=1;
			flag[vertex2->id]=1;
		}
	}
	for(i=0;i<(graph->numberOfVertices);i++)
		if(flag[i]==0)
			count++;
	return count;
}

unsigned int countPendentNodes_AdjacencyList(struct Graph_AdjacencyList*graph)
{
	/*
		a vertex is defined as pendent vertex if its degree is 1.
	*/
	unsigned int *degree,count=0,i;
	struct Vertex_AdjacencyList*vertex1,*vertex2;
	struct ListNode_Generic*pointer1,*pointer2;
	
	degree=(unsigned int*)malloc(sizeof(unsigned int)*(graph->numberOfVertices));
	for(i=0;i<(graph->numberOfVertices);i++)
		degree[i]=0;
		
	// assuming inDegree = outDegree = Degree of vertex.
	for(pointer1=graph->vertexList->start;pointer1;pointer1=pointer1->next)
	{
		vertex1=(struct Vertex_AdjacencyList*)(pointer1->data);
		for(pointer2=vertex1->adjacencyList->start;pointer2;pointer2=pointer2->next)
		{
			vertex2=(struct Vertex_AdjacencyList*)(pointer2->data);
			degree[vertex1->id]++;
			degree[vertex2->id]++;
			//printf("Incrementing degree of %d\n",vertex1->id);
			//printf("Incrementing degree of %d\n",vertex2->id);
		}
	}
	for(i=0;i<(graph->numberOfVertices);i++)
		if(degree[i]==1)
			count++;
	return count;			
}
