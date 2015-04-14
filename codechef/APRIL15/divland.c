#include<stdio.h>
#include<stdlib.h>
/*

6 9
0 1 1 
0 2 2
0 3 2
0 5 2
1 2 5
2 4 3 
3 4 1
3 5 4
1 4 1


*/
struct Node
{
	int d,w;
	struct Node*next;
};
struct Edge
{
	int s,d,w;
};
int c(const void*a,const void*b)
{
	struct Edge aa,bb;
	aa=*(struct Edge*)a;
	bb=*(struct Edge*)b;
	return aa.w-bb.w;
}
struct Node*makeNode(int d,int w)
{
	struct Node*node;
	node=(struct Node*)malloc(sizeof(struct Node));
	node->next=NULL;
	node->d=d;
	node->w=w;
	return node;
}
struct Node* insert(struct Node*start,struct Node*node)
{
	struct Node*ptr,*prev;
	prev=NULL;
	if(!start)
		return node;
	for(ptr=start;ptr && (ptr->d)<(node->d);prev=ptr,ptr=ptr->next);
	if(ptr)
		node->next=ptr;
	prev->next=node;
}

void insertAfter(struct Node*ptr,struct Node*newNode)
{
	newNode->next=ptr->next;
	ptr->next=newNode;
}
struct Node*insertStart(struct Node*start,struct Node*newNode)
{
	newNode->next=start;
	return newNode;
}
struct Node* searchAndChange(struct Node*start,int d,int w)
{
	struct Node*ptr,*prev;
	prev=NULL;
	for(ptr=start;ptr && (ptr->d)<=d;prev=ptr,ptr=ptr->next)
	{
		if((ptr->d)==(d))
		{
			(ptr->w)=(ptr->w)+w;
			return start;
		}
	}
	if(prev!=NULL)
		insertAfter(prev,makeNode(d,w));
	else
		start=insertStart(start,makeNode(d,w));

	return start;
}

void printLinkedList(struct Node*start)
{
	for(;start;start=start->next)
	{
		printf("%d(%d),",start->d,start->w);
	}
	printf("\n");
}
void printAdjacencyList(struct Node**startArray,int n)
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("The adjacency List of vertex number %d is : ",i);
		printLinkedList(startArray[i]);
	}
}
void makeAdjacencyList(struct Node**startArray,int n,struct Edge*arr,int e)
{
	int i,min,max;
	for(i=0;i<e;i++)
	{
		min=arr[i].s<arr[i].d?arr[i].s:arr[i].d;
		max=arr[i].s>arr[i].d?arr[i].s:arr[i].d;
		startArray[min]=searchAndChange(startArray[min],max,arr[i].w);
	}
}

int makeEdgeArray(struct Node**startArray,int n,struct Edge*arr,int e)
{
	int counter=0,i;
	struct Node*start,*ptr;
	for(i=0;i<n;i++)
	{
		start=startArray[i];
		for(ptr=start;ptr;ptr=ptr->next)
		{
			arr[counter].s=i;
			arr[counter].d=ptr->d;
			arr[counter].w=ptr->w;
			counter++;
		}
	}
	return counter;
}

int main()
{
	int counter,needed,newSize,j;
	int n,e,i,*flagn,*flagv;
	struct Node**startArray;
	struct Edge*arr;
	scanf("%d%d",&n,&e);

	startArray=(struct Node**)malloc(sizeof(struct Node*)*n);
	for(i=0;i<n;i++)
	{
		startArray[i]=NULL;
	}	
	arr=(struct Edge*)malloc(sizeof(struct Edge)*e);
	flagv=(int*)malloc(sizeof(int)*n);	
	
	for(i=0;i<n;i++)
		flagv[i]=0;
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&(arr[i].s),&(arr[i].d),&(arr[i].w));
	}
	
	makeAdjacencyList(startArray,n,arr,e);
	
	newSize=makeEdgeArray(startArray,n,arr,e); // this will overwrite arr.
	
	qsort(arr,newSize,sizeof(struct Edge),c);
	counter=0;
	for(i=newSize-1;i>=0;i--)
	{
		needed=n/2-counter;
		if(needed==0)
			break;

		j=i+1;
		while(j>=0 && arr[i].w==arr[j].w)
		{
			j--;
		}
		j++;
		// now edges from jth index to ith index have the same weight.
		// and you need to choose an edge which is most appropriate.
		// now you need to cleverly choose some of the edges that have same weight
		// number of edges that you need to choose : needed.
		

		if((flagv[arr[i].s]==0 || flagv[arr[i].d]==0) && needed!=1)
		{
			if(flagv[arr[i].s]==0)
			{
				counter++;
				printf("%d ",arr[i].s);
				flagv[arr[i].s]=1;
			}
			if(flagv[arr[i].d]==0)
			{
				counter++;
				printf("%d ",arr[i].d);
				flagv[arr[i].d]=1;
			}
			if(counter>=n/2)
				break;
		}
		else if(flagv[arr[i].d]==0 && flagv[arr[i].s]==1 && needed==1) // exactly one of the vertex should be alive.
		{
			printf("%d ",arr[i].d);
			break;
		}
		else if(flagv[arr[i].d]==1 && flagv[arr[i].s]==0 && needed==1) // exactly one of the vertex should be alive.
		{
			printf("%d ",arr[i].s);
			break;
		}
	}
	return 0;
}
