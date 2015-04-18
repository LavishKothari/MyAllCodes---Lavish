#include"LinkedList_Generic.h"
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
struct Graph_AdjacencyList* makeAndInitialiseGraph();
void addVertex_AdjacencyList(struct Graph_AdjacencyList*graph,struct Vertex_AdjacencyList*vertex);
int getVertexId_AdjacencyList(struct ListNode_Generic*node);
void removeVertex_AdjacencyList(struct Graph_AdjacencyList*graph,int vertexNumber);
void addEdge_AdjacencyList(struct Graph_AdjacencyList*graph,int sourceVertexNumber,int destinationVertexNumber);
void removeEdge_AdjacencyList(struct Graph_AdjacencyList *graph,int sourceVertexNumber,int destinationVertexNumber);
struct Vertex_AdjacencyList *makeVertex();
void printGraph_AdjacencyList(struct Graph_AdjacencyList*graph);

