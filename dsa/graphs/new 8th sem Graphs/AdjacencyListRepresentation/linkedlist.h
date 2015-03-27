struct Node
{
	struct Vertex*data;
	struct Node*next;
};
struct LinkedList
{
	struct Node*start,*last;
};
struct Node*makeNode(struct Vertex*vertex);
void add(LinkedList *list,struct Node*node);
