#include"LinkedList_Generic.h"

struct Stack
{
    struct LinkedList_Generic *list;
	int numberOfElements;
};

struct Stack* createStack(int elementSize);
void push(struct Stack*q,struct ListNode_Generic*node);
struct ListNode_Generic* pop(struct Stack*q);
void freeStack(struct Stack*);
