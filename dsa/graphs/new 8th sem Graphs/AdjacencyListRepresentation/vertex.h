#define WHITE 1
#define GRAY 2
#define BLACK 3
struct Vertex
{
	struct Vertex parent;
	int color,distanceFromSource;
	struct LinkedList adjacencyList;
};
