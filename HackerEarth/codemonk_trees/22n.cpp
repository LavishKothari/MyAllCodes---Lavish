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
	static int maxInPath(Node*,int,int);
	static int findx(Node*,int);

};



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
int BST<T>::findx(Node*root,int x) {
	int m=root->data;
	while(root->data != x) {
		m = max(m, root->data);
		if(x < root->data)
			root = root->left;
		else
			root = root->right;
	}	
	return m;
}


template <typename T>
int BST<T>::maxInPath(Node*root,int x,int y) {
	if(!root)
		return -1;
	int m;
	if(x < root->data && y < root->data)
		return maxInPath(root->left, x, y);
	else if(x > root->data && y > root->data)
		return maxInPath(root->right, x, y);
	else {
		m = INT_MIN;
		m = max(m, root->data);
		int x1 = findx(root, x);
		m = max(m, x1);
		int x2 = findx(root, y);
		m = max(m, x2);
	}
	return m;		
}




int main()
{
	BST <int>bst;
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		int temp;
		cin>>temp;
		bst.insert(temp);
	}
	int x,y;
	cin>>x>>y;


	cout<<BST<int>::maxInPath(bst.root, x, y)<<endl;
	return 0;
}
