
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
struct Node*sortSpecial(struct Node*start)
{
    struct Node*temp;
    int num0=0,num1=0,num2=0;
    while(start)
    {
        if(start->data==0)
            num0++;
        else if(start->data==1)
            num1++;
        else if(start->data==2)
            num2++;
        temp=start;
        start=start->next;
        free(temp);
    }
    while(num0--)
        start=insertAtEnd(start,makeNode(0));
    while(num1--)
        start=insertAtEnd(start,makeNode(1));
    while(num2--)
        start=insertAtEnd(start,makeNode(2));
    return start;
}
int main()
{
    struct Node*start=NULL;
    start=insertAtEnd(start,makeNode(1));
    start=insertAtEnd(start,makeNode(0));
    start=insertAtEnd(start,makeNode(1));
    start=insertAtEnd(start,makeNode(2));
    start=insertAtEnd(start,makeNode(0));
    start=insertAtEnd(start,makeNode(2));
    start=insertAtEnd(start,makeNode(0));
    start=insertAtEnd(start,makeNode(1));
    start=insertAtEnd(start,makeNode(0));
    printf("The original Linked List is : \n");
    printList(start);
    start=sortSpecial(start);
    printf("The Linked List after sorting is : \n");
    printList(start);

    return 0;
}
