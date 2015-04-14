#include<stdio.h>
#include"Graph_Generic.h"
int main()
{
	struct Graph_Generic*graph;
	int a,b,weight,isDirected,i,numberOfVertices,numberOfEdges,sourceVertex,destinationVertex,vertexNumber;

	printf("Enter the number of Vertices in the Graph : ");
	scanf("%d",&(numberOfVertices));
	printf("Enter the number of Edges in the Graph : ");
	scanf("%d",&(numberOfEdges));

	graph=makeAndInitialiseGraph();

	for(i=0;i<numberOfVertices;i++)
		addVertex(graph,makeVertex());

	printf("NOTE 1 : The ordering of the Vertices and Edges is zero indexed.\n");
	printf("NOTE 2 : For each edge enter the following in Sequence : \n");
	printf("\t1. Source Vertex Number.\n");
	printf("\t2. Destination Vertex Number.\n");
	printf("\t3. Weight associated with Edge.\n");
	printf("\t4. 1 if the Edge is Directed, and 0 otherwise.\n");
	
	for(i=0;i<numberOfEdges;i++)
	{
		printf("Enter the edge Number %d : ",i+1);
		scanf("%d%d%d%d",&a,&b,&weight,&isDirected);
		addEdge(graph,makeEdge(a,b,weight,isDirected));
	}
	printGraph_Generic(graph);
	
	printf("\nDeleting an Edge : \n");
	printf("Enter the sourceVertex, destinationVertex and weight of the graph : ");
	scanf("%d%d%d",&sourceVertex,&destinationVertex,&weight);
	removeEdge(graph,sourceVertex,destinationVertex,weight);
	
	printf("Deleting a Vertex : \n");
	printf("Enter the Vertex number to be deleted : ");
	scanf("%d",&vertexNumber);
	removeVertex(graph,vertexNumber);
	
	printGraph_Generic(graph);
	
	printf("Program Execution Successful...\n");
	return 0;
}
