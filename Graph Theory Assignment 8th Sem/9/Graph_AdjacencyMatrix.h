struct Graph
{
	int numberOfVertices,numberOfEdges;
	unsigned int*adjacencyMatrix;
};
struct Graph*makeNewGraph();
void initializeAdjacencyMatrix(struct Graph*);
void createEdge(struct Graph*,int,int);
void removeEdge(struct Graph*,int,int);
void showAdjacencyMatrix(struct Graph*);
int findNumberOfComponents(struct Graph*);
