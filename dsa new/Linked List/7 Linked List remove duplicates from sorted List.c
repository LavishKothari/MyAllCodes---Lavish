
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*next;
};

struct Node* makeNode(int n)
{
    struct Node*node;
    node=(struct Node*)malloc(sizeof(struct Node)*n);
    node->next=NULL;
    node->data=n;
    return node;
}

void printList(struct Node*start)
{
    while(start)
    {
        printf("%d\n",start->data);
        start=start->next;
    }
}

struct Node*insertAtEnd(struct Node*start,struct Node*newNode)
{
    struct Node*node;
    if(!start)
        return newNode;
    for(node=start;node->next;node=node->next);
    node->next=newNode;
    return start;
}

void removeDuplicatesFromSorted(struct Node*start)
{
    struct Node*temp;
    while(start)
    {
        if(start->next && start->next->data==start->data)
        {
            temp=start->next;
            start->next=start->next->next;
            free(temp);
        }
        start=start->next;
    }
}

int main()
{
    struct Node*start=NULL;
    start=insertAtEnd(start,makeNode(3));
    start=insertAtEnd(start,makeNode(3));
    start=insertAtEnd(start,makeNode(4));
    start=insertAtEnd(start,makeNode(4));
    start=insertAtEnd(start,makeNode(9));
    start=insertAtEnd(start,makeNode(21));
    start=insertAtEnd(start,makeNode(21));
    start=insertAtEnd(start,makeNode(89));
    start=insertAtEnd(start,makeNode(96));
    start=insertAtEnd(start,makeNode(96));

    removeDuplicatesFromSorted(start);
    printList(start);
    return 0;
}
