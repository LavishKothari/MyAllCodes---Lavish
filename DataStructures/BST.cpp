#include <bits/stdc++.h>

using namespace std;


template <typename T>
class BST
{
	class Node
	{
		public:
			T data;
			Node*left,*right;
			Node(T data)
			{
				this->data = data;
				right = left = NULL;
			}
	};

	public:
	Node *root;
	int numberOfNodes;

	BST()
	{
		numberOfNodes = 0;
		root = NULL;
	}

	void insert(T);
	static void inorder(Node*);
	static int height();
};



	template <typename T>
int BST::height(Node*root)
{
	if(!root)
		return 0;
	return 1 + max(height(root->left) , height(root->right));
}



	template <typename T>
void BST<T>::insert(T data)
{
	Node*temp=new Node(data);
	numberOfNodes++;
	if(!root)
		root=temp;
	else
	{
		Node*prev,*curr;
		prev = NULL;
		curr = root;
		while(curr)
		{
			prev = curr;
			if(curr->data < data)
				curr = curr->right;
			else curr = curr->left;
		}
		if(data > prev->data)
			prev->right = temp;
		else prev->left = temp;
	}
}

	template <typename T>
void BST<T>::inorder(Node*root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

int main()
{
	BST <int>bst;
	bst.insert(5);
	bst.insert(15);
	bst.insert(9);
	bst.insert(7);
	bst.insert(16);

	BST<int>::inorder(bst.root);
	return 0;
}
