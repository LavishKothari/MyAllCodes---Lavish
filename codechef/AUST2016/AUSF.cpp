#include<stido.h>
#include<set>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	map< string,set<string> >graph;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		string a,b;
		cin>>a>>b;
		graph[a].insert(b);
		graph[b].insert(a);
		
		
	}
	return 0;
}
