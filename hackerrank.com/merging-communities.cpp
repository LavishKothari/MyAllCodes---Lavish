#include <bits/stdc++.h>
using namespace std;


// heuristics:
//	1. Union by rank
/// 2. Path compression
class DisjointSet
{
	public:
		class Node
		{
			public:
				Node*parent;
				int rank; // used for union by rank
				int associatedNodes; // maintaining the number of nodes in a group (for representative element)

				Node()
				{	
					rank = 1;
					associatedNodes = 1;
					parent = this;
				}
		};

		vector<Node*>nodes;
		DisjointSet(int n)
		{
			nodes=vector<Node*>(n);
			for(int i=0;i<n;i++)
				nodes[i]=new Node();
		}
		Node*find(Node*node) // returns the representative element of node
		{
			if(node->parent != node)
				node->parent = find(node->parent); // path compression
			return node->parent;
		}
		void merge(Node*n1,Node*n2)
		{
			Node*pn1 = find(n1);
			Node*pn2 = find(n2);
			if(pn1!=pn2)
			{
				if(pn1->rank > pn2->rank)
				{
					pn2->parent = pn1;
					pn1->associatedNodes += pn2->associatedNodes;
				}
				else 
				{
					pn1->parent = pn2;
					pn2->associatedNodes += pn1->associatedNodes;
				}
				if(pn1->rank == pn2->rank)
					pn2->rank++;
			}
		}

};

int main()
{
	int n;
	cin>>n;
	DisjointSet ds(n);

	int q;
	cin>>q;
	while(q--)
	{
		char ch;
		cin>>ch;
		if(ch=='M')
		{
			int a,b;
			cin>>a>>b;
			ds.merge(ds.nodes[a-1],ds.nodes[b-1]);
		}
		else if(ch=='Q')
		{
			int num;
			cin>>num;
			cout<<ds.find(ds.nodes[num-1])->associatedNodes<<endl;
		}
	}
	return 0;
}
