// Program illustrating single linked list.
#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node*next;
};
struct Node*makeNode(int data)
{
	Node*node;
	node=new struct Node();
	node->data=data;
	node->next=NULL;
}
class List
{
	Node *start;
	public:
		List();
		void printList(); // prints the whole list
		void insert(int); // insert an element with given value at the end of the list.
		bool remove(int); // removes the element at the given index in the list. returns true if successful, otherwise returns false // 0 based indexing
		void reverse(); // revese the elements of linked list.
		struct Node*nthFromLast(int n); // this function returns the reference of the nth node from last
};
List::List()
{
	this->start=NULL;
}
void List::printList()
{
	for(Node *node=this->start;node!=NULL;node=node->next)
		cout<<node->data<<" ";
	cout<<endl<<endl;
}
void List::insert(int d)
{
	if((this->start)==NULL)
		this->start=makeNode(d);
	else 
	{
		struct Node *node,*prev;
		for(node=this->start,prev=NULL;node!=NULL;prev=node,node=node->next);
		prev->next=makeNode(d);
	}
}
bool List::remove(int index)
{
	if(index<0) return false;
	if((this->start)==NULL)
		return false;
	if(index==0) // this means we have to delete the starting of the node. special case
	{
		struct Node*node=this->start;
		this->start=this->start->next;
		delete node;
		return true;
	}
	int i=0;
	struct Node*prev=NULL;
	for(struct Node*node=this->start;node!=NULL;prev=node,i++,node=node->next)
	{
		if(i==index)
		{
			prev->next=node->next;
			delete node;
			return true;
		}
	}
	return false;
}
void List::reverse()
{
	if((this->start)==NULL || (this->start->next)==NULL) return;
	struct Node*p,*c,*n;
	p=NULL;
	c=this->start;
	n=c->next;
	while(true)
	{
		c->next=p;
		p=c;
		c=n;
		if(n==NULL)
			break;
		n=n->next;
	}
	this->start=p;
}
struct Node* List::nthFromLast(int n)
{
	struct Node*p1,*p2;
	p1=NULL;p2=this->start;
	int i=0;
	for(i=1,p2=this->start;i<=n && p2;i++,p2=p2->next);
	if(!p2) return NULL;
	p1=this->start;
	while(p2)
	{
		p2=p2->next;
		p1=p1->next;
	}
	return p1;
}
int main()
{
	List list=List();
	for(int i=0;i<20;i++)
		list.insert(i+1);
	//list.remove(8); // testing remove
	cout<<"this is the list before reversing...\n";	
	list.printList(); // testing printList
	list.reverse();
	cout<<"this is the list after reversing\n";
	list.printList();
	struct Node*node=list.nthFromLast(15);
	if(node)
		cout<<"this is the nth element from the last : "<<node->data<<endl;
	else cout<<"Node not found\n";
	return 0;
}
