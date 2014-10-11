#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct AdjacencyLinkedListNode;
int noOfVertices;
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

typedef struct AdjacencyLinkedListNode AdjacencyLinkedListNode;
typedef struct GraphNode GraphNode;

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

GraphNode * findGraphNode(GraphNode *graphNodeArray,char*tempName)
{
    AdjacencyLinkedListNode *nn;
    int i;
    for(i=0;i<noOfVertices;i++)
    {
        if(strcmp(tempName,graphNodeArray[i].name)==0)
        {
            return (&(graphNodeArray[i]));
        }
    }
    return NULL;
}

void printList(AdjacencyLinkedListNode*head)
{
    for(;head;printf("%s-->",head->node->name),head=head->next);
    printf("\n");
}
void displayGraph(GraphNode *graphNodeArray)
{
    int i;
    for(i=0;i<noOfVertices;i++)
    {
        printf("For node : %s ---> ",graphNodeArray[i].name);
        printList(graphNodeArray[i].head);
    }
}

int main()
{
    int noOfSuccessors;
    char tempName[100];
    int i,j;
    GraphNode *graphNodeArray;
    printf("\nEnter the no of vertices in the graph:");
    scanf("%d",&noOfVertices);
    graphNodeArray=(GraphNode*)malloc(sizeof(GraphNode)*noOfVertices);

    for(i=0;i<noOfVertices;i++)
    {
        printf("\nEnter the name of the vertex : ");
        scanf("%s",graphNodeArray[i].name);
        graphNodeArray[i].vertexNumber=i;
        graphNodeArray[i].distance=2147483647;
        strcpy(graphNodeArray[i].color,"white");
        graphNodeArray[i].parent=NULL;
        graphNodeArray[i].head=NULL;
    }

    for(i=0;i<noOfVertices;i++)
    {
        printf("\nEnter the no of vertices attached to node %s : ",graphNodeArray[i].name);
        scanf("%d",&noOfSuccessors);
        for(j=0;j<noOfSuccessors;j++)
        {
            printf("Enter the name of %d attached node to %d : ",j,i);
            scanf("%s",tempName);
            graphNodeArray[i].head=add(findGraphNode(graphNodeArray,tempName),graphNodeArray[i].head);
        }
    }

    displayGraph(graphNodeArray);
    return 0;
}

