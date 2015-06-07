#include<stdlib.h>
#include"stack.h"
struct Stack* createStack(int elementSize)
{
    struct Stack *stack;
    stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->list=createList(elementSize);
	return stack;
}
void push(struct Stack*stack,struct ListNode_Generic*node)
{
    /*
        you need to insert the node at the end of the stack->list
    */
    (stack->numberOfElements)++;
    addElement(stack->list,node);
}
struct ListNode_Generic* pop(struct Stack*stack)
{
    /*
        you need to remove element form the end of the stack->list and return the same
    */
    struct ListNode_Generic*node,*prev;
    (stack->numberOfElements)--;
    prev=NULL;
    for(node=stack->list->start;node && node->next!=NULL;prev=node,node=node->next);
    if(node)
    {
        if(prev)
            prev->next=NULL;
        else
            stack->list->start=NULL;
        return node;
    }
    else
        return NULL;
}
struct ListNode_Generic*getTopOfStack(struct Stack*stack)
{
    struct ListNode_Generic*node,*prev;
    prev=NULL;
    for(node=stack->list->start;node;prev=node,node=node->next);
    return prev;
}
void freeStack(struct Stack*stack)
{
    free(stack);
}
