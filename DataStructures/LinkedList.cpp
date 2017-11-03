#include <bits/stdc++.h>
using namespace std;

template<typename T>
class LinkedList {
	struct Node
	{
		T data;
		Node*next;

		Node(T data,Node*next):data(data),next(next)
		{
		}
	};

	Node*head;

	public:

	LinkedList() {
		head = NULL;
	}

	void append (T); 
	void print();	

};

template<typename T>
void LinkedList<T> :: append (T data) {
	if(head == NULL) {
		head = new Node(data,NULL);
		return;
	}
	Node *headcp=head;
	while(headcp->next)
		headcp = headcp->next;
	headcp->next = new Node(data,NULL);
} 

	template<typename T>
void LinkedList<T>::print()
{
	Node *headcp=head;
	while(headcp)
	{
		cout<<headcp->data<<" ";
		headcp=headcp->next;
	}
	cout<<endl;
}


int main()
{

	LinkedList <double> l;
	l.append(5.5);
	l.append(5.4);
	l.append(6.3);
	l.append(5.9);
	l.append(9.2);

	l.print();
	return 0;
}
