

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

struct Node*intersection(struct Node*start1,struct Node*start2)
{
    struct Node*copy_start2,*returnStart=NULL;
    while(start1)
    {
        for(copy_start2=start2;copy_start2;copy_start2=copy_start2->next)
            if(start1->data==copy_start2->data)
            {
                returnStart=insertAtEnd(returnStart,makeNode(start1->data));
                break;
            }
        start1=start1->next;
    }
    return returnStart;
}


int main()
{
    struct Node*start1=NULL,*start2=NULL,*intersectionList;
    start1=insertAtEnd(start1,makeNode(5));
    start1=insertAtEnd(start1,makeNode(3));
    start1=insertAtEnd(start1,makeNode(7));
    start1=insertAtEnd(start1,makeNode(4));
    start1=insertAtEnd(start1,makeNode(9));
    start1=insertAtEnd(start1,makeNode(2));

    start2=insertAtEnd(start2,makeNode(1));
    start2=insertAtEnd(start2,makeNode(8));
    start2=insertAtEnd(start2,makeNode(3));
    start2=insertAtEnd(start2,makeNode(9));
    start2=insertAtEnd(start2,makeNode(6));

    intersectionList=intersection(start1,start2);
    printList(intersectionList);
    return 0;
}
