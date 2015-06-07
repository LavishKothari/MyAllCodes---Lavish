struct Graph_AdjacencyMatrix
{
	int numberOfVertices;
	unsigned int*adjacencyMatrix;
};
struct Graph_AdjacencyMatrix*makeNewGraph(int);
void createEdge(struct Graph_AdjacencyMatrix*,int,int);
void removeEdge(struct Graph_AdjacencyMatrix*,int,int);
void showAdjacencyMatrix(struct Graph_AdjacencyMatrix*);
int findNumberOfComponents(struct Graph_AdjacencyMatrix*);
