struct Graph_Generic
{
	struct LinkedList_Generic *vertexList,*edgeList;
	int numberOfVertices, numberOfEdges;
};
struct Vertex
{
	int id;
};
struct Edge
{
	int id,sourceVertex,destinationVertex,isDirected,weight;
};
struct Graph_Generic*makeAndInitialiseGraph();
void addVertex(struct Graph_Generic*graph,struct Vertex*vertex);
void removeVertex(struct Graph_Generic*graph,int vertexNumber);
void addEdge(struct Graph_Generic*graph,struct Edge*edge);
void removeEdge(struct Graph_Generic *graph,int edgeNumber);
struct Edge *makeEdge(int sourceVertex,int destinationVertex,int weight,int isDirected);
struct Vertex *makeVertex();
void printGraph_Generic(struct Graph_Generic*grpah);
