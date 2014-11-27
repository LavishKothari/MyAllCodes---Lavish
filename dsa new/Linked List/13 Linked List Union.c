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

struct Node*unionOfLists(struct Node*start1,struct Node*start2)
{
    int flag;
    struct Node*copy_start1,*returnStart=NULL;

    /*
        copying all the data from first list into the newly constructed list.
    */
    for(copy_start1=start1;start1;start1=start1->next)
        returnStart=insertAtEnd(returnStart,makeNode(start1->data));

    /*
        now copying all the data from the second list into the new
        list if the current node in second list is not present in the first list
    */
    for(start1=copy_start1;start2;start2=start2->next)
    {
        flag=0;
        for(copy_start1=start1;start1;start1=start1->next)
            if(start2->data==start1->data)
            {
                flag=1;
                break;
            }
        start1=copy_start1;
        if(flag==0)
            returnStart=insertAtEnd(returnStart,makeNode(start2->data));
    }
    return returnStart;
}


int main()
{
    struct Node*start1=NULL,*start2=NULL,*unionList;
    start1=insertAtEnd(start1,makeNode(5));
    start1=insertAtEnd(start1,makeNode(3));
    start1=insertAtEnd(start1,makeNode(7));
    start1=insertAtEnd(start1,makeNode(4));
    start1=insertAtEnd(start1,makeNode(9));
    start1=insertAtEnd(start1,makeNode(2));

    start2=insertAtEnd(start2,makeNode(5));
    start2=insertAtEnd(start2,makeNode(7));
    start2=insertAtEnd(start2,makeNode(3));
    start2=insertAtEnd(start2,makeNode(9));
    start2=insertAtEnd(start2,makeNode(2));

    unionList=unionOfLists(start1,start2);
    printList(unionList);
    return 0;
}
