
/*
    this program illustrates the concept involved in taking intersection of two sorted Linked List.
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

struct Node*instersectionOfSorted(struct Node* start1,struct Node* start2)
{
    struct Node*start3=NULL,*copy_start2;
    for(;start1;start1=start1->next)
    {
        for(copy_start2=start2;start2;start2=start2->next)
        {
            if(start2->data>start1->data)
                break;
            else if(start2->data==start1->data)
                start3=insertAtEnd(start3,makeNode(start1->data));
        }
        start2=copy_start2;
    }
    return start3;
}

int main()
{
    struct Node*start1=NULL,*start2=NULL,*start3;
    start1=insertAtEnd(start1,makeNode(5));
    start1=insertAtEnd(start1,makeNode(31));
    start1=insertAtEnd(start1,makeNode(72));
    start1=insertAtEnd(start1,makeNode(412));
    start1=insertAtEnd(start1,makeNode(910));
    start1=insertAtEnd(start1,makeNode(1020));
    start1=insertAtEnd(start1,makeNode(1335));
    start1=insertAtEnd(start1,makeNode(1859));
    start1=insertAtEnd(start1,makeNode(2906));

    start2=insertAtEnd(start2,makeNode(51));
    start2=insertAtEnd(start2,makeNode(60));
    start2=insertAtEnd(start2,makeNode(72));
    start2=insertAtEnd(start2,makeNode(512));
    start2=insertAtEnd(start2,makeNode(910));
    start2=insertAtEnd(start2,makeNode(1335));
    start2=insertAtEnd(start2,makeNode(1338));
    start2=insertAtEnd(start2,makeNode(1857));
    start2=insertAtEnd(start2,makeNode(2906));

    start3=instersectionOfSorted(start1,start2);
    printList(start3);
    return 0;
}
