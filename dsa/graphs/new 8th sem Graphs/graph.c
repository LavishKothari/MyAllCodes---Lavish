#include"graph.h"
struct Graph*makeNewGraph()
{
	struct Graph*g;
	g=(struct Graph*)malloc(sizeof(struct Graph));
	return g;
}
void initializeAdjacencyMatrix(struct Graph*g)
{
	int sizeOfIntegerColumns,i,j;
	sizeOfIntegerColumns=((g->numberOfVertices)*(g->numberOfVertices))/32+1;
	(g->adjacencyMatrix)=(unsigned int*)malloc(sizeof(unsigned int)*sizeOfIntegerColumns);
	for(i=0;i<sizeOfIntegerColumns;i++)
		(g->adjacencyMatrix)[i]=0;
}
void createEdge(struct Graph*g,int a,int b)
{
	int bitNumber=a*(g->numberOfVertices)+b;
	(g->adjacencyMatrix)[bitNumber/32]|=((unsigned int)1<<(31-bitNumber%32));  // to set its 31-(bitNumber%32) th bit.
}
void showAdjacencyMatrix(struct Graph*g)
{
	int i,j,bitNumber;
	for(i=0;i<(g->numberOfVertices);i++)
	{
		for(j=0;j<(g->numberOfVertices);j++)
		{
			bitNumber=i*(g->numberOfVertices)+j;
			if(((g->adjacencyMatrix)[bitNumber/32]&((unsigned int)1<<(31-bitNumber%32)))!=0)
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
}
