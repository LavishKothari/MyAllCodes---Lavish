#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010

vector<int>parent(MAXN),size(MAXN);

int find(int n) {
	if(parent[n]==n) return n;
	else return parent[n] = find(parent[n]);
}

void merge(int a,int b) {
	int pa = find(a);
	int pb = find(b);
	if(pa!=pb) {
		if(size[pa]>size[pb]) {
			parent[pb]=pa;
			size[pa]+=size[pb];
		}
		else {
			parent[pa]=pb;
			size[pb]+=size[pa];
		}
	}
}

int main()
{

	for(int i=0;i<MAXN;i++)
		parent[i] = i, size[i] = 1;

	int q,n,a,b,num;
	cin>>n>>q;

	while(q--) {
		char ch;
		cin>>ch;
		if(ch=='M') {
			cin>>a>>b;
			merge(a-1,b-1);
		}
		else if(ch=='Q') {
			cin>>num;
			cout<<size[find(num-1)]<<endl;
		}
	}
	return 0;
}
