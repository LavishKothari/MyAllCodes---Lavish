#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

class vertex {
	public:
	int start,end,color,id;
	vector <int> adj;
	vertex()
	{
		start=end=-1;
		color=0;
		adj=vector<int>(0);
	}

};


void dfs(vector <vertex> &v, int n, int m, int start) {
	static int cnt=1;

	v[start].color = 1;
	v[start].start = cnt;
	cnt++;
		
	for(int i=0; i<v[start].adj.size(); i++) {
		int temp = v[start].adj[i];
		if(v[temp].color == 0)
			dfs(v,n,m,temp);
	}
		
	v[start].end = cnt;
	cnt++;
}

bool cmp(const vertex&a,const vertex &b)
{
	return b.end<a.end;
}

int main () {	
	// indexing of vertices is from 0
	int n,m;
	scanf("%d",&n);

	scanf("%d",&m);

	vector <vertex> v(n, vertex());
	for(int i=0;i<n;i++)
		v[i].id=i;
	for(int i=0; i<m; i++) {
		int a, b;
		scanf("%d%d",&a,&b);
		v[a].adj.push_back(b);
	}
	
	for(int i=0;i<n;i++)
		if(v[i].color==0)
			dfs(v,n,m, i);
	/*
	for(int i=0;i<n;i++){
		cout<<i<<" : ";
		for(int j=0;j<v[i].adj.size();j++)
			cout<<v[i].adj[j]<<" ";
		cout<<" start = "<<v[i].start<<" and end = "<<v[i].end<<endl;
		cout<<endl;
	}
	*/
	sort(v.begin(),v.end(),cmp); // sorting the vertices according to the finish time.
	cout<<"graph in topological order : ";
	for(int i=0;i<n;i++)
		cout<<v[i].id<<" ";
	cout<<endl;
	
	for(int i=0;i<n;i++)
	{
		
	}
	
	return 0;
}
