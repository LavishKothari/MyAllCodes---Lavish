#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node
{
    int data;
    struct Node*next;
};

typedef struct Node Node;

Node*sort2(Node*,Node**);
Node*sort(Node*start,Node**);
Node*reverseList(Node*,Node**);
void insertAfter(Node*,Node**,int,int);
Node* insertBefore(Node*,int,int);
void printList(Node*);
Node*insertLast(Node*,Node**,Node*);
Node*createNode(int);
int search(Node*,int);
Node*Delete(Node*,Node**,int);
Node*deleteLast(Node*,Node**);

/*
int main()
{
    int temp,ch,num;
    Node *newNode,*start,*last;
    start=last=NULL;
    while(1)
    {
        printf("\n_________________menu__________________\n");
        printf("1. insert at the end of list...\n");
        printf("2. print the list...\n");
        printf("3. search a speific item...\n");
        printf("4. insert after a specific node...\n");
        printf("5. insert a node before a specific node...\n");
        printf("6. delete a specific node...\n");
        printf("7. delete a last node...\n");
        printf("8. reverse the link list...\n");
        printf("9. sort the link list...\n");
        printf("10. sort the link list(another method)...\n");
        printf("11. exit...\n");

        printf("\nenter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("enter the data part of the node that you want to insert :\n");
                scanf("%d",&temp);
                newNode=createNode(temp);
                start=insertLast(start,&last,newNode);
                break;
            case 2:
                printList(start);
                break;
            case 3:
                printf("enter the data that you want to search : ");
                scanf("%d",&temp);
                if(search(start,temp))
                    printf("the number you entered was in the list");
                else
                    printf("the number you entered was not in the list");
                break;
            case 4:
                printf("enter the data of the node after which you want to insert new node : ");
                scanf("%d",&temp);
                printf("enter the data part of the node that you want to insert : ");
                scanf("%d",&num);
                insertAfter(start,&last,temp,num);
                break;
            case 5:
                printf("enter the data of the node before which you want to insert new node : ");
                scanf("%d",&temp);
                printf("enter the data part of the node that you want to insert : ");
                scanf("%d",&num);
                start=insertBefore(start,temp,num);
                break;
            case 6:
                printf("enter the data part of the node that you want to delete : ");
                scanf("%d",&temp);
                start=Delete(start,&last,temp);
                break;
            case 7:
                if(last==NULL)
                {
                    printf("the list is empty...you can't delete any node...");
                    break;
                }
                start=deleteLast(start,&last);
                break;
            case 8:
                start=reverseList(start,&last);
                break;
            case 9:
                start=sort(start,&last);
                break;
            case 10:
                start=sort2(start,&last);
                break;
            case 11:
                exit(1);
            default:
                printf("you have entered a wrong choice...enter a valid choice");
        }
    }
}
*/
Node* createNode(int data)
{
    Node*newNode;
    newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

Node*insertLast(Node*start,Node**p2last,Node*newNode)
{
    if(*p2last==NULL)
    {
        *p2last=newNode;
        return newNode;
    }
    (*p2last)->next=newNode;
    *p2last=newNode;
    return start;
}

void printList(Node*start)
{
    printf("your list is as follows : \n");
    while(start)
    {
        printf("%d\t",start->data);
        start=start->next;
    }
}

int search(Node*start,int data)
{
    while(start)
    {
        if(start->data==data)
            return 1;
        start=start->next;
    }
    return 0;
}

void insertAfter(Node*start,Node**p2last,int data,int num)
{
    Node*newNode,*tmp;
    newNode=createNode(num);
    if(*p2last==NULL)
        printf("the list is empty...");
    tmp=start;
    while(tmp)
    {
        if(tmp->data==data)
            break;
        tmp=tmp->next;
    }
    if(!tmp)
        printf("the number you enter was not in the list\n");
    else
    {
        newNode->next=tmp->next;
        tmp->next=newNode;
        if(tmp==*p2last)
            *p2last=newNode;
    }
}

Node*insertBefore(Node*start,int data,int num)
{
    Node *newNode,*prev,*tmp;
    prev=NULL;
    newNode=createNode(num);
    if(start==NULL)
    {
        printf("the list is empty...");
        return start;
    }
    tmp=start;
    while(tmp)
    {
        if(tmp->data==data)
            break;
        prev=tmp;
        tmp=tmp->next;
    }
    if(!tmp)
        printf("the number you enter was not in the list\n");
    else if(prev==NULL)
    {
        newNode->next=start;
        start=newNode;
    }
    else
    {
        newNode->next=prev->next;
        prev->next=newNode;
    }
    return start;
}

Node*Delete(Node*start,Node**p2last,int data)
{
    Node*prev,*tmp;
    tmp=start;
    prev=NULL;
    while(tmp)
    {
        if(tmp->data==data)
            break;
        prev=tmp;
        tmp=tmp->next;
    }

    if(!tmp)
    {
        printf("the item you entered was not in the list...\n");
        return start;
    }
    if(tmp==start)
    {
        if((*p2last)==start)
            *p2last=NULL;
        return NULL;
    }
    prev->next=tmp->next;
    if(tmp==(*p2last))
        *p2last=prev;
    free(tmp);

    return start;
}

Node*deleteLast(Node*start,Node**p2last)
{
    return Delete(start,p2last,(*p2last)->data);
}

Node*reverseList(Node*start,Node**p2last)
{
    Node*ptr,*tmp,*prev;
    (*p2last)=start;
    prev=NULL;
    for(ptr=start;ptr;)
    {
        tmp=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=tmp;
    }
    return prev;
}

Node*sort(Node*start,Node**p2last)
{
    Node*ptr,*newNode,*tmp,*start1,*last1;
    start1=last1=NULL;
    while(start!=NULL)
    {
        tmp=ptr=start;
        while(ptr)
        {
            if(tmp->data > ptr->data)
                tmp=ptr;
            ptr=ptr->next;
        }
        newNode=createNode(tmp->data);
        start1=insertLast(start1,&last1,newNode);
        start=Delete(start,p2last,tmp->data);
    }
    *p2last=last1;
    return start1;
}

Node*sort2(Node*start,Node**p2last)
{
    int *arr,count=0,i,tmp,j;
    Node*ptr,*start1,*last1,*newNode;
    ptr=start;
    start1=last1=NULL;
    while(ptr)
    {
        count++;
        ptr=ptr->next;
    }

    arr=(int*)malloc(sizeof(int)*count);

    ptr=start;
    for(i=0;i<count;i++)
    {
        arr[i]=ptr->data;
        ptr=ptr->next;
    }

    /* sorting the array bubble */
    for(i=1;i<count;i++)
        for(j=0;j<count-i;j++)
            if(arr[j]>arr[j+1])
            {
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }

    for(i=0;i<count;i++)
        start1=insertLast(start1,&last1,createNode(arr[i]));
    *p2last=last1;
    return start1;
}

int main()
{
    int t,temp;
    Node *newNode,*start,*last;
    scanf("%d",&t);
    while(t--)
    {
        start=last=NULL;
        scanf("%d",&n);
        for(i=0;i<(int)pow(2,n);i++)
        {
            scanf("%d",&temp);
            start=insertLast(createNode(temp));
        }


    }
    return 0;
}
