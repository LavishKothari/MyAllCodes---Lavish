#include <bits/stdc++.h>
using namespace std;

class Trie
{
	public:
		class Node
		{
			public:
				bool isPresent;
				int count;
				Node*nodes[26];

				Node()
				{
					isPresent=false;
					count=1;
					for(int i=0;i<26;i++)
						nodes[i]=NULL;
				}
		};

		Node *node;
		Trie()
		{
			node=new Node();
		}
		void insert(const string &str)
		{
			Node*temp=node;
			for(int i=0;i<str.size();i++)
			{
				if((temp->nodes)[str[i]-'a'])
					((temp->nodes[str[i]-'a'])->count)++;
				else
					temp->nodes[str[i]-'a'] = new Node();
				temp=(temp->nodes[str[i]-'a']);
			}
			temp->isPresent=true;
		}
		int find(const string &str)
		{
			Node*temp=node;
			for(int i=0;i<str.size();i++)
			{
				if(temp->nodes[str[i]-'a'] == NULL)
					return 0;
				temp = temp->nodes[str[i]-'a'];
			}
			return temp->count;
		}
};


int main()
{
	int q;
	scanf("%d",&q);
	Trie t;
	while(q--)
	{
		string type,keyword;
		cin>>type>>keyword;
		if(type == "add"){
			t.insert(keyword);
		}
		else cout<<t.find(keyword)<<endl;
	}
	return 0;
}
