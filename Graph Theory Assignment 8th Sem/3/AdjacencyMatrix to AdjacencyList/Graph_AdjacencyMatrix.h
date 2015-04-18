#include"Graph_AdjacencyList.h"
struct Graph_AdjacencyMatrix
{
	int numberOfVertices,numberOfEdges;
	unsigned int*adjacencyMatrix;
};
struct Graph_AdjacencyMatrix*makeNewGraph();
void initializeAdjacencyMatrix(struct Graph_AdjacencyMatrix*);
void createEdge_AdjacencyMatrix(struct Graph_AdjacencyMatrix*,int,int);
void removeEdge_AdjacencyMatrix(struct Graph_AdjacencyMatrix*,int,int);
void showAdjacencyMatrix(struct Graph_AdjacencyMatrix*);
int findNumberOfComponents(struct Graph_AdjacencyMatrix*);
struct Graph_AdjacencyList*convertMatrixToList(struct Graph_AdjacencyMatrix*graph);
struct Graph_AdjacencyMatrix*convertListToMatrix(struct Graph_AdjacencyList*graph);
