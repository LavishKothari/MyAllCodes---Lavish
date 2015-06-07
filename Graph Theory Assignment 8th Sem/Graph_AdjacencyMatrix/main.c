#include<stdio.h>
#include"Graph_AdjacencyMatrix.h"

int main()
{
	int i,n,a,b,numberOfVertices,numberOfEdges;
	struct Graph_AdjacencyMatrix*g;
	
	printf("Enter the number of Vertices in the Graph : ");
	scanf("%d",&numberOfVertices);
	printf("Enter the number of Edges in the Graph : ");
	scanf("%d",&numberOfEdges);
	
	g=makeNewGraph(numberOfVertices);
	
	printf("NOTE : The ordering of the vertices is zero indexed.\n");

    printf("Enter the information about edges : \n");
    for(i=0;i<numberOfEdges;i++)
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
