/*
    this program illustrates the reversing the linked list
    reverseList(struct Node*) is used for the same.
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

struct Node*reverseList(struct Node*start)
{
    struct Node*prev=NULL,*currentNode=start,*temp;
    while(currentNode)
    {
        temp=currentNode->next;
        currentNode->next=prev;
        prev=currentNode;
        currentNode=temp;
    }
    return prev;
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
    printf("The original LinkedList is : \n");
    printList(start);

    start=reverseList(start);

    printf("The reverse of the original Linked List is : \n");
    printList(start);
    return 0;
}
