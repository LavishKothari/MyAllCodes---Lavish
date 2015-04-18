#include"LinkedList_Generic.h"
/*
	this is a directed graph.
*/
/*
	The graph will have a vertexList which will store all the the vertex of the graph in a list.
	
	And then corresponding to each vertex we have its own adjacency list which will store all the vertices adjacency to this vertex. 
*/
struct Graph_AdjacencyList
{
	struct LinkedList_Generic *vertexList;
	int numberOfVertices;
};
struct Vertex_AdjacencyList
{
	int id;
	struct LinkedList_Generic *adjacencyList;
};
struct Graph_AdjacencyList*makeAndInitialiseGraph();
void addVertex(struct Graph_AdjacencyList*graph,struct Vertex_AdjacencyList*vertex);
int getVertexId(struct ListNode_Generic*node);
void removeVertex(struct Graph_AdjacencyList*graph,int vertexNumber);
void addEdge(struct Graph_AdjacencyList*graph,int sourceVertexNumber,int destinationVertexNumber);
void removeEdge(struct Graph_AdjacencyList *graph,int sourceVertexNumber,int destinationVertexNumber);
struct Vertex_AdjacencyList *makeVertex();
void printGraph_AdjacencyList(struct Graph_AdjacencyList*graph);

unsigned int countParallelEdges_AdjacencyList(struct Graph_AdjacencyList*graph);
unsigned int countSelfLoops_AdjacencyList(struct Graph_AdjacencyList*graph);
unsigned int countIsolatedNodes_AdjacencyList(struct Graph_AdjacencyList*graph);
unsigned int countPendentNodes_AdjacencyList(struct Graph_AdjacencyList*graph);
