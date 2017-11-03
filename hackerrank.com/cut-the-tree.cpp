#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<map>
using namespace std;
int sum=0,minValue=2147483647;
class vertex
{
	public:
		int parent,value;
		bool isVisited;
		vector<int>adj_list;
		vertex(int,int,bool);
		vertex();
};
vertex::vertex(){}
vertex::vertex(int value,int parent,bool isVisited)
{
	this->value=value;
	this->parent=parent;
	this->isVisited=isVisited;
}
map<int,vertex>graph; //////////////////////////////// global graph.
int dfs(int start)
{
	int currentSum=graph[start].value;
	graph[start].isVisited=true;
	for(int i=0;i<graph[start].adj_list[i];i++)
	{
		int v=graph[start].adj_list[i];
		if(graph[v].isVisited==false)
		{
			graph[v].parent=start;
			graph[v].isVisited=true;
			currentSum+=dfs(v);
		}
	}
	int sum1=currentSum;
	int sum2=sum-sum1;
	if(minValue>abs(sum1-sum2))
		minValue=abs(sum1-sum2);
	return currentSum;
}
int main()
{
	int n;
	scanf("%d",&n);
	sum=0;
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		sum+=t;
		graph[i+1]=vertex(t,-1,false);
	}
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a].adj_list.push_back(b);
		graph[b].adj_list.push_back(a);
	}
	dfs(1);
	printf("%d\n",minValue);
	/*
	//printing the graph
	for(int i=1;i<=n;i++)
	{
	printf("%d -> ",i);
	for(int j=0;j<graph[i].adj_list.size();j++)
	printf("%d ",graph[i].adj_list[j]);
	printf("\n");
	}
	 */
	return 0;
}

