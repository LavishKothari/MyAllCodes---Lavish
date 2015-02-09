/*
    this program illustrates the very basic structure of a LinkedList in C
    Only two functionality are provided in this program
        1. printing the list
        2. inserting a new node at the end of the list.
*/

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
    printList(start);
    return 0;
}
