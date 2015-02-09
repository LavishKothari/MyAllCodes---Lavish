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
        printf("%d , ",start->data);
        start=start->next;
    }
    printf("\n");
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

struct Node*deleteFromLastAndInserInFront(struct Node*start)
{
    struct Node*prev=NULL,*current=start;
    if(!(current->next) || !current)
        return start;
    while(current->next)
    {
        prev=current;
        current=current->next;
    }
    prev->next=NULL;
    current->next=start;
    return current;
}


struct Node*deleteFromFirstAndInserAtLast(struct Node*start)
{
    struct Node*current,*temp;
    if(!(start->next) || !start)
        return start;
    for(current=start;current->next;current=current->next);
    // now current is pointing to the last element of the linked list.
    current->next=start;
    temp=start->next;
    current->next->next=NULL;
    return temp;
}

struct Node*rotationLastToFirst(struct Node*start,int n)
{
    while(n--)
        start=deleteFromLastAndInserInFront(start);
    return start;
}

struct Node*rotationFirstToLast(struct Node*start,int n)
{
    while(n--)
        start=deleteFromFirstAndInserAtLast(start);
    return start;
}
int main()
{
    struct Node*start=NULL;
    start=insertAtEnd(start,makeNode(5));
    start=insertAtEnd(start,makeNode(3));
    start=insertAtEnd(start,makeNode(7));
    start=insertAtEnd(start,makeNode(4));
    start=insertAtEnd(start,makeNode(9));
    start=insertAtEnd(start,makeNode(2));
    start=insertAtEnd(start,makeNode(1));
    start=insertAtEnd(start,makeNode(8));
    start=insertAtEnd(start,makeNode(6));

    //start=rotationLastToFirst(start,10);
    start=rotationFirstToLast(start,3);
    printList(start);
    return 0;
}
