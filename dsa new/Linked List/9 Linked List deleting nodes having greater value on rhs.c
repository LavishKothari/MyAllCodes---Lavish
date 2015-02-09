/*
    deleting all the node that have a greater value on the right hand side
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

struct Node*deleteSpecial(struct Node*start)
{
    struct Node*cptr=start,*prev=NULL,*temp;
    while(cptr)
    {
        temp=NULL;
        if(cptr->next && cptr->next->data > cptr->data)
        {
            if(prev==NULL)
                start=start->next;
            else
                prev->next=cptr->next;
            temp=cptr;
        }
        prev=cptr;
        cptr=cptr->next;
        if(temp)
            free(temp);
    }
    return start;
}

int main()
{
    struct Node*start=NULL;
    start=insertAtEnd(start,makeNode(5));
    start=insertAtEnd(start,makeNode(41));
    start=insertAtEnd(start,makeNode(7));
    start=insertAtEnd(start,makeNode(4));
    start=insertAtEnd(start,makeNode(9));
    start=insertAtEnd(start,makeNode(2));
    start=insertAtEnd(start,makeNode(1));
    start=insertAtEnd(start,makeNode(8));
    start=insertAtEnd(start,makeNode(6));

    start=deleteSpecial(start);

    printList(start);
    return 0;
}
