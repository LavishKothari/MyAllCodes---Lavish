//#include"LinkedList_Generic.h"
#include"queue.h"
#include"stack.h"

#define BLACK 0
#define GRAY 1
#define WHITE 2

#define INFINITY 2147483647

struct Graph_AdjacencyList
{
	struct LinkedList_Generic *vertexList;
	int numberOfVertices;
};
struct Vertex_AdjacencyList
{
	int id;
	int color,distance;
	struct Vertex_AdjacencyList*parent;
	struct LinkedList_Generic *adjacencyList;
};
struct Graph_AdjacencyList* createGraph(int);
void addVertex(struct Graph_AdjacencyList*graph,struct Vertex_AdjacencyList*vertex);
int getVertexId(struct ListNode_Generic*node);
void removeVertex(struct Graph_AdjacencyList*graph,int vertexNumber);
void addEdge(struct Graph_AdjacencyList*graph,int sourceVertexNumber,int destinationVertexNumber);
void removeEdge(struct Graph_AdjacencyList *graph,int sourceVertexNumber,int destinationVertexNumber);
struct Vertex_AdjacencyList *makeVertex(int);
void printGraph_AdjacencyList(struct Graph_AdjacencyList*graph);
struct Graph_AdjacencyList* BFS(struct Graph_AdjacencyList*graph,int startingVertexNumber);
struct Graph_AdjacencyList* DFS(struct Graph_AdjacencyList*graph,int startingVertexNumber);
