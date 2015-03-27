#include<stdlib.h>
#include<stdio.h>
#define WHITE 1
#define GRAY 2
#define BLACK 3
struct Node
{
	int vertexNumber;
	struct Node*next;
};
struct Vertex
{
	int vertexNumber;
	struct Node*start;
};
int *mainColorArray;
////////////////////////////////////////////////////////////////////////////////////
struct Queue
{
	int first,last,numberOfElements;
	int *arr;
};
struct Queue* makeAndInitializeQueue(int n) // n is maximum number of Elements that you want in your queue
{
	struct Queue *q;
	q=(struct Queue*)malloc(sizeof(struct Queue));
	q->numberOfElements=n;
	(q->arr)=(int*)malloc(sizeof(int)*n);
	(q->numberOfElements)=0;
	(q->first)=(q->last)=-1;
	return q;
}
void enqueue(struct Queue*q,int newElement)
{
	if((q->numberOfElements)==0)
		(q->first)++;
	(q->numberOfElements)++;
	(q->arr)[++(q->last)]=newElement;
}
int dequeue(struct Queue*q)
{
	(q->numberOfElements)--;
	if((q->first)==(q->last))
	{
		int r=(q->arr)[q->first];
		(q->first)=(q->last)=-1;
		return r;
	}
	return (q->arr)[(q->first)++];
}
void freeQueue(struct Queue*q)
{
	free(q->arr);
	free(q);
}
////////////////////////////////////////////////////////////////////////////////////
struct Vertex *makeNewVertex(int vertexNumber)
{
	struct Vertex*vertex;
	vertex=(struct Vertex*)malloc(sizeof(struct Vertex));
	(vertex->vertexNumber)=vertexNumber;
	(vertex->start)=NULL;
	return vertex;
}
struct Node* insertNode(struct Node*start,struct Node*node)
{
	struct Node*ptr;
	 if(start==NULL)
	 	return node;
	 for(ptr=start;ptr->next;ptr=ptr->next);
	 ptr->next=node;
	 return start;
}
struct Node* removeNode(struct Node*start,int nodeNumber)
{
	struct Node*ptr,*prevPtr;
	if(start==NULL)
		return start;
	for(ptr=start;ptr && (ptr->vertexNumber)!=nodeNumber;prevPtr=ptr,ptr=ptr->next);
	if(ptr!=NULL) // means this vertex is not found in Adjacency List
	{
		if(ptr==start)
		{
			ptr=start->next;
			free(start);
			return ptr;
		}
		(prevPtr->next)=(ptr->next);
		free(ptr);
	}
	return start;
}
struct Node*makeNode(int vertexNumber)
{
	struct Node*node;
	node=(struct Node*)malloc(sizeof(struct Node));
	(node->vertexNumber)=vertexNumber;
	node->next=NULL;
	return node;
}
void printList(struct Node*start)
{
	for(;start;printf("%d ",start->vertexNumber),start=start->next);
}
void printAdjacencyList(struct Vertex**vertexArray,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d -> ",i);
		printList((vertexArray[i])->start);
		printf("\n");
	}
}
void BFS(int n,int m,struct Vertex**vertexArray,int sourceVertexNumber)
{
	struct Node*ptr;
	struct Queue*queue;
	int i,*colorArray,u,v;
	colorArray=(int*)malloc(sizeof(int)*n*m);
	for(i=0;i<n*m;i++)
		colorArray[i]=WHITE;
	colorArray[sourceVertexNumber]=GRAY;
	// making queue...
	queue=makeAndInitializeQueue(n*m);
	enqueue(queue,sourceVertexNumber);
	printf("Printing the BFS order : \n");
	while((queue->numberOfElements)!=0)
	{
		u=dequeue(queue);
		printf("%d ",u);
		for(ptr=((vertexArray[u])->start);ptr;ptr=ptr->next)
		{
			if(colorArray[ptr->vertexNumber]==WHITE)
			{
				colorArray[ptr->vertexNumber]=GRAY;
				enqueue(queue,ptr->vertexNumber);
			}
		}
		colorArray[u]=BLACK;
	}
	freeQueue(queue);
	free(colorArray);
	printf("\n");
}
int findMaximumNumberOfComponents(int n,int m,struct Vertex**vertexArray,int sourceVertexNumber)
{
	struct Node*ptr;
	struct Queue*queue;
	int i,u,v,counter;
	mainColorArray[sourceVertexNumber]=GRAY;
	// making queue...
	queue=makeAndInitializeQueue(n*m);
	enqueue(queue,sourceVertexNumber);
	//printf("Printing the BFS order : \n");
	counter=0;
	while((queue->numberOfElements)!=0)
	{
		u=dequeue(queue);
		counter++;
		//printf("%d ",u);
		for(ptr=((vertexArray[u])->start);ptr;ptr=ptr->next)
		{
			//printf("hey\n");
			if(mainColorArray[ptr->vertexNumber]==WHITE)
			{
				mainColorArray[ptr->vertexNumber]=GRAY;
				enqueue(queue,ptr->vertexNumber);
			}
		}
		mainColorArray[u]=BLACK;
	}
	freeQueue(queue);
	//printf("\n");
	return counter;
}
int isReachable(int n,int m,struct Vertex**vertexArray,int sourceVertexNumber,int destinationVertexNumber)
{
	struct Node*ptr;
	struct Queue*queue;
	int i,*colorArray,u,v;
	colorArray=(int*)malloc(sizeof(int)*n*m);
	for(i=0;i<n*m;i++)
		colorArray[i]=WHITE;
	colorArray[sourceVertexNumber]=GRAY;
	// making queue...
	queue=makeAndInitializeQueue(n*m);
	enqueue(queue,sourceVertexNumber);
	//printf("Printing the BFS order : \n");
	while((queue->numberOfElements)!=0)
	{
		u=dequeue(queue);
		//printf("%d ",u);
		if(u==destinationVertexNumber)
			return 1;
		for(ptr=((vertexArray[u])->start);ptr;ptr=ptr->next)
		{
			if(colorArray[ptr->vertexNumber]==WHITE)
			{
				colorArray[ptr->vertexNumber]=GRAY;
				enqueue(queue,ptr->vertexNumber);
			}
		}
		colorArray[u]=BLACK;
	}
	freeQueue(queue);
	free(colorArray);
	//printf("\n");
	return 0;
}
int main()
{
	int t,i,j,n,m,q,max,temp,type,x,y,x1,x2,y1,y2;
	long long int answer;
	struct Node*start,*ptr;
	struct Vertex ** vertexArray;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&q);
		vertexArray=(struct Vertex**)malloc(sizeof(struct Vertex*)*n*m);
		for(i=0;i<n*m;i++)
			vertexArray[i]=makeNewVertex(i);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(i-1>=0) ((vertexArray[i*m+j])->start)=insertNode((vertexArray[i*m+j])->start,makeNode((i-1)*m+j));
				if(i+1<n) ((vertexArray[i*m+j])->start)=insertNode((vertexArray[i*m+j])->start,makeNode((i+1)*m+j));
				if(j-1>=0) ((vertexArray[i*m+j])->start)=insertNode((vertexArray[i*m+j])->start,makeNode(i*m+j-1));
				if(j+1<m) ((vertexArray[i*m+j])->start)=insertNode((vertexArray[i*m+j])->start,makeNode(i*m+j+1));
			}
		}
		//printAdjacencyList(vertexArray,n*m);
		//BFS(n,m,vertexArray,0);
		answer=0;
		while(q--)
		{
			scanf("%d",&type);
			switch(type)
			{
				case 1:
					scanf("%d%d",&x,&y);
					x--;y--;
					(vertexArray[x*m+y])->start=removeNode((vertexArray[x*m+y])->start,x*m+y+1);
					(vertexArray[x*m+y+1])->start=removeNode((vertexArray[x*m+y+1])->start,x*m+y);
					//printAdjacencyList(vertexArray,n*m);
					break;
				case 2:
					scanf("%d%d",&x,&y);
					x--;y--;
					(vertexArray[x*m+y])->start=removeNode((vertexArray[x*m+y])->start,(x+1)*m+y);
					(vertexArray[(x+1)*m+y])->start=removeNode((vertexArray[(x+1)*m+y])->start,x*m+y);
					//printAdjacencyList(vertexArray,n*m);
					break;
				case 3:
					scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
					x1--;y1--;x2--;y2--;
					answer+=isReachable(n,m,vertexArray,x1*m+y1,x2*m+y2);
					break;
				case 4:
					max=0;
					mainColorArray=(int*)malloc(sizeof(int)*n*m);
					for(i=0;i<n*m;i++)
						mainColorArray[i]=WHITE;
					for(i=0;i<n*m;i++)
					{
						if(mainColorArray[i]==WHITE)
						{
							temp=findMaximumNumberOfComponents(n,m,vertexArray,i);
							if(temp>max)
								max=temp;
						}
					}
					answer+=max;
					free(mainColorArray);
					break;
			}
		}
		printf("%lld\n",answer);
		///////////////////////////////// END OF EACH TEST CASE.
		for(i=0;i<m*n;i++)
		{
			for(ptr=(vertexArray[i]->start);ptr;ptr=ptr->next)
				free(ptr);
			free(vertexArray[i]);
		}
		free(vertexArray);
	}
	return 0;
}
