#ifndef LinkedList_Generic_H
#include"LinkedList_Generic.h"
#endif
struct Stack
{
    struct LinkedList_Generic *list;
	int numberOfElements;
};

struct Stack* createStack(int elementSize);
void push(struct Stack*s,struct ListNode_Generic*node);
struct ListNode_Generic* pop(struct Stack*s);
void freeStack(struct Stack*);
struct ListNode_Generic*getTopOfStack(struct Stack*stack);
