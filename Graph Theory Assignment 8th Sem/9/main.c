#include<stdio.h>
#include"Graph_AdjacencyMatrix.h"

int main()
{
	int i,n,a,b;
	struct Graph*g;
	g=makeNewGraph();
	printf("Enter the number of Vertices in the Graph : ");
	scanf("%d",&(g->numberOfVertices));
	printf("Enter the number of Edges in the Graph : ");
	scanf("%d",&(g->numberOfEdges));
	initializeAdjacencyMatrix(g);
	printf("NOTE : The ordering of the vertices is zero indexed.\n");
	for(i=0;i<(g->numberOfEdges);i++)
	{
		printf("Enter the edge Number %d : ",i+1);
		scanf("%d%d",&a,&b);
		createEdge(g,a,b);
	}
	showAdjacencyMatrix(g);
	printf("Number of components in the Graph = %d\n",findNumberOfComponents(g));
	printf("\nProgram execution successful...\n");
	return 0;
}
