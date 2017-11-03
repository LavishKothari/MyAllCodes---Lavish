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
	static void inorder(Node*,vector<int>&);

};



	template <typename T>
void BST<T>::insert(vector <int>&a)
{
	Node*temp=new Node(a[0]);
	root=temp;

	map<int, Node*>m;
	m[0] = root;

	int n=a.size();
	for(int i=0; i<n; i++) {
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
void BST<T>::inorder(Node*root, vector <int> &v)
{
	if(root)
	{
		inorder(root->left,v);
		v.push_back(root->data);
		inorder(root->right,v);
	}
}


long long merge(vector<int> &a,int start, int end) {

	if(start >= end)
		return 0;
	int mid=(start+end)/2;
	int l=start,r=mid+1;
	long long count=0;
	vector <int> b;

	while(l<=mid && r<=end) {
		if(a[l] <= a[r]) {
			b.push_back(a[l]);
			l++;
		}
		else {
			b.push_back(a[r]);
			r++;
			count += mid-l+1;
		}
	}

	while(l<=mid) {
		b.push_back(a[l]);
		l++;
	}
	while(r<=end) {
		b.push_back(a[r]);
		r++;
	}  
	int k=0;
	for(int i=start; i<=end; i++) {
		a[i] = b[k++];
	}
	return count;
}



long long merge_sort(vector<int> &a,int start, int end) {
	if(start >= end)
		return 0;
	long long int count;
	int mid=(start+end)/2;
	count = merge_sort(a,start,mid);
	count += merge_sort(a,mid+1,end);
	count += merge(a,start,end);
	return count;
}

long long count_inversions(vector<int> a) {

	return merge_sort(a,0,a.size()-1);

}

int minSwaps(vector<int>&arr, int n)
{
	pair<int, int> arrPos[n];
	for (int i = 0; i < n; i++)
	{
		arrPos[i].first = arr[i];
		arrPos[i].second = i;
	}

	sort(arrPos, arrPos + n);

	vector<bool> vis(n, false);

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (vis[i] || arrPos[i].second == i)
			continue;

		int cycle_size = 0;
		int j = i;
		while (!vis[j])
		{
			vis[j] = 1;
			j = arrPos[j].second;
			cycle_size++;
		}

		ans += (cycle_size - 1);
	}

	return ans;
}
int main()
{
	BST <int>bst;
	int n;
	cin>>n;
	vector <int> arr(n);
	for(int i=0; i<n; i++) {
		int temp;
		cin>>temp;
		arr[i] = temp;
		//bst.insert(temp);
	}
	bst.insert(arr);
	vector <int> v;
	bst.inorder(bst.root,v);

	//cout<<count_inversions(v)<<endl;
	cout<<minSwaps(v,v.size())<<endl;
	return 0;
}
