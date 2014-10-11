#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct AdjacencyLinkedListNode;

struct GraphNode
{
    int vertexNumber;
    char name[100];
    struct GraphNode * parent;
    char color[100];
    int distance;

    struct AdjacencyLinkedListNode *head;
};

struct AdjacencyLinkedListNode
{
    struct GraphNode *node;
    struct AdjacencyLinkedListNode *next;
};

struct Graph
{
    struct GraphNode*graphNodeArray;
    int noOfVertices;
};

typedef struct AdjacencyLinkedListNode AdjacencyLinkedListNode;
typedef struct GraphNode GraphNode;
typedef struct Graph Graph;
AdjacencyLinkedListNode * makeLinkedListNode()
{
    AdjacencyLinkedListNode *nn;
    nn=(AdjacencyLinkedListNode*)malloc(sizeof(AdjacencyLinkedListNode));
    nn->node=NULL;
    nn->next=NULL;
    return nn;
}
AdjacencyLinkedListNode *add(GraphNode*gn,AdjacencyLinkedListNode*head)
{
    AdjacencyLinkedListNode*tempNode,*previousNode;
    AdjacencyLinkedListNode *newNode;

    newNode=makeLinkedListNode();
    newNode->node=gn;
    newNode->next=NULL;

    if(head==NULL)
        return newNode;

    for(tempNode=head;tempNode;previousNode=tempNode,tempNode=tempNode->next);
    previousNode->next=newNode;

    return head;
}

GraphNode * findGraphNode(Graph *G,char*tempName)
{
    AdjacencyLinkedListNode *nn;
    int i;
    for(i=0;i<G->noOfVertices;i++)
    {
        if(strcmp(tempName,G->graphNodeArray[i].name)==0)
        {
            return (&(G->graphNodeArray[i]));
        }
    }
    return NULL;
}

void printList(AdjacencyLinkedListNode*head)
{
    for(;head;printf("%s-->",head->node->name),head=head->next);
    printf("\n");
}

void displayGraph(Graph *G)
{
    int i;
    for(i=0;i<G->noOfVertices;i++)
    {
        printf("For node : %s ---> ",G->graphNodeArray[i].name);
        printList(G->graphNodeArray[i].head);
    }
}

int main()
{
    int noOfSuccessors;
    char tempName[100];
    int i,j;
    Graph *G;
    G=(Graph*)malloc(sizeof(Graph));

    printf("\nEnter the no of vertices in the graph:");
    scanf("%d",&G->noOfVertices);
    G->graphNodeArray=(GraphNode*)malloc(sizeof(GraphNode)*G->noOfVertices);

    for(i=0;i<G->noOfVertices;i++)
    {
        printf("\nEnter the name of the vertex : ");
        scanf("%s",G->graphNodeArray[i].name);
        G->graphNodeArray[i].vertexNumber=i;
        G->graphNodeArray[i].distance=2147483647;
        strcpy(G->graphNodeArray[i].color,"white");
        G->graphNodeArray[i].parent=NULL;
        G->graphNodeArray[i].head=NULL;
    }

    for(i=0;i<G->noOfVertices;i++)
    {
        printf("\nEnter the no of vertices attached to node %s : ",G->graphNodeArray[i].name);
        scanf("%d",&noOfSuccessors);
        for(j=0;j<noOfSuccessors;j++)
        {
            printf("Enter the name of %d attached node to %s : ",j+1,G->graphNodeArray[i].name);
            scanf("%s",tempName);
            G->graphNodeArray[i].head=add(findGraphNode(G,tempName),G->graphNodeArray[i].head);
        }
    }
    displayGraph(G);
    return 0;
}
