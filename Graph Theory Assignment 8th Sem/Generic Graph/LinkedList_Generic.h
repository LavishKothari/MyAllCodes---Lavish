struct LinkedList_Generic
{
	struct ListNode_Generic*start;
	int elementSize;
	/*
		elementSize, will store the size of each element. 
		The element size is important, because generics in C are limited to void pointers, 
		in order to let the compiler know the amount of memory needed by malloc/memcpy. 
		This information should always be supplied dynamically. The caller should use sizeof(int) rather than 4.
	*/
};
struct ListNode_Generic
{
	void *data;
	struct ListNode_Generic*next;
};
struct LinkedList_Generic *makeAndInitialiseLinkedList();
struct ListNode_Generic *makeAndInitialiseLisNode();
void addElement(struct LinkedList_Generic*list,void*element);
void removeElement(struct LinkedList_Generic*list,int ide,int(*getId)(struct ListNode_Generic*));
