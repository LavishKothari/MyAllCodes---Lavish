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

	void insert(vector <int>&);
	void findx(Node*,int);

};


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

	template <typename T>
void BST<T>::insert(vector <int>&a)
{
	Node*temp=new Node(a[0]);
	root=temp;

	map<int, Node*>m;
	m[0] = root;

	int n=a.size();
	for(int i=0; i<=n/2; i++) {
		int l=-1,r=-1;
		Node*rootcp = m[i];
		if(2*i+1 <n)		
			l = a[2*i+1];
		if(2*i+2 <n)		
			r = a[2*i+2];	

		if(l != -1)  {
			temp = new Node(l);
			rootcp->left = temp;
			m[2*i+1] = temp;
		}	
		if(r != -1) {
			temp = new Node(r);
			rootcp->right = temp;
			m[2*i+2] = temp;
		}	
	}
}


template <typename T>
void BST<T>::findx(Node*root,int x) {
	while(root->data != x) {
		//m = max(m, root->data);
		if(x <= root->data) {
			root = root->left;
			cout<<"l";
		}
		else {
			root = root->right;
			cout<<"r";	
		}	
	}	
}

int main()
{
	BST <int>bst;

	int l,s;
	cin>>l>>s;

	int n=(1>>l)-1;
	vector<int>v(n);


	v[0] = l;

	for(int i=1; i<n; i++) {
		if((i-1)%2 == 0)
			v[i] = v[(i-1)/2];
		else 
			v[i] = v[(i-2)/2];
	}
	int sum=0;
	for(int i=0; i<n; i++)
		sum += v[i];	

	int lc=l;
	lc++;	
	while(sum < s) {

		v[0] = lc;

		for(int i=1; i<n; i++) {
			if((i-1)%2 == 0)
				v[i] = v[(i-1)/2];
			else 
				v[i] = v[(i-2)/2];
		}
		sum=0;
		for(int i=0; i<n; i++)
			sum += v[i];	
		lc++;
	}	

	bst.insert(v);
	int q;
	while(q--) {
		int type,k;
		cin>>type>>k;
		if(type == 1)
			cout<<v[k-1]<<endl;

		if(type == 0) {
			if(v[0] == k)
				cout<<"root"<<endl;
			else {
				bst.findx(bst.root, k);				
			}
		}	
	}	

	return 0;
}
