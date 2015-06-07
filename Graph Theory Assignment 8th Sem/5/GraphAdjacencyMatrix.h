#define INFINITY 2147483647

struct GraphAdjacencyMatrix
{
	int numberOfVertices;
	int ** adjacencyMatrix;
};

struct GraphAdjacencyMatrix * createGraph(int numberOfVertices);
void createEdge(struct GraphAdjacencyMatrix*,int ,int ,int);
void printGraph(struct GraphAdjacencyMatrix*);
void print2DMatrix(int**,int);
int ** findMinimumDistanceMatrix(struct GraphAdjacencyMatrix * graph);
int ** findReachabilityMatrix(struct GraphAdjacencyMatrix * graph);
