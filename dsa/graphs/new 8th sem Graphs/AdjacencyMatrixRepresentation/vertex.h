#define WHITE 1 // if a vertex is WHITE means it is not yet visited.
#define GRAY 2 // if a vertex is GRAY means it is visited but some of its neighbours are not visited.
#define BLACK 3 // if a vertex is BLACK means it is visited and all of its neighbours are also visited.
struct Vertex
{
	int vertexNumber,color,distance,parentVertexNumber;
};
