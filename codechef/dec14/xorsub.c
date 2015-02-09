#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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

struct Node*add(struct Node*start,struct Node*newNode)
{
    struct Node*node;
    if(!start)
        return newNode;
    for(node=start;node->next;node=node->next);
    node->next=newNode;
    return start;
}
int calculateLength(int n)
{
    int answer=0;
    if(n<=0)
        return 0;

    while(n)
    {
        answer++;
        n>>=1;
    }
    return answer;
}
struct Node*removeFirst(struct Node*start)
{
    struct Node*temp;
    if(!start)
        return start;
    temp=start;
    start=start->next;
    free(temp);
    return start;
}
int main()
{
    int t,n,k,*arr,a,i,x,xelement,oldElement,len,element;
    struct Node *list[11];
    struct Node *newList[11];
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<=10;i++)
        {
            list[i]=NULL;
            newList[i]=NULL;
        }
        scanf("%d%d",&n,&k);
        arr=(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        for(i=0;i<n;i++)
        {
            a=calculateLength(arr[i]);
            list[a]=add(list[a],makeNode(arr[i]));
        }
        // Gaussian Elimination
        for(i=10;i>=0;i--)
        {
            //printf("hello lavish kothari\n");
            if(list[i])
            {
                xelement=list[i]->data;
                newList[i]=add(newList[i],makeNode(xelement));
                list[i]=removeFirst(list[i]);
                element=newList[i]->data;
                while(list[i])
                {
                    oldElement=list[i]->data;
                    list[i]=removeFirst(list[i]);
                    len=calculateLength(element^oldElement);
                    if(len>0)
                        list[len]=add(list[len],makeNode(element^oldElement));
                }
            }
        }
        x=k;

        for(i=10;i>=1;i--)
        {
            if(newList[i])
            {
                element=newList[i]->data;
                if((x^element) > x)
                    x=(x^element);
            }
        }
        printf("%d\n",x);
        for(i=0;i<=10;i++)
        {
            if(list[i])
                free(list[i]);
            if(newList[i])
                free(newList[i]);
        }
    }
    return 0;
}
