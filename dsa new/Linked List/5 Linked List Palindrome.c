
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

// this function reverses the sublist from ath element to the bth element including a and b
struct Node*reverseListAdvanced(struct Node*start,int a,int b)
{
    struct Node*prev=NULL,*currentNode=start,*temp,*startNode,*prevStartNode;
    int i,copy_a=a;
    for(i=0;i<a-1;i++)
    {
        prev=currentNode;
        currentNode=currentNode->next;
    }
    startNode=currentNode; // this is the first node of the list that we need to reverse.
    prevStartNode=prev;
    while(currentNode && a<=b)
    {
        a++;
        temp=currentNode->next;
        currentNode->next=prev;
        prev=currentNode;
        currentNode=temp;
    }
    if(prevStartNode)
        prevStartNode->next=prev;
    startNode->next=currentNode;
    if(copy_a==1)
        return prev;
    return start;
}

int listSize(struct Node*start)
{
    int count=0;
    while(start)
    {
        count++;
        start=start->next;
    }
    return count;
}
int isPalindrome(struct Node*start)
{
    int i;
    struct Node*midNode;
    int size=listSize(start);
    if(size==1 || size==0)
        return 1;
    int mid=size/2;
    if(size&1!=0) // means size of list is odd
        mid+=2;
    else
        mid++;
    reverseListAdvanced(start,mid,size);
    for(i=1,midNode=start;i<mid;midNode=midNode->next,i++);
    while(midNode)
    {
        if(midNode->data!=start->data)
            return 0;
        midNode=midNode->next;
        start=start->next;
    }
    return 1;
}
int main()
{
    struct Node*start=NULL;
    start=insertAtEnd(start,makeNode(1));
    start=insertAtEnd(start,makeNode(2));
    start=insertAtEnd(start,makeNode(3));
    start=insertAtEnd(start,makeNode(4));
    start=insertAtEnd(start,makeNode(100));
    start=insertAtEnd(start,makeNode(4));
    start=insertAtEnd(start,makeNode(3));
    start=insertAtEnd(start,makeNode(2));
    start=insertAtEnd(start,makeNode(1));

    if(isPalindrome(start))
        printf("The linked List is Palindrome\n");
    else
        printf("The linked list is not a palindrome\n");

    return 0;
}
