long long int solveExpression(char *);
struct Node
{
	int data;
	char op;
	struct Node*next;
};
struct LinkedList
{
	struct Node*start;	
};
struct StackNode
{
	char op;
	struct StackNode*next;
};
struct Node*makeNode(int data,char op);
struct Node*insertAtEnd(struct Node*start, struct Node*newNode);
struct Node*deleteNode(struct Node*start,int data,char op);
void printList(struct Node*start);
struct StackNode*makeStackNode(char op);
struct StackNode*push(struct StackNode*top, struct StackNode*newNode);
struct StackNode*pop(struct StackNode**top);