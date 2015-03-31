struct Queue
{
	int first,last,numberOfElements;
	int *arr;
};
void initializeQueue(struct Queue*,int);
void enqueue(struct Queue*,int);
int dequeue(struct Queue*);
void freeQueue(struct Queue*);

