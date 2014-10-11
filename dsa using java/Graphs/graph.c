#include<stdio.h>
#include<stdlib.h>

struct LinkedList
{
    struct LinkedList*next;
    struct GraphNode*node;
};

struct GraphNode
{
    struct GraphNode*parent;
    char name[200];
    char color[20];
    int distance;
    int nodeNumber;
    struct LinkedList*start;
};

struct Graph
{
    int numberOfVerties;
};
int main()
{
    Graph *G;

    printf("Enter the number of vertices of the Graph : ")
    scanf("%d",&(G->numberOfVertices));

    for(i=0;i<n;i++)
    {
        printf("Enter the name of vertex number %d : ",(i+1));
    }

    return 0;
}
