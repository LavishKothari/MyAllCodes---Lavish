#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node
{
	public:
		T data;
		int level;
		Node*left,*right;
		Node(T data)
		{
			this->data = data;
			right = left = NULL;
		}
};


template <typename T>
class BST
{

	public:
		Node<T> *root;
		int numberOfNodes;

		BST()
		{
			numberOfNodes = 0;
			root = NULL;
		}

		void insert(T);
		static void inorder(Node<T>*);
		static int maxInPath(Node<T>*,int,int);
		static void inorder(Node<int>*root, vector < Node<int>* > &);
};



	template <typename T>
void BST<T>::insert(T data)
{
	Node<T>*temp=new Node<T>(data);
	numberOfNodes++;
	if(!root)
		root=temp;
	else
	{
		Node<T>*prev,*curr;
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
int BST<T>::maxInPath(Node<T>*root,int x,int y) {
	if(!root)
		return -1;

	while(root->data != x) {
		if(x < root->data)
			root = root->left;
		else
			root = root->right;
	}	
	//cout<<"hello"<<endl;
	int m=INT_MIN;
	while(root && root->data != y) {
		m = max(m, root->data);
		cout<<"****** "<<root->data<<endl;
		if(y < root->data)
			root = root->left;
		else
			root = root->right;
		cout<<"****** "<<root->data<<endl;

	}	
	return m;


}


	template <typename T>
void BST<T>::inorder(Node<T>*root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void BFS(Node<int>*root)
{
	root->level=0;
	vector<Node<int>* >q;
	q.push_back(root);

	int level=0;
	while(!q.empty())
	{
		Node<int>*curr=q.front();
		q.erase(q.begin());
		//cout<<"#"<<curr->data<<" -> #";
		if(curr->left)
		{
			q.push_back(curr->left);
			curr->left->level=curr->level+1;
		}
		if(curr->right)
		{
			q.push_back(curr->right);
			curr->right->level=curr->level+1;
		}

	}

}


	template <typename T>
void BST<T>::inorder(Node<int>*root, vector <Node<int>*  > &v)
{
	if(root)
	{
		inorder(root->left,v);
		v.push_back(root);
		inorder(root->right,v);
	}
}

int main()
{

	int n,K;

	cin>>n>>K;
	vector<Node<int>*>nodev;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		nodev.push_back(new Node<int>(temp));
	}


	for(int i=1;i<n;i++)
	{
		int temp;
		cin>>temp;

		Node<int>*parent = nodev[temp-1];
		Node<int>*child = nodev[i];
		if(parent->left == NULL)
			parent->left = child;
		else parent->right = child;
	}
	//BST<int>::inorder(nodev[0]);

	BFS(nodev[0]); // updating level

	int answer=0;
	if(n>2)
		for(int i=0;i<n;i++)
		{
			vector<Node<int>*>v;
			BST<int>::inorder(nodev[i],v);
			/*
			   cout<<nodev[i]->data<<" -> ";
			   for(int j=0;j<v.size();j++)
			   cout<<v[j]->data<<" ";
			   cout<<endl;
			 */
			for(int j=0;j<v.size();j++)
			{
				for(int k=j+1;k<v.size();k++)
				{
					long long int a = nodev[i]->data;
					long long int b = v[j]->data;
					long long int c = v[k]->data;

					if(nodev[i]!=v[j] && nodev[i]!=v[k] && a+b+c >= K )
					{
						//cout<<nodev[i]->data<<" "<<v[j]->data<<" "<<v[k]->data<<" "<<endl;
						answer++;
					}
				}
			}
			v.erase(v.begin(),v.end());
		}
	cout<<answer<<endl;
	return 0;
}
